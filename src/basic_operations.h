#include <math.h>

double logarithm(double num, double base)
{
  double result = log(num) / log(base);
  return result;
}

double nthRoot(double radicand, double degree)
{
  double result;
  assert(degree != 0);
  result = pow(radicand, (1 / degree));
  return result;
}

double absf(double num)
{
  if (num >= 0)
    return num;
  else
    return -num;
}

double roundTo(double num, unsigned decimalPlaces)
{
  double result, base10 = pow(10, decimalPlaces);
  result = round(num * base10) / base10;
  return result;
}
