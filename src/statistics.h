#include <assert.h>
#include <math.h>
#include "include/sort.h"
#include "percentage.h"
#include "basic_operations.h"

#ifndef STATISTICS_H
#define STATISTICS_H

/**
  @brief Calculate the arithmetic mean of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated mean.
*/

double mean(double *arr, unsigned length)
{
  double result,
      sum = 0;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    sum += arr[i];
  result = sum / length;
  return result;
}

/**
  @brief Calculate the weighted mean of a set of values.
  @param valuesWeightsPairs The array of value-weight pairs. Each pair is represented
  as a double array with two elements: [value, weight].
  @param length The length of the valuesWeightsPairs array.
  @return The weighted mean of the arr.
*/

double weightedMean(double **valuesWeightsPairs, unsigned length)
{
  double result, value, weight,
      sum = 0,
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

/**
  @brief Calculate the trimmed mean of an array of values.
  @param arr The array of values.
  @param length The length of the arr array.
  @param trimmedMeanPercentage The percentage of elements to be trimmed from both ends.
  @return The trimmed mean of the arr.
*/

double trimmedMean(double *arr, unsigned lenght, double trimmedMeanPercentage)
{
  unsigned nElementsToTrim = (unsigned)round(nPercentOfX(lenght, trimmedMeanPercentage));
  assert(2 * nElementsToTrim < lenght);
  arr = sort(arr, lenght);
  arr += nElementsToTrim;
  lenght -= 2 * nElementsToTrim;
  return mean(arr, lenght);
}

/**
  @brief Calculate the geometric mean of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated geometric mean.
*/

double geometricMean(double *arr, unsigned length)
{
  double result,
      product = 1;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
  {
    assert(arr[i] >= 0);
    product *= arr[i];
  }
  result = nthRoot(product, length);
  return result;
}

/**
  @brief Calculate the harmonic mean of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated harmonic mean.
*/

double harmonicMean(double *arr, unsigned length)
{
  double result,
      sum = 0;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
  {
    assert(arr[i] > 0);
    sum += 1 / arr[i];
  }
  result = length / sum;
  return result;
}

/**
  @brief Calculate the median of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated median.
*/

double median(double *arr, unsigned length)
{
  double result,
      *sortedArr = sort(arr, length);
  assert(length > 0);
  if (length % 2)
    result = sortedArr[length / 2];
  else
    result = (sortedArr[length / 2 - 1] + sortedArr[length / 2]) / 2;
  return result;
}

/**
  @brief Calculate the mode(s) of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @param ptrNOfModes Pointer to store the number of modes found.
  @return An array containing the mode(s) of the input values.
  @note The number of modes is stored in ptrNOfModes.
*/

double *mode(double *arr, unsigned length, unsigned *ptrNOfModes)
{
  double **frequency, *result, *sortedArr;
  unsigned i,
      minFreq = __UINT32_MAX__,
      maxFreq = 0,
      resultLenght = 0,
      frequencyLength = 0;
  assert(length > 0);
  result = NULL;
  sortedArr = sort(arr, length);
  frequency = (double **)malloc(sizeof(*frequency) * length);
  for (i = 0; i < length; i++)
    frequency[i] = (double *)calloc(sizeof(**frequency), 2);
  frequency[frequencyLength++][0] = sortedArr[0];
  for (i = 0; i < length; i++)
    if (sortedArr[i] == frequency[frequencyLength - 1][0])
      frequency[frequencyLength - 1][1] += 1;
    else
    {
      frequency[frequencyLength][0] = sortedArr[i];
      frequency[frequencyLength++][1] += 1;
    }
  for (i = 0; i < frequencyLength; i++)
  {
    minFreq = frequency[i][1] < minFreq ? frequency[i][1] : minFreq;
    maxFreq = frequency[i][1] > maxFreq ? frequency[i][1] : maxFreq;
  }
  *ptrNOfModes = 0;
  if (minFreq < maxFreq)
    for (i = 0; i < frequencyLength; i++)
      if (frequency[i][1] == maxFreq)
      {
        result = (double *)realloc(result, sizeof(*result) * ++(*ptrNOfModes));
        result[resultLenght++] = frequency[i][0];
      }
  return result;
}

/**
  @brief Find the minimum value in an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The minimum value.
*/

double min(double *arr, unsigned length)
{
  double result = __DBL_MAX__;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result = arr[i] < result ? arr[i] : result;
  return result;
}

/**
  @brief Find the maximum value in an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The maximum value.
*/

double max(double *arr, unsigned length)
{
  double result = -__DBL_MAX__;
  unsigned i;
  assert(length > 0);
  for (i = 0; i < length; i++)
    result = arr[i] > result ? arr[i] : result;
  return result;
}

/**
  @brief Calculate the range of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated range.
*/

double range(double *arr, unsigned length)
{
  double minValue = min(arr, length),
         maxValue = max(arr, length),
         result = maxValue - minValue;
  return result;
}

/**
  @brief Calculate the midrange of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated midrange.
*/

double midrange(double *arr, unsigned length)
{
  double result = range(arr, length) / 2;
  return result;
}

/**
  @brief Calculate the variance of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated variance.
*/

double variance(double *arr, unsigned length)
{
  double mu = mean(arr, length),
         sum = 0,
         result;
  unsigned i;
  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);
  result = sum / length;
  return result;
}

/**
  @brief Calculate the standard deviation of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated standard deviation.
*/

double standardDeviation(double *arr, unsigned length)
{
  double result = sqrt(variance(arr, length));
  return result;
}

/**
  @brief Calculate the sample variance of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated sample variance.
*/

double sampleVariance(double *arr, unsigned length)
{
  double mu = mean(arr, length),
         sum = 0,
         result;
  unsigned i;
  assert(length != 1);
  for (i = 0; i < length; i++)
    sum += pow((arr[i] - mu), 2);
  result = sum / (length - 1);
  return result;
}

/**
  @brief Calculate the sample standard deviation of an array of values.
  @param arr The array of values.
  @param length The length of the array.
  @return The calculated sample standard deviation.
*/

double sampleStandardDeviation(double *arr, unsigned length)
{
  double result = sqrt(sampleVariance(arr, length));
  return result;
}

#endif /* STATISTICS_H */
