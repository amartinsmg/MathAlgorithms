#include <assert.h>
#include <math.h>
#include "gcd.h"

#ifndef LCM_H
#define LCM_H

/**
  @brief Calculate the least common multiple (LCM) of two integers.
  @param x The first integer.
  @param y The second integer.
  @return The LCM of 'x' and 'y'.
  @pre x and y cannot both be 0.
*/

long long lcm(int x, int y)
{
  long long result;
  assert(x != 0 && y != 0);
  result = abs(x * y / gcd(x, y));
  return result;
}

#endif /* LCM_H */
