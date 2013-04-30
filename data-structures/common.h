#ifndef __CDS_COMMON_H
#define __CDS_COMMON_H

// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);

// boolean don't exist...seriously...
typedef enum { TRUE, FALSE } bool;

#endif