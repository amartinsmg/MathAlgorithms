#include <assert.h>
#include <math.h>
#include "combinatorics.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#ifndef PROBABILITY_DISTRIBUTION_H
#define PROBABILITY_DISTRIBUTION_H

/**
  @brief Calculate the binomial coefficient.
  @param trials The number of trials.
  @param successProb The success probability.
  @param success The number of successful outcomes.
  @return The binomial coefficient.
  @pre trials must be greater than 0, success must be greater than or equal to 0,
 successProb must be between 0 and 1 (inclusive).
*/

double binominal(int trials, double successProb, int success)
{
  double result;
  assert(trials > 0 && success >= 0 && successProb >= 0 && successProb <= 1);
  result = combinationlf(trials, success) *
           pow(successProb, success) *
           pow((1 - successProb), (trials - success));
  return result;
}

/**
  @brief Calculate the Poisson probability.
  @param lambda The mean value.
  @param x The number of occurrences.
  @return The Poisson probability.
*/

double poisson(double lambda, unsigned x)
{
  double result;
  result = exp(-lambda) * pow(lambda, x) / factoriallf(x);
  return result;
}

/**
  @brief Calculate the cumulative distribution function (CDF) of a Gaussian distribution.
  @param mu The mean value of the Gaussian distribution.
  @param standardDev The standard deviation of the Gaussian distribution.
  @param x The input value.
  @return The cumulative distribution function (CDF) value.
  @pre standardDev must be greater than 0.
*/

double gaussianCDF(double mu, double standadDev, double x)
{
  double phi, result, z,
      denominator = 1,
      sum = 0;
  int i;
  assert(standadDev > 0);
  z = (x - mu) / standadDev;
  phi = exp(-pow(z, 2) / 2) / sqrt(2 * M_PI);
  for (i = 1; i <= 100; i += 2)
  {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }
  result = 0.5 + phi * sum;
  return result;
}

#endif /* PROBABILITY_DISTRIBUTION_H */
