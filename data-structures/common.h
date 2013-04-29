#ifndef __CDS_COMMON_H
#define __CDS_COMMON_H

// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);

typedef struct _listNode {
	void *data;
	struct _listNode *next;
} listNode;

#endif