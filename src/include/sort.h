#include <stdlib.h>

double *insertion_sort(double *values, int length)
{
  double num, *result = (double *)malloc(sizeof(*result) * length);
  int i, j;
  result[0] = values[0];
  for (i = 1; i < length; i++)
  {
    result[i] = num = values[i];
    for (j = i - 1; j >= 0; j--)
    {
      if (num < result[j])
      {
        result[j + 1] = result[j];
        result[j] = num;
      }
      else
        break;
    }
  }
  return result;
}
