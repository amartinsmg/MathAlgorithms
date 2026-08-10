#include "internal/mathlib_c.h"

double nPercentOfX(double x, double n)
{
  if (n == 0)
    return 0;
  double result = x / 100 * n;
  return result;
}

double nIsWhatPercentOfX(double x, double n)
{
  if (x == 0)
    return 0;
  double result = n / x * 100;
  return result;
}
