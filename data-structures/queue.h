#ifndef __CDS_QUEUE_H
#define __CDS_QUEUE_H 

#include "common.h"

typedef struct _queueNode {
	void *data;
	struct _queueNode *next;
} queueNode;

typedef struct {
	int logicalLength;
	int elementSize;
	queueNode *head;
	queueNode *tail;
	freeFunction freeFn;
} queue;

void queue_new(queue *q, int elementSize, freeFunction freeFn);
void queue_destroy(queue *q);
void queue_enqueue(queue *q, void *element);
void queue_dequeue(queue *q, void *element);
void queue_peek(queue *q, void *element);
int queue_size(queue *q);

#endif