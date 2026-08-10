#include "internal/mathlib_c.h"

double binominal(int trials, double successProb, int success) {
  if (trials < 0 || success < 0 || success > trials || successProb < 0 ||
      successProb > 1)
    return NAN;

  double result = combinationlf(trials, success) * pow(successProb, success) *
                  pow((1 - successProb), (trials - success));
  return result;
}

double poisson(double lambda, int x) {
  if (lambda < 0 || x < 0)
    return NAN;

  double result = exp(-lambda) * pow(lambda, x) / factoriallf(x);
  return result;
}

double gaussianCDF(double mu, double stdDev, double x) {
  if (stdDev < 0)
    return NAN;
  if (stdDev == 0)
    return (x < mu) ? 0.0 : 1.0;

  double phi;
  double result;
  double z;
  double denominator = 1;
  double sum = 0;
  int i;

  z = (x - mu) / stdDev;
  phi = exp(-pow(z, 2) / 2) / sqrt(2 * M_PI);

  for (i = 1; i <= 100; i += 2) {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }

  result = 0.5 + (phi * sum);
  return result;
}
