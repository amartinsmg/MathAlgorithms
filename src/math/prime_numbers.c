#include "internal/mathlib_c.h"

bool isPrime(long long num) {
  long long i;
  for (i = 2; num % i && i <= num; i++)
    if (i * i > num)
      return true;
  if (i == num)
    return true;
  return false;
}
