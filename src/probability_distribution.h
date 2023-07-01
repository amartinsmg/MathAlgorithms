#include <assert.h>
#include <math.h>
#include "combinatorics.h"

/**
  @brief Calculate the binomial coefficient.
  @param trials The number of trials.
  @param success_prob The success probability.
  @param success The number of successful outcomes.
  @return The binomial coefficient.
  @pre trials must be greater than 0, success must be greater than or equal to 0,
  success_prob must be between 0 and 1 (inclusive).
*/

double binominal(int trials, double success_prob, int success)
{
  double result;
  assert(trials > 0 && success >= 0 && success_prob >= 0 && success_prob <= 1);
  result = combinationlf(trials, success) *
           pow(success_prob, success) *
           pow((1 - success_prob), (trials - success));
  return result;
}

/**
  @brief Calculate the Poisson probability.
  @param mean The mean value.
  @param x The number of occurrences.
  @return The Poisson probability.
*/

double poisson(double mean, unsigned x)
{
  double result;
  result = exp(-mean) * pow(mean, x) / factoriallf(x);
  return result;
}

/**
  @brief Calculate the cumulative distribution function (CDF) of a Gaussian distribution.
  @param mean The mean value of the Gaussian distribution.
  @param standardDev The standard deviation of the Gaussian distribution.
  @param x The input value.
  @return The cumulative distribution function (CDF) value.
  @pre standardDev must be greater than 0.
*/

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
