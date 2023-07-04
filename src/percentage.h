#include <assert.h>

/**
  @brief Calculate n percent of x.
  @param x The value.
  @param n The percentage.
  @return The calculated result.
*/

double nPercentOfX(double x, double n)
{
  double result = x / 100 * n;
  return result;
}

/**
  @brief Calculate what percentage n is of x.
  @param x The value.
  @param n The value to calculate the percentage for.
  @return The calculated percentage.
*/

double nIsWhatPercentOfX(double x, double n)
{
  double result;
  assert(x != 0);
  result = n / x * 100;
  return result;
}
