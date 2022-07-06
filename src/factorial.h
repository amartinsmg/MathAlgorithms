#include <assert.h>

long long factorial(int num)
{
  assert(num >= 0);
  long long result = 1;
  for (int i = 1; i <= num; i++)
    result *= i;
  return result;
}


double factoriallf(int num)
{
  assert(num >= 0);
  double result = 1;
  for (int i = 1; i <= num; i++)
    result *= i;
  return result;
}
