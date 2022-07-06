#include <assert.h>
#include "./factorial.h"

double permutation(int n)
{
  assert(n > 0);
  double result = factorial(n);
  return result;
}

double cyclePermutation(int n)
{
  assert(n > 0);
  double result = factorial(n - 1);
  return result;
}

double arrangement(int n, int p)
{
  assert(n > 0 && p >= 0);
  double result = factorial(n) / factorial(n - p);
  return result;
}

double combination(int n, int p)
{
  assert(n > 0 && p >= 0 && p <= n);
  double result = factorial(n) / (factorial(p) * factorial(n - p));
  return result;
}
