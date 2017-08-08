#include "../Src/alloc.h"
using namespace LiteSTL;
#include <iostream>
#include <vector>
#include <ctime>

void test1();
void test2();
void test3();
void test4();

int main()
{
	test3();
	//test4();

	return 0;
}

void test1() {
	allocator<int> int_alloc;
	int* pi = int_alloc.allocate(1);
	int_alloc.construct(pi, 7);
	std::cout << pi[0] << std::endl;
	int_alloc.deallocate(pi, 1);
}

void test2() {
	allocator<std::string> str_alloc;
	std::string* strs = str_alloc.allocate(2);
	str_alloc.construct(strs, "foo");
	str_alloc.construct(strs + 1, "bar");
	std::cout << strs[0] << ' ' << strs[1] << std::endl;
	str_alloc.destroy(strs);
	str_alloc.destroy(strs + 1);
	str_alloc.deallocate(strs, 2);
}

void test3() {
	long long quantities[] = { 
		1000, 10000, 100000, 1000000, 10000000, 100000000 
	};
	std::vector<int, allocator<int>> vec;

	for (int i = 0; i < 6; ++i) {
		clock_t start = clock();

		for (long long j = 0; j < quantities[i]; ++j)
			vec.push_back(j);

		clock_t end = clock();
		std::cout << "quanlity = " << quantities[i] << ", ";
		std::cout << "time = " << (float)(end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl;

		vec.clear();
	}
}

void test4() {
	long long quantities[] = {
		1000, 10000, 100000, 1000000, 10000000, 100000000
	};
	std::vector<int> vec;

	for (int i = 0; i < 6; ++i) {
		clock_t start = clock();

		for (long long j = 0; j < quantities[i]; ++j)
			vec.push_back(j);

		clock_t end = clock();
		std::cout << "quanlity = " << quantities[i] << ", ";
		std::cout << "time = " << (float)(end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl;

		vec.clear();
	}
}

