#include <assert.h>
#include "factorial.h"

long long permutation(int n)
{
  assert(n > 0);
  long long result = factorial(n);
  return result;
}

long long cyclePermutation(int n)
{
  assert(n > 0);
  long long result = factorial(n - 1);
  return result;
}

long long arrangement(int n, int p)
{
  assert(n > 0 && p >= 0);
  long long result = factorial(n) / factorial(n - p);
  return result;
}

long long combination(int n, int p)
{
  assert(n > 0 && p >= 0 && p <= n);
  long long result = factorial(n) / (factorial(p) * factorial(n - p));
  return result;
}

double permutationlf(int n)
{
  assert(n > 0);
  double result = factoriallf(n);
  return result;
}

double cyclePermutationlf(int n)
{
  assert(n > 0);
  double result = factoriallf(n - 1);
  return result;
}

double arrangementlf(int n, int p)
{
  assert(n > 0 && p >= 0);
  double result = factoriallf(n) / factoriallf(n - p);
  return result;
}

double combinationlf(int n, int p)
{
  assert(n > 0 && p >= 0 && p <= n);
  double result = factoriallf(n) / (factoriallf(p) * factoriallf(n - p));
  return result;
}
