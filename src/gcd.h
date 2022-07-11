#include <math.h>

int gcd(int x, int y)
{
  int result, remainder = x % y;
  while (remainder)
  {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  result = abs(y);
  return result;
}
