#include <stdio.h>
#include <assert.h>
#include "../headers/vector.h"

void test_vector_can_grow()
{
	const int vector_initial_size = 4;

	vector v;
	vector_new(&v, sizeof(int));

	int i;
	for(i = 0; i < vector_initial_size + 2; i++) {
		vector_add(&v, &i);
	}

	int value;
	vector_item_at(&v, vector_initial_size, &value);
	assert(value == vector_initial_size);
}