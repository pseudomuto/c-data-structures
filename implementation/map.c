#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../data-structures/map.h"

static void map_free_node(mapNode *node, freeFunction freeFn)
{
	// base case
	if(node == NULL) return;

	// post order delete
	map_free_node(node->left, freeFn);
	map_free_node(node->right, freeFn);

	if(freeFn) {
		freeFn(node->value);
	}

	free(node->key);
	free(node->value);
	free(node);
}

static mapNode *map_find_node(mapNode *node, const char *key)
{
	// base case
	if(node == NULL) return NULL;

	int result = strcmp(node->key, key);

	if(result == 0) return node;
	else if(result < 0) return map_find_node(node->left, key);	
	else return map_find_node(node->right, key);
}

void map_new(map *map, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	map->elementSize = elementSize;
	map->logicalLength = 0;
	map->freeFn = freeFn;
	map->root = NULL;
}

void map_destroy(map *map)
{
	// recursively delete tree
	map_free_node(map->root, map->freeFn);
}

bool map_contains_key(map *map, const char *key)
{
	mapNode *node = map_find_node(map->root, key);
	return (node == NULL) ? FALSE : TRUE;
}

void map_set(map *map, const char *key, void *element)
{
	mapNode *node;
	bool containsKey = map_contains_key(map, key);

	if(!containsKey) {
		node = malloc(sizeof(mapNode));
		node->key = strdup(key);
		node->value = malloc(map->elementSize);
		memcpy(node->value, element, map->elementSize);
		map->logicalLength++;
	} else {
		node = map_find_node(map->root, key);
		memcpy(node->value, element, map->elementSize);
		return;
	}

	if(!map->root) {
		map->root = node;
		map->root->left = NULL;
		map->root->right = NULL;
	} else {
		// TODO: Find out where to put this new node..
	}
}

void map_get(map *map, const char *key, void *element)
{
	memcpy(element, map->root->value, map->elementSize);
}

int map_size(map *map)
{
	return map->logicalLength;
}