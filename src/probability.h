#include <math.h>
#include "./factorial.h"
#include "./combinatorics.h"

#define PI 3.141592653589793

double binominal(unsigned n, unsigned x, double p)
{
  double probability = combination(n, x) * pow(p, x) * pow((1 - p), (n - x));
  return probability;
}

double poisson(double lambda, unsigned k)
{
  double probability = exp(-lambda) * pow(lambda, k) / factorial(k);
  return probability;
}

double gaussianCDF(double x, double mu, double sigma)
{
  double z = (x - mu) / sigma,
         phi = exp(-pow(z, 2) / 2) / sqrt(2 * PI),
         sum = 0,
         denon = 1;
  for (int i = 1; i <= 31; i += 2)
  {
    denon *= i;
    sum += pow(z, i) / denon;
  }
  double probability = 1 / 2 + phi * sum;
  return probability;
}
