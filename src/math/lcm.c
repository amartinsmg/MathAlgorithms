#include "internal/mathlib_c.h"

long long lcm(long long x, long long y) {
  if (x == 0 || y == 0)
    return 0;
  long long result = llabs(x / gcd(x, y) * y);

  return result;
}
