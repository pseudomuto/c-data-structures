#include "cdatastructures/queue.h"
#include "test.h"
#include <stdlib.h>
#include <string.h>

static void test_initial_state(void **state) {
  queue q;
  queue_new(&q, sizeof(int), NULL);
  assert_int_equal(0, queue_size(&q));

  queue_destroy(&q);
}

static void test_enqueue(void **state) {
  queue q;
  queue_new(&q, sizeof(int), NULL);

  int value = 10;
  queue_enqueue(&q, &value);
  assert_int_equal(1, queue_size(&q));

  queue_destroy(&q);
}

static void test_dequeue(void **state) {
  queue q;
  queue_new(&q, sizeof(int), NULL);

  int value = 10;
  queue_enqueue(&q, &value);
  assert_int_equal(1, queue_size(&q));

  int other;
  queue_dequeue(&q, &other);
  assert_int_equal(value, other);
  assert_int_equal(0, queue_size(&q));

  queue_destroy(&q);
}

static void test_peek() {
  queue q;
  queue_new(&q, sizeof(int), NULL);

  int value = 10;
  queue_enqueue(&q, &value);
  assert_int_equal(1, queue_size(&q));

  int other;
  queue_peek(&q, &other);
  assert_int_equal(value, other);
  assert_int_equal(1, queue_size(&q));

  queue_destroy(&q);
}

static void queue_free_string(void *data) { free(*(char **)data); }

static void test_string_values(void **state) {
  queue q;
  queue_new(&q, sizeof(char *), queue_free_string);

  const char *names[] = {"David", "Muto", "Tester"};
  int i;
  char *name;
  for (i = 0; i < 3; i++) {
    name = strdup(names[i]);
    queue_enqueue(&q, &name);
  }

  assert_int_equal(3, queue_size(&q));

  queue_dequeue(&q, &name);
  assert_int_equal(0, strcmp(name, "David"));
  free(name);

  assert_int_equal(2, queue_size(&q));
  queue_destroy(&q);
}

int run_all_tests() {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_initial_state),
      cmocka_unit_test(test_enqueue),
      cmocka_unit_test(test_dequeue),
      cmocka_unit_test(test_peek),
      cmocka_unit_test(test_string_values),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
