#ifndef CDATASTRUCTURES_TEST_H
#define CDATASTRUCTURES_TEST_H

#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <cmocka.h>

/**
 * This function must be defined in every test file
 * @return the exit code
 */
int run_all_tests(void);


int main() {
  return run_all_tests();
}

#endif // CDATASTRUCTURES_TEST_H
