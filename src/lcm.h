#include "./gcd.h"

long long lcm(unsigned x, unsigned y)
{
  long long result = x * y / gcd(x, y);
  return result;
}
