#include <assert.h>
#include <math.h>
#include "combinatorics.h"

#define PI 3.141592653589793

double binominal(int trials, int success, double success_prob)
{
  double result;
  assert(trials > 0 && success >= 0 && success_prob >= 0 && success_prob <= 1);
  result = combinationlf(trials, success) *
           pow(success_prob, success) *
           pow((1 - success_prob), (trials - success));
  return result;
}

double poisson(int x, double mean)
{
  double result;
  assert(x >= 0);
  result = exp(-mean) * pow(mean, x) / factoriallf(x);
  return result;
}

double gaussianCDF(double x, double mean, double standadDev)
{
  double denominator, phi, result, sum, z;
  int i;
  assert(standadDev != 0);
  z = (x - mean) / standadDev;
  phi = exp(-pow(z, 2) / 2) / sqrt(2 * PI);
  sum = 0;
  denominator = 1;
  for (i = 1; i <= 100; i += 2)
  {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }
  result = 0.5 + phi * sum;
  return result;
}
