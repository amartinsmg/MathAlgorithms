#include "internal/mathlib_c.h"

long long gcd(long long x, long long y) {
  long long result;
  long long remainder;
  if (x == 0)
    return llabs(y);
  if (y == 0)
    return llabs(x);
  remainder = x % y;
  while (remainder) {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  result = llabs(y);
  return result;
}
