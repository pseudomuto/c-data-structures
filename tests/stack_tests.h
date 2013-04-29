#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "../data-structures/stack.h"

void test_stack_initializes() 
{
	stack s;
	stack_new(&s, sizeof(int), NULL);

	assert(s.logicalLength == 0);
	assert(s.elementSize == sizeof(int));
	assert(s.freeFn == NULL);
	assert(s.head == NULL);

	stack_destroy(&s);
}

void test_stack_can_push_item()
{
	stack s;
	stack_new(&s, sizeof(int), NULL);

	int value = 10;
	stack_push(&s, &value);

	assert(s.logicalLength == 1);

	stack_destroy(&s);
} 

void test_stack_can_pop_item()
{
	stack s;
	stack_new(&s, sizeof(int), NULL);

	int value = 10;
	stack_push(&s, &value);
	assert(s.logicalLength == 1);

	int other;
	stack_pop(&s, &other);
	assert(other == value);
	assert(s.logicalLength == 0);

	stack_destroy(&s);
}

void test_stack_can_peek_item()
{
	stack s;
	stack_new(&s, sizeof(int), NULL);

	int value = 10;
	stack_push(&s, &value);
	assert(s.logicalLength == 1);

	int other;
	stack_peek(&s, &other);
	assert(other == value);
	assert(s.logicalLength == 1);

	stack_destroy(&s);
}

void test_stack_free_string(void *data)
{
	free(*(char **)data);
}

void test_stack_can_work_with_strings()
{
	stack s;
	stack_new(&s, sizeof(char *), test_stack_free_string);

	const char *names[] = { "David", "Muto", "Tester" };
	int i;
	char *name;
	for(i = 0; i < 3; i++) {
		name = strdup(names[i]);
		stack_push(&s, &name);
	}

	assert(stack_size(&s) == 3);

	stack_pop(&s, &name);
	assert(strcmp(name, "Tester") == 0);
	free(name);

	assert(stack_size(&s) == 2);
	stack_destroy(&s);
}

void test_stack_operations()
{
	test_stack_initializes();
	test_stack_can_push_item();
	test_stack_can_pop_item();
	test_stack_can_peek_item();
	test_stack_can_work_with_strings();
}