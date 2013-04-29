#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../data-structures/stack.h"

void stack_new(stack *s, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	s->logicalLength = 0;
	s->elementSize = elementSize;
	s->freeFn = freeFn;
	s->head = NULL;
}

void stack_destroy(stack *s)
{
	listNode *current;
	while(s->head != NULL) {
		current = s->head;
		s->head = current->next;

		if (s->freeFn) {
			s->freeFn(current->data);
		}

		free(current->data);
		free(current);
	}
}

void stack_push(stack *s, void *element)
{
	listNode *node = malloc(sizeof(listNode));
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

	listNode *node = s->head;
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

	listNode *node = s->head;
	memcpy(element, node->data, s->elementSize);
}

int stack_size(stack *s)
{
	return s->logicalLength;
}