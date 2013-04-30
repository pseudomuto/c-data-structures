#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "../data-structures/list.h"

void test_list_initializes()
{
	list l;
	list_new(&l, sizeof(int), NULL);

	assert(list_size(&l) == 0);
	assert(l.elementSize == sizeof(int));
	assert(l.head == NULL);
	assert(l.tail == NULL);
	assert(l.freeFn == NULL);

	list_destroy(&l);
	PRINT_SUCCESS();
}

void test_list_can_append_item() 
{
	list l;
	list_new(&l, sizeof(int), NULL);

	int i;
	for(i = 0; i < 10; i++) {
		list_append(&l, &i);
	}

	assert(list_size(&l) == 10);

	int value;
	list_tail(&l, &value, PEEK);
	assert(value == 9);

	list_head(&l, &value, PEEK);
	assert(value == 0);

	list_destroy(&l);
	PRINT_SUCCESS();
}

void test_list_can_prepend_item()
{
	list l;
	list_new(&l, sizeof(int), NULL);

	int i;
	for(i = 0; i < 10; i++) {
		list_prepend(&l, &i);
	}

	assert(list_size(&l) == 10);

	int value;
	list_tail(&l, &value, PEEK);
	assert(value == 0);

	list_head(&l, &value, PEEK);
	assert(value == 9);

	list_destroy(&l);
	PRINT_SUCCESS();
}

void test_list_operations()
{
	test_list_initializes();
	test_list_can_append_item();
	test_list_can_prepend_item();
}