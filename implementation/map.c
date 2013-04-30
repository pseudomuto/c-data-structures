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

void map_contains_key(map *map, const char *key)
{
	
}

void map_set(map *map, const char *key, void *element)
{
	mapNode *node = malloc(sizeof(mapNode));
	node->key = strdup(key);
	node->value = malloc(map->elementSize);
	memcpy(node->value, element, map->elementSize);
	map->logicalLength++;

	if(map->root) {

	} else {
		map->root = node;
		map->root->left = NULL;
		map->root->right = NULL;
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