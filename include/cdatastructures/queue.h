#ifndef __CDS_QUEUE_H
#define __CDS_QUEUE_H

#include "common.h"
#include "list.h"

typedef struct {
  list *list;
} queue;

void queue_new(queue *q, int elementSize, freeFunction freeFn);

void queue_destroy(queue *q);

void queue_enqueue(queue *q, void *element);

void queue_dequeue(queue *q, void *element);

void queue_peek(queue *q, void *element);

int queue_size(queue *q);

#endif
