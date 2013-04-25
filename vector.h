typedef struct {
	void *elements;
	int elementSize;
	int allocatedLength;
	int logicalLength;
} vector;

void vector_new(vector *vector, int elementSize);
void vector_destroy(vector *vector);

void vector_add(vector *vector, void *element);
int vector_size(vector *vector);