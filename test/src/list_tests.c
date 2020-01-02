#include "cdatastructures/list.h"
#include "test.h"

static void test_initial_state(void **state) {
  list l;
  list_new(&l, sizeof(int), NULL);

  assert_int_equal(0, list_size(&l));
  assert_int_equal(sizeof(int), l.elementSize);
  assert_null(l.head);
  assert_null(l.tail);
  assert_null(l.freeFn);

  list_destroy(&l);
}

static void test_append(void **state) {
  list l;
  list_new(&l, sizeof(int), NULL);

  int i;
  for (i = 0; i < 10; i++) {
    list_append(&l, &i);
  }

  assert_int_equal(10, list_size(&l));

  int value;
  list_tail(&l, &value);
  assert_int_equal(9, value);

  list_head(&l, &value, false);
  assert_int_equal(0, value);

  list_destroy(&l);
}

static void test_prepend(void **state) {
  list l;
  list_new(&l, sizeof(int), NULL);

  int i;
  for (i = 0; i < 10; i++) {
    list_prepend(&l, &i);
  }

  assert_int_equal(10, list_size(&l));

  int value;
  list_tail(&l, &value);
  assert_int_equal(0, value);

  list_head(&l, &value, false);
  assert_int_equal(9, value);

  list_destroy(&l);
}

static int iteratorCount = 0;

static bool iterate(void *data) {
  assert_int_equal(iteratorCount++, *(int *)data);
  return iteratorCount != 5;
}

static void test_for_each(void **state) {
  list l;
  list_new(&l, sizeof(int), NULL);

  int i;
  int numItems = 10;
  for (i = 0; i < numItems; i++) {
    list_append(&l, &i);
  }

  assert_int_equal(numItems, list_size(&l));

  iteratorCount = 0;
  list_for_each(&l, iterate);
  assert_int_equal(5, iteratorCount);

  list_destroy(&l);
}

int run_all_tests() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_initial_state),
      cmocka_unit_test(test_append),
      cmocka_unit_test(test_prepend),
      cmocka_unit_test(test_for_each),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
