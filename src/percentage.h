#include <assert.h>

double nPercentOfX(double x, double n)
{
  double result = x / 100 * n;
  return result;
}

double nIsWhatPercentOfX(double x, double n)
{
  assert(x != 0);
  double result = n / x * 100;
  return result;
}
