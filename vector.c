#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "vector.h"

static void vector_grow(vector *vector)
{
	vector->allocatedLength *= 2;
	vector->elements = realloc(vector->elements, vector->elementSize * vector->allocatedLength);
	assert(vector->elements != NULL);
}

void vector_new(vector *vector, int elementSize)
{
	assert(elementSize > 0);
	vector->logicalLength = 0;
	vector->allocatedLength = 2;
	vector->elements = NULL;
	vector_grow(vector);
}

void vector_destroy(vector *vector)
{
	int i;
	void *freeTarget;

	for(i = 0; i < vector->logicalLength; i++) {
		freeTarget = (char *)vector->elements + i * vector->elementSize;
		free(freeTarget);
	}

	// free main elements
	free(vector->elements);
}

void vector_add(vector *vector, void *element)
{
	if (vector->allocatedLength == vector->logicalLength) {
		vector_grow(vector);
	}

	void *target = (char *)vector->elements + vector->elementSize * vector->logicalLength++;
	memcpy(target, element, vector->elementSize);
}