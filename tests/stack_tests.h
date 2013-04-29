// void stack_new(stack *s, int elementSize, void (*freeFn)(void *));
// void stack_destroy(stack *s);
// void stack_push(stack *s, void *element);
// void stack_pop(stack *s, void *element);
// void stack_peek(stack *s, void *element);

#include <assert.h>

#include "../headers/stack.h"

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

void test_stack_operations()
{
	test_stack_initializes();
	test_stack_can_push_item();
	test_stack_can_pop_item();
	test_stack_can_peek_item();
}