#ifndef __CDS_QUEUE_H
#define __CDS_QUEUE_H 

#include "common.h"

typedef struct _queueNode {
	void *data;
	struct _queueNode *next;
	struct _queueNode *prev;
} queueNode;

typedef struct {
	int logicalLength;
	int elementSize;
	void (*freeFn)(void *);
} queue;

void queue_new(queue *q, int elementSize, void (*freeFn)(void *));

#endif