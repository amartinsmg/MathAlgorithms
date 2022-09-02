#include <assert.h>
#include <math.h>
#include "combinatorics.h"

double binominal(int trials, double success_prob, int success)
{
  double result;
  assert(trials > 0 && success >= 0 && success_prob >= 0 && success_prob <= 1);
  result = combinationlf(trials, success) *
           pow(success_prob, success) *
           pow((1 - success_prob), (trials - success));
  return result;
}

double poisson(double mean, unsigned x)
{
  double result;
  result = exp(-mean) * pow(mean, x) / factoriallf(x);
  return result;
}

double gaussianCDF(double mean, double standadDev, double x)
{
  double phi, result, z, denominator = 1,
                         sum = 0;
  int i;
  assert(standadDev > 0);
  z = (x - mean) / standadDev;
  phi = exp(-pow(z, 2) / 2) / sqrt(2 * M_PI);
  for (i = 1; i <= 100; i += 2)
  {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }
  result = 0.5 + phi * sum;
  return result;
}
