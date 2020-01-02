#include "cdatastructures/map.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void map_free_node(mapNode *node, freeFunction freeFn) {
  // base case
  if (node == NULL)
    return;

  // post order delete
  map_free_node(node->left, freeFn);
  map_free_node(node->right, freeFn);

  if (freeFn) {
    freeFn(node->value);
  }

  free(node->key);
  free(node->value);
  free(node);
}

static mapNode *map_find_node(mapNode *node, const char *key) {
  // base case
  if (!node)
    return NULL;

  int result = strcmp(node->key, key);

  if (result == 0)
    return node;
  else if (result < 0)
    return map_find_node(node->left, key);
  else
    return map_find_node(node->right, key);
}

static void map_insert_node(mapNode *tree, mapNode *node) {
  int result;
  mapNode *parent;

  while (tree) {
    // store result
    parent = tree;
    result = strcmp(tree->key, node->key);

    if (result < 0)
      tree = tree->left;
    else
      tree = tree->right;
  }

  // must have found a parent!
  assert(parent);

  result = strcmp(parent->key, node->key);
  if (result < 0)
    parent->left = node;
  else
    parent->right = node;
}

void map_new(map *map, int elementSize, freeFunction freeFn) {
  assert(elementSize > 0);

  map->elementSize = elementSize;
  map->logicalLength = 0;
  map->freeFn = freeFn;
  map->root = NULL;
}

void map_destroy(map *map) {
  // recursively delete tree
  map_free_node(map->root, map->freeFn);
}

bool map_contains_key(map *map, const char *key) {
  mapNode *node = map_find_node(map->root, key);
  return (node != NULL);
}

void map_set(map *map, const char *key, void *element) {
  mapNode *node;

  if (map_contains_key(map, key)) {
    node = map_find_node(map->root, key);
    memcpy(node->value, element, map->elementSize);
    return;
  }

  node = malloc(sizeof(mapNode));
  node->left = node->right = NULL;
  node->key = strdup(key);
  node->value = malloc(map->elementSize);
  memcpy(node->value, element, map->elementSize);

  map->logicalLength++;

  if (!map->root) {
    map->root = node;
    map->root->left = NULL;
    map->root->right = NULL;
  } else {
    map_insert_node(map->root, node);
  }
}

void map_get(map *map, const char *key, void *element) {
  mapNode *node = map_find_node(map->root, key);

  assert(node != NULL);
  memcpy(element, node->value, map->elementSize);
}

int map_size(map *map) { return map->logicalLength; }
