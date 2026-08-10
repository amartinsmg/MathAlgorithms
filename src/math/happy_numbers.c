#include "internal/mathlib_c.h"
#include "utils/set.h"

bool isHappy(long long num) {
  long long remainder;
  long long sum = num;
  Set num_set = set_init(sizeof(long long));
  set_add_value(&num_set, &sum);
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
    set_add_value(&num_set, &sum);
    num = sum;
  }
}