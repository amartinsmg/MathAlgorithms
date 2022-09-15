#include <assert.h>
#include <math.h>
#include "gcd.h"

long long lcm(int x, int y)
{
  long long result;
  assert(x != 0 && y != 0);
  result = abs(x * y / gcd(x, y));
  return result;
}
