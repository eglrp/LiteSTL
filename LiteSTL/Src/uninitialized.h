#pragma once

#include "construct.h"
#include "algobase.h"
#include <string.h>

namespace STLite {
	template <class InputIterator, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy_aux(InputIterator first, InputIterator last,
												 ForwardIterator result, true_type) {
		return copy(first, last, result);
	}

	template <class InputIterator, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy_aux(InputIterator first, InputIterator last,
												 ForwardIterator result, false_type) {
		ForwardIterator cur = result;

		for (; first != last; ++first, ++cur)
			construct(&*cur, *first);

		return cur;
	}

	template <class InputIterator, class ForwardIterator, typename T>
	inline ForwardIterator
	uninitialized_copy_dispatch(InputIterator first, InputIterator last,
															ForwardIterator result, T*) {
		typedef typename type_traits<T>::is_POD_type is_POD_type;
		return uninitialized_copy_aux(first, last, result, is_POD_type());
	}

	template <class InputIterator, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy(InputIterator first, InputIterator last,
										 ForwardIterator result) {
		return uninitialized_copy_dispatch(first, last, result, value_type(result));
	}

	inline char* uninitialized_copy(const char* first, const char* last, 
																	char* result) {
		memmove(result, first, last - first);
		return result + (last - first);
	}

	inline wchar_t* uninitialized_copy(const wchar_t* first, const wchar_t* last,
																		 wchar_t* result) {
		memmove(result, first, sizeof(wchar_t) * (last - first));
		return result + (last - first);
	}

	template <class InputIterator, typename Size, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy_n_aux(InputIterator first, Size count, 
													 ForwardIterator result, input_iterator_tag) {
		ForwardIterator cur = result;

		for (; count > 0; --count, ++first, ++cur)
			construct(&*cur, *first);
		return cur;
	}

	template <class RandomAccessIterator, typename Size, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy_n_aux(RandomAccessIterator first, Size count,
													 ForwardIterator result, random_access_iterator_tag) {
		RandomAccessIterator last = first + count;

		return uninitialized_copy(first, last, result);
	}

	template <class InputIterator, typename Size, class ForwardIterator>
	inline ForwardIterator
	uninitialized_copy_n(InputIterator first, Size count,
																ForwardIterator result) {
		return uninitialized_copy_n_aux(first, count, result,
																		iterator_category(first));
	}

	template <class ForwardIterator, typename T>
	inline void
	uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
												 const T& x, true_type) {
		fill(first, last, x);
	}

	template <class ForwardIterator, typename T>
	inline void
	uninitialized_fill_aux(ForwardIterator first, ForwardIterator last,
												 const T& x, false_type) {
		ForwardIterator cur = first;

		for (; cur != last; ++cur)
			construct(&*cur, x);
	}

	template <class ForwardIterator, typename T, typename U>
	inline void
	uninitialized_fill_dispatch(ForwardIterator first, ForwardIterator last,
										 const T& x, U*) {
		typedef typename type_traits<U>::is_POD_type is_POD_type;
		uninitialized_fill_aux(first, last, x, is_POD_type());
	}

	template <class ForwardIterator, typename T>
	inline void
	uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& x) {
		uninitialized_fill_dispatch(first, last, x, value_type(first));
	}

	template <class ForwardIterator, typename Size, typename T>
	inline ForwardIterator
	uninitialized_fill_n_aux(ForwardIterator first, Size count,
													 const T& x, true_type) {
		return fill_n(first, count, x);
	}

	template <class ForwardIterator, typename Size, typename T>
	inline ForwardIterator
	uninitialized_fill_n_aux(ForwardIterator first, Size count,
													 const T& x, false_type) {
		ForwardIterator cur = first;

		for (; count > 0; --count, ++cur)
			construct(&*cur, x);
		return cur;
	}

	template <class ForwardIterator, typename Size, typename T, typename U>
	inline ForwardIterator
	uninitialized_fill_n_dispatch(ForwardIterator first, Size count,
																const T& x, U*) {
		typedef typename type_traits<U>::is_POD_type is_POD_type;
		return uninitialized_fill_n_aux(first, count, x, is_POD_type());
	}

	template <class ForwardIterator, typename Size, typename T>
	inline ForwardIterator
	uninitialized_fill_n(ForwardIterator first, Size count, T& x) {
		return uninitialized_fill_n_dispatch(first, count, x, value_type(first));
	}

}