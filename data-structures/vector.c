#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../headers/vector.h"

static void vector_grow(vector *vector)
{
	vector->allocatedLength *= 2;
	vector->elements = realloc(vector->elements, vector->elementSize * vector->allocatedLength);
	assert(vector->elements != NULL);
}

static void *vector_address(vector *vector, int index)
{
	int addr = vector->elementSize * index;
	return (char *)vector->elements + addr;
}

void vector_new(vector *vector, int elementSize)
{
	assert(elementSize > 0);
	vector->elementSize = elementSize;
	vector->logicalLength = 0;
	vector->allocatedLength = 2;
	vector->elements = NULL;
	vector_grow(vector);
}

void vector_destroy(vector *vector)
{
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