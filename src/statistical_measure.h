#include <assert.h>
#include <math.h>
#include "basic_operations.h"

double mean(double *values, int length)
{
  double sum = 0,
         result;
  int i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    sum += values[i];
  result = sum / length;
  return result;
}

double weightedMean(double **valuesWeightsPairs, int length)
{
  double result, value, weight, sum = 0,
                                weightSum = 0;
  int i;
  assert(length > 0);
  for (i = 0; i < length; i++)
  {
    value = valuesWeightsPairs[i][0];
    weight = valuesWeightsPairs[i][1];
    assert(weight > 0);
    sum += value * weight;
    weightSum += weight;
  }
  result = sum / weightSum;
  return result;
}

double geometricMean(double *values, int length)
{
  double product = 1,
         result;
  int i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    product *= values[i];
  result = nthRoot(product, length);
  return result;
}

double harmonicMean(double *values, int length)
{
  double sum = 0,
         result;
  int i;
  assert(length > 0);
  for (i = 0; i < length; i++)
  {
    assert(values[i]);
    sum += 1 / values[i];
  }
  assert(sum != 0);
  result = length / sum;
  return result;
}

double min(double *values, int length)
{
  double result = __DBL_MAX__;
  int i;
  for (i = 0; i < length; i++)
    result = values[i] < result ? values[i] : result;
  return result;
}

double max(double *values, int length)
{
  double result = -__DBL_MAX__;
  int i;
  for (i = 0; i < length; i++)
    result = values[i] > result ? values[i] : result;
  return result;
}

double rangeStatistics(double *values, int length)
{
  double minValue = min(values, length),
  maxValue = max(values, length),
  result= maxValue - minValue;
  return result;
}

double variance(double *values, int length)
{
  double mu = mean(values, length),
         sum = 0,
         result;
  int i;
  for (i = 0; i < length; i++)
    sum += pow((values[i] - mu), 2);
  result = sum / length;
  return result;
}

double standardDeviation(double *values, int length)
{
  double result = sqrt(variance(values, length));
  return result;
}

double sampleVariance(double *values, int length)
{
  double mu = mean(values, length),
         sum = 0,
         result;
  int i;
  assert(length != 1);
  for (i = 0; i < length; i++)
    sum += pow((values[i] - mu), 2);
  result = sum / (length - 1);
  return result;
}

double sampleStandardDeviation(double *values, int length)
{
  double result = sqrt(sampleVariance(values, length));
  return result;
}
