#include "internal/mathlib_c.h"
#include "utils/set.h"
#include <errno.h>
#include <stdio.h>

bool isHappy(long long num) {
  long long remainder;
  long long sum = num;
  Set num_set = set_init(sizeof(long long));
  if (set_add_value(&num_set, &sum) == -1) {
    set_free(&num_set);
    errno = ENOMEM;
    perror("Error calculating happy number");
    return false;
  }

  while (true) {
    sum = 0;
    while (num > 0) {
      remainder = num % 10;
      num /= 10;
      sum += remainder * remainder;
    }
    if (sum == 1) {
      set_free(&num_set);
      return true;
    }
    if (set_contains(&num_set, &sum)) {
      set_free(&num_set);
      return false;
    }
    if (set_add_value(&num_set, &sum) == -1) {
      set_free(&num_set);
      errno = ENOMEM;
      perror("Error calculating happy number");
      return false;
    }

    num = sum;
  }
}