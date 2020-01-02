#include "cdatastructures/queue.h"
#include <stdlib.h>

void queue_new(queue *q, int elementSize, freeFunction freeFn) {
  q->list = malloc(sizeof(list));
  list_new(q->list, elementSize, freeFn);
}

void queue_destroy(queue *q) {
  list_destroy(q->list);
  free(q->list);
}

void queue_enqueue(queue *q, void *element) { list_append(q->list, element); }

void queue_dequeue(queue *q, void *element) {
  list_head(q->list, element, true);
}

void queue_peek(queue *q, void *element) { list_head(q->list, element, false); }

int queue_size(queue *q) { return list_size(q->list); }
