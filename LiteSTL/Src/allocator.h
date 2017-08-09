#pragma once

#include <stdlib.h>
#include <string.h>
#include <new>
#include <stddef.h>

namespace LiteSTL {
	class alloc {
	private:
		static const int ALIGN = 8;
		static const int MAX_BYTES = 128;
		static const int LIST_NUM = 16;
		struct node { struct node* next; };
		static node* free_list[LIST_NUM];

		typedef char byte;
		struct pool {
			static byte* start;
			static byte* end;
			static size_t size;
		};

	public:
		static void* allocate(const size_t new_sz);
		static void deallocate(void* ptr, const size_t old_sz);
		static void* reallocate(void* ptr, const size_t old_sz, const size_t new_sz);

	private:
		static size_t round_up(size_t bytes) {
			return ((bytes + ALIGN - 1) & ~(ALIGN - 1));
		}
		static size_t index(size_t bytes) {
			return ((bytes + ALIGN - 1) / ALIGN - 1);
		}
		static void* refill(size_t bytes);
		static byte* chunk_alloc(size_t bytes, int& objs);
	};

	alloc::node* alloc::free_list[alloc::LIST_NUM] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};
	alloc::byte* alloc::pool::start = 0;
	alloc::byte* alloc::pool::end = 0;
	size_t alloc::pool::size = 0;

	void* alloc::allocate(const size_t new_sz) {
		if (new_sz > MAX_BYTES)
			return malloc(new_sz);

		node** self_list = free_list + index(new_sz);
		node* result = *self_list;

		if (0 == result)
			return refill(round_up(new_sz));

		*self_list = result->next;
		return result;
	}

	void alloc::deallocate(void* ptr, const size_t old_sz) {
		if (old_sz > MAX_BYTES) 
			return free(ptr);
		
		node* q = (node*)ptr;
		node** self_list = free_list + index(old_sz);

		q->next = *self_list;
		*self_list = q;
	}

	void* alloc::reallocate(void* ptr, const size_t old_sz, const size_t new_sz) {
		if (old_sz > MAX_BYTES && new_sz > MAX_BYTES)
			return realloc(ptr, new_sz);

		if (round_up(old_sz) == round_up(new_sz))
			return ptr;

		void* result = allocate(new_sz);
		size_t copy_sz = old_sz < new_sz ? old_sz : new_sz;

		memcpy(result, ptr, copy_sz);
		deallocate(ptr, old_sz);

		return result;
	}

	void* alloc::refill(size_t bytes) {
		int objs = 20;
		byte* chunk = chunk_alloc(bytes, objs);

		if (1 == objs)
			return chunk;

		node* result = (node*)chunk;
		node** self_list = free_list + index(bytes);
		node* next_node = (node*)(chunk + bytes);
		node* curr_node = 0;

		*self_list = next_node;

		for (int i = 1; ; ++i) {
			curr_node = next_node;

			if (objs > i + 1) {
				next_node = (node*)((byte*)next_node + bytes);
				curr_node->next = next_node;
			}
			else { // the end of chunk
				curr_node->next = 0;
				break;
			}
		}

		return result;
	}

	alloc::byte* alloc::chunk_alloc(size_t bytes, int& objs) {
		byte* result = 0;
		size_t bytes_need = bytes * objs;
		size_t bytes_left = pool::end - pool::start;

		if (bytes_left >= bytes_need) {
			result = pool::start;
			pool::start += bytes_need;

			return result;
		}

		if (bytes_left >= bytes) {
			objs = bytes_left / bytes;
			result = pool::start;
			pool::start += objs * bytes;

			return result;
		}

		if (bytes_left > 0) {
			node** self_list = free_list + index(bytes_left);

			((node*)(pool::start))->next = *self_list;
			*self_list = (node*)(pool::start);
		}

		size_t bytes_to_get = (bytes_need << 1) + round_up(pool::size >> 4);

		pool::start = (byte*)malloc(bytes_to_get);

		if (0 == pool::start) {
			node** self_list = 0;
			node* p = 0;

			for (int b = bytes; b <= MAX_BYTES; b += ALIGN) {
				self_list = free_list + index(b);
				p = *self_list;

				if (p != 0) {
					*self_list = p->next;
					pool::start = (byte*)p;
					pool::end = pool::start + b;

					return chunk_alloc(bytes, objs);
				}
			}

			pool::end = 0;

			while (0 == (pool::start = (byte*)malloc(bytes_to_get)));
		}

		pool::size += bytes_to_get;
		pool::end = pool::start + bytes_to_get;

		return chunk_alloc(bytes, objs);
	}

	template <typename T>
	struct allocator {
		typedef T          value_type;
		typedef size_t     size_type;
		typedef ptrdiff_t  difference_type;
		typedef T*         pointer;
		typedef const T*   const_pointer;
		typedef T&         reference;
		typedef const T&   const_reference;

		template <typename U> struct rebind {
			typedef allocator<U> other;
		};

		allocator() noexcept {}
		allocator(const allocator&) noexcept {}
		template <typename U> allocator(const allocator<U>&) noexcept {}
		~allocator() {}

		pointer address(reference x) const { return &x; }
		const_pointer address(const_reference x) const { return &x; }

		pointer allocate(size_type n) {
			return n != 0 ? static_cast<T*>(alloc::allocate(n * sizeof(T))) : 0;
		}
		void deallocate(pointer ptr, size_type n) {
			alloc::deallocate(ptr, n * sizeof(T));
		}

		size_type max_size() const noexcept {
			return size_t(-1) / sizeof(T);
		}

		void construct(pointer ptr, const T& x) { new(ptr) T(x); }
		void destroy(pointer ptr) { ptr->~T(); }
	};

	template<>
	struct allocator<void> {
	public:
		typedef void        value_type;
		typedef size_t      size_type;
		typedef ptrdiff_t   difference_type;
		typedef void*       pointer;
		typedef const void* const_pointer;
		
		template <typename U> struct rebind {
			typedef allocator<U> other;
		};
	};

	template <typename T1, typename T2>
	inline bool operator==(const allocator<T1>&, const allocator<T2>&) {
		return true;
	}
	template <typename T1, typename T2>
	inline bool operator!=(const allocator<T1>&, const allocator<T2>&) {
		return false;
	}

}