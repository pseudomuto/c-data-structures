#include <stdio.h>
#include "tests/tests.h"

int main(int argc, char *argv[])
{
	test_vector_operations();
	test_list_operations();
	test_stack_operations();
	test_queue_operations();
	
	printf("All tests passed.\n");
	
	return 0;
}