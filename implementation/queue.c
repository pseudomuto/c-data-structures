#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../data-structures/queue.h"

void queue_new(queue *q, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	q->logicalLength = 0;
	q->elementSize = elementSize;
	q->head = q->tail = NULL;
	q->freeFn = freeFn;
}

void queue_destroy(queue *q)
{
	listNode *current;
	while(q->head != NULL) {
		current = q->head;
		q->head = current->next;

		if (q->freeFn && current->data) {
			q->freeFn(current->data);
		}

		free(current->data);
		free(current);
	}
}

void queue_enqueue(queue *q, void *element)
{
	listNode *node = malloc(sizeof(listNode));
	node->data = malloc(q->elementSize);
	node->next = NULL;
	
	memcpy(node->data, element, q->elementSize);

	if(q->logicalLength == 0) {
		q->head = q->tail = node;
	} else {
		q->tail->next = node;
		q->tail = node;
	}

	q->logicalLength++;
}

void queue_dequeue(queue *q, void *element)
{
	assert(q->logicalLength > 0);

	listNode *node = q->head;
	q->head = node->next;
	memcpy(element, node->data, q->elementSize);

	free(node->data);
	free(node);

	// no more elements
	if(!q->head) {
		q->tail = q->head;
	}

	q->logicalLength--;
}

void queue_peek(queue *q, void *element)
{
	assert(q->logicalLength > 0);

	listNode *node = q->head;
	memcpy(element, node->data, q->elementSize);
}

int queue_size(queue *q)
{
	return q->logicalLength;
}