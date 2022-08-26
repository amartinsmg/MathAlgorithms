#include <math.h>

int gcd(int x, int y)
{
  int result, remainder;
  if (x == 0)
    return abs(y);
  else if (y == 0)
    return abs(x);
  remainder = x % y;
  while (remainder)
  {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  result = abs(y);
  return result;
}
