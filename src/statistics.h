#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include "include/sort.h"
#include "percentage.h"
#include "basic_operations.h"

double mean(double *values, unsigned length)
{
  double sum = 0,
         result;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    sum += values[i];
  result = sum / length;
  return result;
}

double weightedMean(double **valuesWeightsPairs, unsigned length)
{
  double result, value, weight, sum = 0,
                                weightSum = 0;
  unsigned i;
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

double trimmedMean(double *values, unsigned lenght, double trimmedMeanPercentage)
{
  unsigned nElementsToTrim = (unsigned)round(nPercentOfX(lenght, trimmedMeanPercentage));
  assert(2 * nElementsToTrim < lenght);
  values = sort(values, lenght);
  values += nElementsToTrim;
  lenght -= 2 * nElementsToTrim;
  return mean(values, lenght);
}

double geometricMean(double *values, unsigned length)
{
  double product = 1,
         result;
  unsigned i;
  bool noNegatives, noPositives;
  assert(length > 0);
  i = 0;
  do
  {
    noNegatives = values[i] >= 0;
  } while (noNegatives && ++i < length);
  i = 0;
  do
  {
    noPositives = values[i] <= 0;
  } while (noPositives && ++i < length);
  assert(noNegatives || noPositives);
  for (i = 0; i < length; i++)
    product *= values[i];
  result = nthRoot(product, length);
  return result;
}

double harmonicMean(double *values, unsigned length)
{
  double sum = 0,
         result;
  unsigned i;
  bool allPositives;
  assert(length > 0);
  i = 0;
  do
  {
    allPositives = values[i] > 0;
  } while (allPositives && ++i < length);
  assert(allPositives);
  for (i = 0; i < length; i++)
    sum += 1 / values[i];
  assert(sum != 0);
  result = length / sum;
  return result;
}

double median(double *values, unsigned length)
{
  double result,
      *sortedValues = sort(values, length);
  assert(length > 0);
  if (length % 2)
    result = sortedValues[length / 2];
  else
    result = (sortedValues[length / 2 - 1] + sortedValues[length / 2]) / 2;
  return result;
}

double *mode(double *values, unsigned length, unsigned *ptrNOfModes)
{
  double *result, *sortedValues, **frequency;
  unsigned i, min = __UINT32_MAX__,
              max = 0,
              resultLenght = 0,
              frequencyLength = 0;
  assert(length > 0);
  result = NULL;
  sortedValues = sort(values, length);
  frequency = (double **)malloc(sizeof(*frequency) * length);
  for (i = 0; i < length; i++)
    frequency[i] = (double *)calloc(sizeof(**frequency), 2);
  frequency[frequencyLength++][0] = sortedValues[0];
  for (i = 0; i < length; i++)
  {
    if (sortedValues[i] == frequency[frequencyLength - 1][0])
      frequency[frequencyLength - 1][1] += 1;
    else
    {
      frequency[frequencyLength][0] = sortedValues[i];
      frequency[frequencyLength++][1] += 1;
    }
  }
  for (i = 0; i < frequencyLength; i++)
  {
    min = frequency[i][1] < min ? frequency[i][1] : min;
    max = frequency[i][1] > max ? frequency[i][1] : max;
  }
  *ptrNOfModes = 0;
  if (min < max)
  {
    for (i = 0; i < frequencyLength; i++)
    {
      if (frequency[i][1] == max)
      {
        result = (double *)realloc(result, sizeof(*result) * ++(*ptrNOfModes));
        result[resultLenght++] = frequency[i][0];
      }
    }
  }
  return result;
}

double min(double *values, unsigned length)
{
  double result = __DBL_MAX__;
  unsigned i;
  for (i = 0; i < length; i++)
    result = values[i] < result ? values[i] : result;
  return result;
}

double max(double *values, unsigned length)
{
  double result = -__DBL_MAX__;
  unsigned i;
  for (i = 0; i < length; i++)
    result = values[i] > result ? values[i] : result;
  return result;
}

double range(double *values, unsigned length)
{
  double minValue = min(values, length),
         maxValue = max(values, length),
         result = maxValue - minValue;
  return result;
}

double midrange(double *values, unsigned length)
{
  double result = range(values, length) / 2;
  return result;
}

double variance(double *values, unsigned length)
{
  double mu = mean(values, length),
         sum = 0,
         result;
  unsigned i;
  for (i = 0; i < length; i++)
    sum += pow((values[i] - mu), 2);
  result = sum / length;
  return result;
}

double standardDeviation(double *values, unsigned length)
{
  double result = sqrt(variance(values, length));
  return result;
}

double sampleVariance(double *values, unsigned length)
{
  double mu = mean(values, length),
         sum = 0,
         result;
  unsigned i;
  assert(length != 1);
  for (i = 0; i < length; i++)
    sum += pow((values[i] - mu), 2);
  result = sum / (length - 1);
  return result;
}

double sampleStandardDeviation(double *values, unsigned length)
{
  double result = sqrt(sampleVariance(values, length));
  return result;
}
