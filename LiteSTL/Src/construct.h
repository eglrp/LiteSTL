#pragma once

#include "type_traits.h"
#include "iterator_base.h"
#include <new>

namespace LiteSTL {
	template <typename T1, typename T2>
	inline void construct(T1* ptr, T2& val) {
		new((void*)ptr) T1(val);
	}

	template <typename T>
	inline void construct(T* ptr) {
		new((void*)ptr) T();
	}

	template <typename T>
	inline void destroy(T* ptr) {
		ptr->~T();
	}

	template <class ForwardIterator> 
	inline void 
		destroy_aux(ForwardIterator first, ForwardIterator last, false_type) {
		for (; first != last; ++first)
			destroy(&*first);
	}
	template <class ForwardIterator> 
	inline void 
		destroy_aux(ForwardIterator first, ForwardIterator last, true_type) { }

	template <class ForwardIterator, class T>
	inline void
		destroy_dispatch(ForwardIterator first, ForwardIterator last, T*) {
		typedef typename type_traits<T>::has_trivial_destructor trivial_destructor;
		destroy_aux(first, last, trivial_destructor);
	}

	template <class ForwardIterator>
	inline void destroy(ForwordIterator first, ForwardIterator last) {
		destroy_dispatch(first, last, value_type(first));
	}

	inline void destroy(char*, char*) {}
	inline void destroy(wchar_t*, wchar_t*) {}
	inline void destroy(int*, int*) {}
	inline void destroy(long*, long*) {}
	inline void destroy(float*, float*) {}
	inline void destroy(double*, double*) {}

}
