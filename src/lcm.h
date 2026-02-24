#ifndef LCM_H
#define LCM_H

#include <errno.h>
#include <math.h>
#include "gcd.h"

/**
 * @brief Calculate the least common multiple (LCM) of two integers.
 *
 * @param x The first integer.
 * @param y The second integer.
 *
 * @return The LCM of 'x' and 'y'.
 */

long long lcm(int x, int y)
{
  if (x == 0 || y == 0)
    return 0;
  long long result;
  result = abs(x * y / gcd(x, y));
  return result;
}

#endif /* LCM_H */
