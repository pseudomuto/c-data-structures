#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../headers/vector.h"

static void vector_grow(vector *vector)
{
	vector->allocatedLength *= 2;
	vector->elements = realloc(vector->elements, vector->elementSize * vector->allocatedLength);
	assert(vector->elements);
}

static void *vector_address(vector *vector, int index)
{
	int addr = vector->elementSize * index;
	return (char *)vector->elements + addr;
}

void vector_new(vector *vector, int elementSize, void (*freeFn)(void *))
{
	assert(elementSize > 0);
	vector->elementSize = elementSize;
	vector->logicalLength = 0;
	vector->allocatedLength = 2;
	vector->elements = NULL;
	vector->freeFn = freeFn;
	vector_grow(vector);
}

void vector_destroy(vector *vector)
{
	if(vector->freeFn) {
		int i;
		for(i = 0; i < vector_size(vector); i++) {
			vector->freeFn(vector_address(vector, i));
		}
	}

	// free main elements
	free(vector->elements);
}

int vector_size(vector *vector)
{
	return vector->logicalLength;
}

void vector_add(vector *vector, void *element)
{
	if (vector->allocatedLength == vector->logicalLength) {
		vector_grow(vector);
	}

	void *target = vector_address(vector, vector->logicalLength++);
	memcpy(target, element, vector->elementSize);
}

void vector_item_at(vector *vector, int index, void *target)
{
	assert(index >= 0 && index < vector->logicalLength);

	void *source = vector_address(vector, index);
	memcpy(target, source, vector->elementSize);
}

void vector_insert_at(vector *vector, int index, void *target)
{
	assert(index >= 0 && index <= vector->logicalLength);
	vector_add(vector, target);

	if(index < vector->logicalLength) {	
		int i;
		void *source;
		void *destination;

		for(i = vector->logicalLength - 2; i > index; i--) {
			source = vector_address(vector, i);
			destination = vector_address(vector, i + 1);
			memcpy(destination, source, vector->elementSize);
		}

		destination = vector_address(vector, i);
		memcpy(destination, target, vector->elementSize);
	}
}

void vector_remove_at(vector *vector, int index)
{
	assert(index >= 0 && index < vector->logicalLength);
	void *item = vector_address(vector, index);
	if(vector->freeFn) {
		vector->freeFn(item);
	}

	if(index < vector->logicalLength - 1) {
		int i;
		void *source;
		void *destination;

		for(i = index; i < vector->logicalLength; i++) {
			source = vector_address(vector, i + 1);
			destination = vector_address(vector, i);
			memcpy(destination, source, vector->elementSize);
		}
	}

	vector->logicalLength--;
}