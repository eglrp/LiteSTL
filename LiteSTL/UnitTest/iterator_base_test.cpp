#include "../Src/iterator_base.h"
#include "../Src/type_traits.h"
using namespace STLite; 
#include <iostream>
#include <list>
#include <iterator>

void iter_id_test();
void valtype_test();

int main()
{
	//iter_id_test();
	//valtype_test();
	// distance() and advance() testing remain.
	return 0;
}

void iter_id_aux(input_iterator_tag) {
	std::cout << "Input Iterator" << std::endl;
}

void iter_id_aux(output_iterator_tag) {
	std::cout << "Output Iterator" << std::endl;
}

void iter_id_aux(std::output_iterator_tag) {
	std::cout << "std::Output Iterator" << std::endl;
}

void iter_id_aux(forward_iterator_tag) {
	std::cout << "Forward Iterator" << std::endl;
	std::cout << "Input Iterator" << std::endl;
}

void iter_id_aux(bidirectional_iterator_tag) {
	std::cout << "Bidirectional Iterator" << std::endl;
	std::cout << "Forward Iterator" << std::endl;
	std::cout << "Input Iterator" << std::endl;
}

void iter_id_aux(std::bidirectional_iterator_tag) {
	std::cout << "std::Bidirectional Iterator" << std::endl;
	std::cout << "std::Forward Iterator" << std::endl;
	std::cout << "std::Input Iterator" << std::endl;
}

void iter_id_aux(random_access_iterator_tag) {
	std::cout << "Random Access Iterator" << std::endl;
	std::cout << "Bidirectional Iterator" << std::endl;
	std::cout << "Forward Iterator" << std::endl;
	std::cout << "Input Iterator" << std::endl;
}

void iter_id_test() {
	/*std::cout << "native pointer: " << std::endl;
	char* ptr;
	iter_id_aux(iterator_category(ptr));

	std::cout << "std::list<char*>::iterator: " << std::endl;
	std::list<char*>::iterator it;
	iter_id_aux(iterator_category(it));*/
	
	std::cout << "std::ostream_iterator<double>(..., ...): " << std::endl;
	iter_id_aux(iterator_category(std::ostream_iterator<double>(std::cout, " ")));
}

void valtype_aux(true_type) {
	std::cout << "POD type" << std::endl;
}

void valtype_aux(false_type) {
	std::cout << "non-POD type" << std::endl;
}

template <typename T> void valtype_dispatch(T*) {
	typedef typename type_traits<T>::is_POD_type is_POD_type;
	valtype_aux(is_POD_type());
}

void valtype_test() {
	char* ptr;
	valtype_dispatch(value_type(ptr));

	std::list<int>::iterator it;
	valtype_dispatch(value_type(it));

	std::list<std::list<int> >::iterator it_;
	valtype_dispatch(value_type(it_));
}