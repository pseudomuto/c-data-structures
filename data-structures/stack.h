#ifndef __CDS_STACK_H
#define __CDS_STACK_H

#include "common.h"

typedef struct _stackNode {
	void *data;
	struct _stackNode *next;
} stackNode;

typedef struct {
	int logicalLength;
	int elementSize;
	stackNode *head;
	freeFunction freeFn;
} stack;

void stack_new(stack *s, int elementSize, freeFunction freeFn);
void stack_destroy(stack *s);
void stack_push(stack *s, void *element);
void stack_pop(stack *s, void *element);
void stack_peek(stack *s, void *element);
int stack_size(stack *s);
#endif