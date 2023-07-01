#include <stdlib.h>

double *sort(double *arr, int length)
{
  double num, *result = (double *)malloc(sizeof(*result) * length);
  int i, j;
  result[0] = arr[0];
  for (i = 1; i < length; i++)
  {
    result[i] = num = arr[i];
    j = i;
    while (--j >= 0 && num < result[j])
    {
      result[j + 1] = result[j];
      result[j] = num;
    }
  }
  return result;
}
