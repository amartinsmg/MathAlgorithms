#include "internal/mathlib_c.h"

double simpGrowth(double initial, double rate, double interval) {
  if (interval < 0)
    return NAN;
  double result = initial * (1 + rate * interval);
  return result;
}

double simpGrowthRate(double initial, double final, double interval) {
  if (initial == 0 || interval <= 0)
    return NAN;
  double result = (final / initial - 1) / interval;
  return result;
}

double compGrowth(double initial, double rate, double interval) {
  if (interval < 0)
    return NAN;
  double result = initial * pow((1 + rate), interval);
  return result;
}

double compGrowthRate(double initial, double final, double interval) {
  if (initial == 0 || interval <= 0)
    return NAN;
  double result = nthRoot((final / initial), interval) - 1;
  return result;
}
