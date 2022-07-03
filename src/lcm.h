#include <math.h>
#include "./gcd.h"

long long lcm(int x, int y)
{
  long long result = abs(x * y / gcd(x, y));
  return result;
}
