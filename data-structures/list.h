#ifndef __CDS_LINKEDLIST_H
#define __CDS_LINKEDLIST_H

#include "common.h"

typedef enum { REMOVE, PEEK } listAction;

typedef struct _listNode {
	void *data;
	struct _listNode *next;
} listNode;

typedef struct {
	int logicalLength;
	int elementSize;
	listNode *head;
	listNode *tail;
	freeFunction freeFn;
} list;

void list_new(list *list, int elementSize, freeFunction freeFn);
void list_destroy(list *list);

void list_prepend(list *list, void *element);
void list_append(list *list, void *element);
int list_size(list *list);

void list_head(list *list, void *element, listAction action);
void list_tail(list *list, void *element, listAction action);

#endif