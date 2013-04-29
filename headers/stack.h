typedef struct _stackNode {
	void *data;
	struct _stackNode *next;
} stackNode;

typedef struct {
	int logicalLength;
	int elementSize;
	stackNode *head;
	void (*freeFn)(void *);
} stack;

void stack_new(stack *s, int elementSize, void (*freeFn)(void *));
void stack_destroy(stack *s);
void stack_push(stack *s, void *element);
void stack_pop(stack *s, void *element);
void stack_peek(stack *s, void *element);