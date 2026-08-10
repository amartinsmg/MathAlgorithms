#include "internal/mathlib_c.h"

bool isArmstrong(long long num) {
  int i;
  int k = floor(log10(num) + 1);
  long long n = num;
  long long sum = 0;
  for (i = 0; i < k; i++) {
    sum += pow((n % 10), k);
    n /= 10;
  }
  if (sum == num)
    return true;
  return false;
}
