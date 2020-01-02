#include "cdatastructures/map.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

static void test_initial_state(void **state) {
  map m;
  map_new(&m, sizeof(int), NULL);
  assert_int_equal(sizeof(int), m.elementSize);
  assert_int_equal(0, map_size(&m));
  assert_null(m.root);
  assert_null(m.freeFn);

  map_destroy(&m);
}

static void test_contains_key(void **state) {
  map m;
  map_new(&m, sizeof(int), NULL);

  const char *key = "MapKey";
  int value = 10;
  map_set(&m, key, &value);
  assert_int_equal(1, map_size(&m));
  assert_true(map_contains_key(&m, key));
  assert_false(map_contains_key(&m, "someKey"));

  map_destroy(&m);
}

static void test_set(void **state) {
  map m;
  map_new(&m, sizeof(int), NULL);

  const char *key = "MapKey";
  int value = 10;
  map_set(&m, key, &value);
  assert_int_equal(1, map_size(&m));

  value = 12;
  map_set(&m, key, &value);
  assert_int_equal(1, map_size(&m));

  int found;
  map_get(&m, key, &found);
  assert_int_equal(value, found);

  map_destroy(&m);
}

static void test_set_multiple_values(void **state) {
  map m;
  map_new(&m, sizeof(int), NULL);

  const char *keys[] = {"First", "Last"};

  int value = 10;
  map_set(&m, keys[1], &value);
  assert_int_equal(1, map_size(&m));

  int value2 = 12;
  map_set(&m, keys[0], &value2);
  assert_int_equal(2, map_size(&m));

  int found;
  map_get(&m, keys[0], &found);
  assert_int_equal(value2, found);

  map_get(&m, keys[1], &found);
  assert_int_equal(value, found);

  map_destroy(&m);
}

static void test_get() {
  map m;
  map_new(&m, sizeof(int), NULL);

  const char *key = "MapKey";
  int value = 10;
  map_set(&m, key, &value);

  assert_int_equal(1, map_size(&m));

  int found;
  map_get(&m, key, &found);
  assert_int_equal(value, found);

  map_destroy(&m);
}

static void string_map_free_fn(void *data) { free(*(char **)data); }

static void test_string_values(void **state) {
  const char *keys[] = {"First", "Last", "Other"};
  const char *names[] = {"David", "Muto", "Test"};

  map m;
  map_new(&m, sizeof(char *), string_map_free_fn);

  int i;
  char *name;
  for (i = 0; i < 3; i++) {
    name = strdup(names[i]);
    map_set(&m, keys[i], &name);
  }

  assert_int_equal(3, map_size(&m));

  map_get(&m, keys[1], &name);
  assert_int_equal(0, strcmp(name, "Muto"));

  map_destroy(&m);
}

int run_all_tests() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_initial_state),
      cmocka_unit_test(test_contains_key),
      cmocka_unit_test(test_set),
      cmocka_unit_test(test_set_multiple_values),
      cmocka_unit_test(test_get),
      cmocka_unit_test(test_string_values),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
