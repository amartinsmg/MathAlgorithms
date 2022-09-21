#include <stdlib.h>

double *sort(double *values, unsigned length)
{
  double num, *result = (double *)malloc(sizeof(*result) * length);
  unsigned i, j;
  result[0] = values[0];
  for (i = 1; i < length; i++)
  {
    result[i] = num = values[i];
    j = i;
    while (--j >= 0 && num < result[j])
    {
      result[j + 1] = result[j];
      result[j] = num;
    }
  }
  return result;
}
