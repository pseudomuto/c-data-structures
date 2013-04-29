#include <stdio.h>
#include "tests/vector_tests.h"
#include "tests/stack_tests.h"

int main(int argc, char *argv[])
{
	test_vector_operations();
	test_stack_operations();

	printf("All tests passed.\n");
	return 0;
}