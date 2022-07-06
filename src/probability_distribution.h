#include <assert.h>
#include <math.h>
#include "combinatorics.h"

#define PI 3.141592653589793

double binominal(int n, int x, double p)
{
  assert(n > 0 && x >= 0 && p >= 0 && p <= 1);
  double probability = combinationlf(n, x) * pow(p, x) * pow((1 - p), (n - x));
  return probability;
}

double poisson(double lambda, int k)
{
  assert(k >= 0);
  double probability = exp(-lambda) * pow(lambda, k) / factoriallf(k);
  return probability;
}

double gaussianCDF(double x, double mu, double sigma)
{
  double z = (x - mu) / sigma,
         phi = exp(-pow(z, 2) / 2) / sqrt(2 * PI),
         sum = 0,
         denominator = 1,
         result;
  for (int i = 1; i <= 100; i += 2)
  {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }
  result = 0.5 + phi * sum;
  return result;
}
