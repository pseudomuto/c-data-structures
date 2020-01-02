#include "cdatastructures/vector.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

static void test_initial_state(void **state) {
  vector v;
  vector_new(&v, sizeof(int), NULL);
  assert_int_equal(0, vector_size(&v));
  assert_int_equal(sizeof(int), v.elementSize);
  assert_null(v.freeFn);

  vector_destroy(&v);
}

static void test_item_at(void **state) {
  vector v;
  vector_new(&v, sizeof(int), NULL);

  int i;
  for (i = 0; i < 3; i++) {
    vector_add(&v, &i);
  }

  int value;
  for (i = 0; i < 3; i++) {
    vector_item_at(&v, i, &value);
    assert_int_equal(i, value);
  }

  vector_destroy(&v);
}

static void test_add_can_grow(void **state) {
  const int vector_initial_size = 4;

  vector v;
  vector_new(&v, sizeof(int), NULL);

  int i;
  for (i = 0; i < vector_initial_size + 2; i++) {
    vector_add(&v, &i);
  }

  int value;
  vector_item_at(&v, vector_initial_size, &value);
  assert_int_equal(vector_initial_size, value);

  vector_destroy(&v);
}

static void vector_string_free(void *pointer) { free(*(char **)pointer); }

static void test_string_values(void **state) {
  const char *names[] = {"David", "Muto", "Test"};

  vector v;
  vector_new(&v, sizeof(char *), vector_string_free);

  int i;
  char *name;
  for (i = 0; i < 3; i++) {
    name = strdup(names[i]);
    vector_add(&v, &name);
  }

  for (i = 0; i < 3; i++) {
    vector_item_at(&v, i, &name);
    assert_int_equal(0, strcmp(name, names[i]));
  }

  vector_destroy(&v);
}

static void test_insert(void **state) {
  int initLength = 10;

  vector v;
  vector_new(&v, sizeof(int), NULL);

  int i;
  for (i = 0; i < initLength; i++) {
    vector_add(&v, &v);
  }

  int value = 1000;
  // prepend value
  vector_insert_at(&v, 0, &value);

  // insert in the middle
  value = 500;
  vector_insert_at(&v, 5, &value);

  // same as add...
  value = 0;
  vector_insert_at(&v, v.logicalLength, &value);

  vector_item_at(&v, 0, &value);
  assert_int_equal(1000, value);

  vector_item_at(&v, 5, &value);
  assert_int_equal(500, value);

  vector_item_at(&v, v.logicalLength - 1, &value);
  assert_int_equal(0, value);

  vector_destroy(&v);
}

static void test_remove(void **state) {
  int initLength = 10;

  vector v;
  vector_new(&v, sizeof(int), NULL);

  int i;
  for (i = 0; i < initLength; i++) {
    vector_add(&v, &i);
  }

  // remove the first element
  int value;
  vector_remove_at(&v, 0);
  vector_item_at(&v, 0, &value);
  assert_int_equal(initLength - 1, vector_size(&v));
  assert_int_equal(1, value);

  // remove the last element
  vector_remove_at(&v, vector_size(&v) - 1);
  vector_item_at(&v, vector_size(&v) - 1, &value);
  assert_int_equal(initLength - 2, vector_size(&v));
  assert_int_equal(8, value);

  // remove something in the middle
  vector_remove_at(&v, 4);
  vector_item_at(&v, 4, &value);
  assert_int_equal(initLength - 3, vector_size(&v));
  assert_int_equal(6, value);

  vector_destroy(&v);
}

int run_all_tests() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_initial_state),
      cmocka_unit_test(test_item_at),
      cmocka_unit_test(test_add_can_grow),
      cmocka_unit_test(test_string_values),
      cmocka_unit_test(test_insert),
      cmocka_unit_test(test_remove),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
