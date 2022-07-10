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

double absf(double num)
{
  if (num >= 0)
    return num;
  else
    return -num;
}
