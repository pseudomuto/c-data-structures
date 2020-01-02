#include "cdatastructures/stack.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

static void test_initial_state(void **state) {
  stack s;
  stack_new(&s, sizeof(int), NULL);
  assert_int_equal(0, stack_size(&s));

  stack_destroy(&s);
}

static void test_push(void **state) {
  stack s;
  stack_new(&s, sizeof(int), NULL);

  int value = 10;
  stack_push(&s, &value);
  assert_int_equal(1, stack_size(&s));

  stack_destroy(&s);
}

static void test_pop(void **state) {
  stack s;
  stack_new(&s, sizeof(int), NULL);

  int value = 10;
  stack_push(&s, &value);
  assert_int_equal(1, stack_size(&s));

  int other;
  stack_pop(&s, &other);
  assert_int_equal(value, other);
  assert_int_equal(0, stack_size(&s));

  stack_destroy(&s);
}

static void test_peek(void **state) {
  stack s;
  stack_new(&s, sizeof(int), NULL);

  int value = 10;
  stack_push(&s, &value);
  assert_int_equal(1, stack_size(&s));

  int other;
  stack_peek(&s, &other);
  assert_int_equal(value, other);
  assert_int_equal(1, stack_size(&s));

  stack_destroy(&s);
}

static void stack_free_string(void *data) { free(*(char **)data); }

static void test_string_values(void **state) {
  stack s;
  stack_new(&s, sizeof(char *), stack_free_string);

  const char *names[] = {"David", "Muto", "Tester"};
  int i;
  char *name;
  for (i = 0; i < 3; i++) {
    name = strdup(names[i]);
    stack_push(&s, &name);
  }

  assert_int_equal(3, stack_size(&s));

  stack_pop(&s, &name);
  assert_int_equal(0, strcmp(name, "Tester"));
  free(name);

  assert_int_equal(2, stack_size(&s));
  stack_destroy(&s);
}

int run_all_tests() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_initial_state),
      cmocka_unit_test(test_push),
      cmocka_unit_test(test_pop),
      cmocka_unit_test(test_peek),
      cmocka_unit_test(test_string_values),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
