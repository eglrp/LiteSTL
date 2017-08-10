#include "../Src/construct.h"
using namespace STLite;
#include <iostream>
#include <string.h>
#include <list>
#include <algorithm>

struct S {
	S() { bytes = new char[8]; }
	~S() { delete[] bytes; }
private:
	char* bytes;
};

void single_test();
void range_test();

int main() {
	//single_test();
	range_test();
	return 0;
}

void single_test() {
	char* buf = new char;
	char val = 'W';

	construct(buf, val);
	std::cout << "*buf = " << *buf << std::endl;
	destroy(buf);

	construct(buf);
	std::cout << "*buf = " << *buf << std::endl;
	destroy(buf);

	delete[] buf;

	int* pi = new int;
	int n = 9;

	construct(pi);
	std::cout << "*pi = " << *pi << std::endl;
	destroy(pi);

	construct(pi, n);
	std::cout << "*pi = " << *pi << std::endl;
	destroy(pi);

	delete[] pi;
}

void range_test() {
	char* str = new char[5];
	memset(str, 'W', 4);
	*(str + 4) = '\0';
	std::cout << str << std::endl;
	destroy(str, str + 5);
	delete[] str;

	int arr[6] = { 1, 2, 3, 4, 5, 6 };
	std::list<int> mylist(arr, arr + 6);
	std::for_each(mylist.begin(), mylist.end(), 
		[](int& x) {std::cout << x << ' '; });
	destroy(mylist.begin(), mylist.end());

	std::list<S> mylist_;
	mylist_.assign(10, S());
	destroy(mylist_.begin(), mylist_.end());
}