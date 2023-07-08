#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#ifndef TEST_H
#define TEST_H

/**
  @brief Perform a test and assert the given condition.
  This function performs a test with the specified code and checks if the given condition is true.
  If the condition is true, the test is considered passed.
  @param code The code of the test.
  @param condition The condition to be tested.
  @return None.
*/

void test(int code, bool condition)
{
  printf("Test #%d: ", code);
  assert(condition);
  printf("Passed!\n");
}

#endif /* TEST_H */
