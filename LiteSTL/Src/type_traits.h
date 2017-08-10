#pragma once

namespace STLite {
	struct true_type {};
	struct false_type {};

	template < class T> struct type_traits {
		typedef false_type has_trivial_default_constructor;
		typedef false_type has_trivial_copy_constructor;
		typedef false_type has_trivial_assignment_operator;
		typedef false_type has_trivial_destructor;
		typedef false_type is_POD_type;
	};

	template <> struct type_traits <bool> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <char> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <signed char> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned char> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <wchar_t> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <short> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned short> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <int> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned int> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <long> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned long> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <long long> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned long long> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <float> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <double> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <long double> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <class T> struct type_traits <T*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <char*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <signed char*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <unsigned char*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <const signed char*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};

	template <> struct type_traits <const unsigned char*> {
		typedef true_type has_trivial_default_constructor;
		typedef true_type has_trivial_copy_constructor;
		typedef true_type has_trivial_assignment_operator;
		typedef true_type has_trivial_destructor;
		typedef true_type is_POD_type;
	};


	template <typename T> struct is_integer {
		typedef false_type Integral;
	};

	template <> struct is_integer <bool> {
		typedef true_type Integral;
	};

	template <> struct is_integer <char> {
		typedef true_type Integral;
	};

	template <> struct is_integer <signed char> {
		typedef true_type Integral;
	};

	template <> struct is_integer <unsigned char> {
		typedef true_type Integral;
	};

	template <> struct is_integer <wchar_t> {
		typedef true_type Integral;
	};

	template <> struct is_integer <short> {
		typedef true_type Integral;
	};

	template <> struct is_integer <unsigned short> {
		typedef true_type Integral;
	};

	template <> struct is_integer <int> {
		typedef true_type Integral;
	};

	template <> struct is_integer <unsigned int> {
		typedef true_type Integral;
	};

	template <> struct is_integer <long> {
		typedef true_type Integral;
	};

	template <> struct is_integer <unsigned long> {
		typedef true_type Integral;
	};

	template <> struct is_integer <long long> {
		typedef true_type Integral;
	};

	template <> struct is_integer <unsigned long long> {
		typedef true_type Integral;
	};

}