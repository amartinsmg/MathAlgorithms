#include <math.h>

double logarithm(double num, double base)
{
  double result = log(num) / log(base);
  return result;
}

double nthRoot(double radicand, double degree)
{
  double result = pow(radicand, (1 / degree));
  return result;
}
