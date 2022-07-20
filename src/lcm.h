#include <math.h>
#include "gcd.h"

long long lcm(int x, int y)
{
  assert(x != 0 && y != 0);
  long long result = abs(x * y / gcd(x, y));
  return result;
}
