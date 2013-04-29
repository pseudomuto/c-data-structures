#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../headers/stack.h"

void stack_new(stack *s, int elementSize, void (*freeFn)(void *))
{
	s->logicalLength = 0;
	s->elementSize = elementSize;
	s->freeFn = freeFn;
	s->head = NULL;
}

void stack_destroy(stack *s)
{
	stackNode *current;
	while(s->head != NULL) {
		current = s->head;
		s->head = current->next;

		free(current->data);
		free(current);
	}
}

void stack_push(stack *s, void *element)
{
	stackNode *node = malloc(sizeof(stackNode));
	node->data = malloc(s->elementSize);
	memcpy(node->data, element, s->elementSize);

	node->next = s->head;
	s->head = node;
	s->logicalLength++;
}

void stack_pop(stack *s, void *element)
{
	// don't pop an empty stack!
	assert(s->logicalLength > 0);

	stackNode *node = s->head;
	memcpy(element, node->data, s->elementSize);
	s->head = s->head->next;
	s->logicalLength--;

	// free data and node
	free(node->data);
	free(node);
}

void stack_peek(stack *s, void *element)
{
	assert(s->logicalLength > 0);

	stackNode *node = s->head;
	memcpy(element, node->data, s->elementSize);
}