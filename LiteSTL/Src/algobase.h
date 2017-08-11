#pragma once

#include "type_traits.h"
#include <string.h>

namespace STLite {
	template <class InputIterator, class OutputIterator, typename Distance>
	inline OutputIterator
	copy_aux3(InputIterator first, InputIterator last, OutputIterator result,
						input_iterator_tag, Distance*)
	{
		for (; first != last; ++result, ++first)
			*result = *first;
		return result;
	}

	template <class RandomAccessIterator, class OutputIterator, typename Distance>
	inline OutputIterator
	copy_aux3(RandomAccessIterator first, RandomAccessIterator last,
					  OutputIterator result, random_access_iterator_tag, Distance*)
	{
		for (Distance n = last - first; n > 0; --n) {
			*result = *first;
			++first;
			++result;
		}
		return result;
	}

	template <class T>
	inline T copy_trivial(const T* first, const T* last, T* result) {
		memmove(result, first, sizeof(T) * (last - first));
		return result + (last - first);
	}

	template <class InputIterator, class OutputIterator>
	inline OutputIterator copy_aux2(InputputIterator first, InputIterator last,
																	OutputIterator, false_type)
	{
		return copy_aux3(first, last, result,
			               iterator_category(first), distance_type(first));
	}

	template <class InputIterator, class OutputIterator>
	inline OutputIterator copy_aux2(InputputIterator first, InputIterator last,
																	OutputIterator, true_type) 
	{
		return copy_aux3(first, last, result,
										 iterator_category(first), distance_type(first));
	}

	template <typename T>
	inline T* copy_aux2(T* first, T* last, T* result, true_type) {
		return copy_trivial(first, last, result);
	}

	template <typename T>
	inline T* copy_aux2(const T* first, const T* last, T* result, true_type) {
		return copy_trivial(first, last, result);
	}

	template <class InputIterator, class OutputIterator, typename T>
	inline OutputIterator copy_aux(InputIterator first, InputIterator last,
																 OutputIterator result, T*)
	{
		typedef typename type_traits<T>::has_trivial_assignment_operator trivial;
		return copy_aux2(first, last, result, trivial());
	}

	template <class InputIterator, class OutputIterator>
	inline OutputIterator copy(InputIterator first, InputIterator last,
														 OutputIterator result)
	{
		return copy_aux(first, last, result, value_type(first));
	}

	template <class ForwardIterator, typename T>
	void fill(ForwardIterator first, ForwardIterator last, const T& value) {
		for (; first != last; ++first)
			*first = value;
	}

	inline void fill(char* first, char* last, const char& value) {
		char tmp = value;
		memset(first, static_cast<unsigned char>(tmp), last - first);
	}

	inline void fill(signed char* first, signed char* last, 
									 const signed char& value)
	{
		signed char tmp = value;
		memset(first, static_cast<unsigned char>(tmp), last - first);
	}

	inline void fill(unsigned char* first, unsigned char* last,
									 const unsigned char& value)
	{
		unsigned char tmp = value;
		memset(first, tmp, last - first);
	}

	template <class OutputIterator, typename Size, typename T>
	OutputIterator fill_n(OutputIterator first, Size count, const T& value) {
		for (; count > 0; --count, ++first)
			*first = value;
		return first;
	}

	template <class Size>
	inline char* fill_n(char* first, Size count, const char& value) {
		fill(first, first + count, value);
		return first + count;
	}

	template <typename Size>
	inline signed char* fill_n(signed char* first, Size count,
														 const signed char& value) 
	{
		fill(first, first + count, value);
		return first + count;
	}

	template <typename Size>
	inline unsigned char* fill_n(unsigned char* first, Size count,
															 const unsigned char& value)
	{
		fill(first, first + count, value);
		return first + count;
	}

}