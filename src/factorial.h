#include <assert.h>

double factorial(int num)
{
  assert(num >= 0);
  double result = 1;
  for (int i = 1; i <= num; i++)
    result *= i;
  return result;
}