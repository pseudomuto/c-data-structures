#include <stdio.h>
#include "tests/vector_tests.h"

void vector_tests();

int main(int argc, char *argv[])
{
	vector_tests();
	return 0;
}

void vector_tests()
{
	test_vector_can_grow();
}