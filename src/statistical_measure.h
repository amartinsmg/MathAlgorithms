#include <math.h>

double average(double *values, int length)
{
  double sum = 0,
         result;
  for (int i = 0; i < length; i++)
    sum += values[i];
  result = sum / length;
  return result;
}

double variance(double *values, int length)
{
  double mu = average(values, length),
         sum = 0,
         result;
  for (int i = 0; i < length; i++)
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
  double mu = average(values, length),
         sum = 0,
         result;
  for (int i = 0; i < length; i++)
    sum += pow((values[i] - mu), 2);
  result = sum / (length - 1);
  return result;
}

double sampleStandardDeviation(double *values, int length)
{
  double result = sqrt(sampleVariance(values, length));
  return result;
}
