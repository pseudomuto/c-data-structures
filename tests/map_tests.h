#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "../data-structures/map.h"

void test_map_initializes()
{
	map m;
	map_new(&m, sizeof(int), NULL);
	assert(m.elementSize == sizeof(int));
	assert(m.root == NULL);
	assert(m.freeFn == NULL);
	assert(map_size(&m) == 0);

	map_destroy(&m);
	PRINT_SUCCESS();
}

void test_map_contains_key()
{
	map m;
	map_new(&m, sizeof(int), NULL);

	const char *key = "MapKey";
	int value = 10;
	map_set(&m, key, &value);
	assert(map_size(&m) == 1);

	bool result = map_contains_key(&m, key);
	assert(result == TRUE);
	assert(result);

	result = map_contains_key(&m, "someKey");
	assert(result == FALSE);
	assert(!result);

	map_destroy(&m);
	PRINT_SUCCESS();		
}

void test_map_can_set_value()
{
	map m;
	map_new(&m, sizeof(int), NULL);

	const char *key = "MapKey";
	int value = 10;
	map_set(&m, key, &value);
	assert(map_size(&m) == 1);

	value = 12;
	map_set(&m, key, &value);
	assert(map_size(&m) == 1);

	int found;
	map_get(&m, key, &found);
	assert(found == value);

	map_destroy(&m);
	PRINT_SUCCESS();	
}

void test_map_can_set_multiple_values()
{
	map m;
	map_new(&m, sizeof(int), NULL);

	const char *keys[] = { "First", "Last" };

	int value = 10;
	map_set(&m, keys[1], &value);
	assert(map_size(&m) == 1);

	int value2 = 12;
	map_set(&m, keys[0], &value2);
	assert(map_size(&m) == 2);

	int found;
	map_get(&m, keys[0], &found);
	assert(found == value2);

	map_get(&m, keys[1], &found);
	assert(found == value);

	map_destroy(&m);
	PRINT_SUCCESS();	
}

void test_map_can_get_value()
{
	map m;
	map_new(&m, sizeof(int), NULL);

	const char *key = "MapKey";
	int value = 10;
	map_set(&m, key, &value);

	assert(map_size(&m) == 1);

	int found;
	map_get(&m, key, &found);
	assert(found == value);

	map_destroy(&m);
	PRINT_SUCCESS();
}

void test_map_string_free(void *data) 
{
	free(*(char **)data);
}

void test_map_can_work_with_strings()
{
	const char *keys[] = { "First", "Last", "Other" };
	const char *names[] = { "David", "Muto", "Test" };

	map m;
	map_new(&m, sizeof(char *), test_map_string_free);

	int i;
	char *name;
	for(i = 0; i < 3; i++) {
		name = strdup(names[i]);
		map_set(&m, keys[i], &name);
	}

	assert(map_size(&m) == 3);

	map_get(&m, keys[1], &name);
	assert(strcmp(name, "Muto") == 0);

	map_destroy(&m);
	PRINT_SUCCESS();
}

void test_map_operations()
{
	test_map_initializes();
	test_map_contains_key();
	test_map_can_set_value();
	test_map_can_get_value();
	test_map_can_set_multiple_values();
	test_map_can_work_with_strings();
}