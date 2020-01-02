#ifndef __CDS_VECTOR_H
#define __CDS_VECTOR_H

#include "common.h"

typedef struct {
  void *elements;
  int elementSize;
  int allocatedLength;
  int logicalLength;
  freeFunction freeFn;
} vector;

void vector_new(vector *vector, int elementSize, freeFunction freeFn);

void vector_destroy(vector *vector);

int vector_size(vector *vector);

void vector_add(vector *vector, void *element);

void vector_item_at(vector *vector, int index, void *target);

void vector_insert_at(vector *vector, int index, void *target);

void vector_remove_at(vector *vector, int index);

#endif
