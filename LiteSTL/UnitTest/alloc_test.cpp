#include "..\Src\allocator.h"
using namespace STLite;
#include <stdio.h>
#include <cstdlib>
#include <string.h>

int main(void)
{
	size_t old_sz = 200 * sizeof(char);
	size_t new_sz = 129 * sizeof(char);

	char* str = (char*)alloc::allocate(old_sz);
	memset(str, 65, old_sz - 1);
	str[old_sz - 1] = '\0';
	printf("%s\n", str);

	str = (char*)alloc::reallocate((void*)str, old_sz, new_sz);
	memset(str, 85, new_sz - 1);
	str[new_sz - 1] = '\0';
	printf("%s\n", str);

	alloc::deallocate((void*)str, new_sz);
	printf("%s\n", str);

	return 0;
}