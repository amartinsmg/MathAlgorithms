#include "internal/mathlib_c.h"

double logarithm(double num, double base) {
  if (num <= 0 || base <= 0 || base == 1)
    return NAN;
  double result = log(num) / log(base);
  return result;
}

double nthRoot(double radicand, double degree) {
  if (degree == 0)
    return NAN;
  double result = pow(radicand, (1 / degree));
  return result;
}

double roundTo(double num, int decimalPlaces) {
  double result;
  double base_10 = pow(10, decimalPlaces);
  result = round(num * base_10) / base_10;
  return result;
}
