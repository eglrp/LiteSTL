#include "../Src/type_traits.h"
using namespace STLite;
#include <iostream>
#include <vector>

struct S {};

template <typename T> struct I {
	T& operator*() const {}
	T* operator->() const {}
	I& operator++() const {}
	I operator++(int) const {}
	bool operator==(const I& x) const {}
	bool operator!=(const I& x) const {}
};

inline bool is_POD_type(true_type) { return true; }
inline bool is_POD_type(false_type) { return false; }
inline bool is_itegral_type(true_type) { return true; }
inline bool is_itegral_type(false_type) { return false; }

void built_in_types_test();
void native_pointers_type_test();
void unique_type_test();
void integral_types_test();
void non_integral_test();

int main()
{
	//built_in_types_test();
	//native_pointers_type_test();
	//unique_type_test();
	//integral_types_test();
	non_integral_test();
	return 0;
}

void built_in_types_test() {
	std::cout << std::boolalpha;

	std::cout << "bool: ";
	std::cout << is_POD_type(type_traits<bool>::is_POD_type()) << std::endl;

	std::cout << "char: ";
	std::cout << is_POD_type(type_traits<char>::is_POD_type()) << std::endl;

	std::cout << "signed char: ";
	std::cout << is_POD_type(type_traits<signed char>::is_POD_type()) << std::endl;

	std::cout << "unsigned char: ";
	std::cout << is_POD_type(type_traits<unsigned char>::is_POD_type()) << std::endl;

	std::cout << "wchar_t: ";
	std::cout << is_POD_type(type_traits<wchar_t>::is_POD_type()) << std::endl;

	std::cout << "short: ";
	std::cout << is_POD_type(type_traits<short>::is_POD_type()) << std::endl;

	std::cout << "unsigned short: ";
	std::cout << is_POD_type(type_traits<unsigned short>::is_POD_type()) << std::endl;

	std::cout << "int: ";
	std::cout << is_POD_type(type_traits<int>::is_POD_type()) << std::endl;

	std::cout << "unsigned int: ";
	std::cout << is_POD_type(type_traits<unsigned int>::is_POD_type()) << std::endl;

	std::cout << "long: ";
	std::cout << is_POD_type(type_traits<long>::is_POD_type()) << std::endl;

	std::cout << "unsigned long: ";
	std::cout << is_POD_type(type_traits<unsigned long>::is_POD_type()) << std::endl;

	std::cout << "long long: ";
	std::cout << is_POD_type(type_traits<long long>::is_POD_type()) << std::endl;

	std::cout << "unsinged long long: ";
	std::cout << is_POD_type(type_traits<unsigned long long>::is_POD_type()) << std::endl;

	std::cout << "float: ";
	std::cout << is_POD_type(type_traits<float>::is_POD_type()) << std::endl;

	std::cout << "double: ";
	std::cout << is_POD_type(type_traits<double>::is_POD_type()) << std::endl;

	std::cout << "long double: ";
	std::cout << is_POD_type(type_traits<long double>::is_POD_type()) << std::endl;
}

void native_pointers_type_test() {
	std::cout << std::boolalpha;

	std::cout << "bool*: ";
	std::cout << is_POD_type(type_traits<bool*>::is_POD_type()) << std::endl;

	std::cout << "char*: ";
	std::cout << is_POD_type(type_traits<char*>::is_POD_type()) << std::endl;

	std::cout << "signed char*: ";
	std::cout << is_POD_type(type_traits<signed char*>::is_POD_type()) << std::endl;

	std::cout << "unsigned char*: ";
	std::cout << is_POD_type(type_traits<unsigned char*>::is_POD_type()) << std::endl;

	std::cout << "wchar_t*: ";
	std::cout << is_POD_type(type_traits<wchar_t*>::is_POD_type()) << std::endl;

	std::cout << "short*: ";
	std::cout << is_POD_type(type_traits<short*>::is_POD_type()) << std::endl;

	std::cout << "unsigned short*: ";
	std::cout << is_POD_type(type_traits<unsigned short*>::is_POD_type()) << std::endl;

	std::cout << "int*: ";
	std::cout << is_POD_type(type_traits<int*>::is_POD_type()) << std::endl;

	std::cout << "unsigned int*: ";
	std::cout << is_POD_type(type_traits<unsigned int*>::is_POD_type()) << std::endl;

	std::cout << "long*: ";
	std::cout << is_POD_type(type_traits<long*>::is_POD_type()) << std::endl;

	std::cout << "unsigned long*: ";
	std::cout << is_POD_type(type_traits<unsigned long*>::is_POD_type()) << std::endl;

	std::cout << "long long*: ";
	std::cout << is_POD_type(type_traits<long long*>::is_POD_type()) << std::endl;

	std::cout << "unsinged long long*: ";
	std::cout << is_POD_type(type_traits<unsigned long long*>::is_POD_type()) << std::endl;

	std::cout << "float*: ";
	std::cout << is_POD_type(type_traits<float*>::is_POD_type()) << std::endl;

	std::cout << "double*: ";
	std::cout << is_POD_type(type_traits<double*>::is_POD_type()) << std::endl;

	std::cout << "long double*: ";
	std::cout << is_POD_type(type_traits<long double*>::is_POD_type()) << std::endl;
}

void unique_type_test() {
	std::cout << std::boolalpha;

	std::cout << "struct S {}; : ";
	std::cout << is_POD_type(type_traits<S>::is_POD_type()) << std::endl;

	std::cout << "S*: ";
	std::cout << is_POD_type(type_traits<S*>::is_POD_type()) << std::endl;

	std::cout << "std::vector<int>: ";
	std::cout << is_POD_type(type_traits<std::vector<int> >::is_POD_type()) << std::endl;

	std::cout << "std::vector<int>*: ";
	std::cout << is_POD_type(type_traits<std::vector<int>*>::is_POD_type()) << std::endl;

	std::cout << "I<int>: ";
	std::cout << is_POD_type(type_traits<I<int> >::is_POD_type()) << std::endl;

	std::cout << "I<int>*: ";
	std::cout << is_POD_type(type_traits<I<int>*>::is_POD_type()) << std::endl;
}

void integral_types_test() {
	std::cout << std::boolalpha;

	std::cout << "bool: ";
	std::cout << is_itegral_type(is_integer<bool>::Integral()) << std::endl;

	std::cout << "char: ";
	std::cout << is_itegral_type(is_integer<char>::Integral()) << std::endl;

	std::cout << "signed char: ";
	std::cout << is_itegral_type(is_integer<signed char>::Integral()) << std::endl;

	std::cout << "unsigned char: ";
	std::cout << is_itegral_type(is_integer<unsigned char>::Integral()) << std::endl;

	std::cout << "wchar_t: ";
	std::cout << is_itegral_type(is_integer<wchar_t>::Integral()) << std::endl;

	std::cout << "short: ";
	std::cout << is_itegral_type(is_integer<short>::Integral()) << std::endl;

	std::cout << "unsigned short: ";
	std::cout << is_itegral_type(is_integer<unsigned short>::Integral()) << std::endl;

	std::cout << "int: ";
	std::cout << is_itegral_type(is_integer<int>::Integral()) << std::endl;

	std::cout << "unsigned int: ";
	std::cout << is_itegral_type(is_integer<unsigned int>::Integral()) << std::endl;

	std::cout << "long: ";
	std::cout << is_itegral_type(is_integer<long>::Integral()) << std::endl;

	std::cout << "unsigned long: ";
	std::cout << is_itegral_type(is_integer<unsigned long>::Integral()) << std::endl;

	std::cout << "long long: ";
	std::cout << is_itegral_type(is_integer<long long>::Integral()) << std::endl;

	std::cout << "unsigned long long: ";
	std::cout << is_itegral_type(is_integer<unsigned long long>::Integral()) << std::endl;
}

void non_integral_test() {
	std::cout << std::boolalpha;

	std::cout << "double: ";
	std::cout << is_itegral_type(is_integer<double>::Integral()) << std::endl;

	std::cout << "struct S {}: ";
	std::cout << is_itegral_type(is_integer<S>::Integral()) << std::endl;

	std::cout << "I<int> ";
	std::cout << is_itegral_type(is_integer<I<int>>::Integral()) << std::endl;

	std::cout << "char*: ";
	std::cout << is_itegral_type(is_integer<char*>::Integral()) << std::endl;
}