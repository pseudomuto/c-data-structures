#include <stdio.h>
#include "tests/vector_tests.h"

void vector_tests();

int main(int argc, char *argv[])
{
	vector_tests();

	printf("All tests passed.\n");
	return 0;
}

void vector_tests()
{
	test_vector_can_get_item_at_index();
	test_vector_can_grow();
	test_vector_can_store_strings();
	test_vector_can_insert_values();
	test_vector_can_remove_values();
}