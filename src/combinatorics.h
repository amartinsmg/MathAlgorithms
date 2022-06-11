#include "./factorial.h"

long long permutation(unsigned n)
{
  long long result = factorial(n);
  return result;
}

long long cyclePermutation(unsigned n)
{
  long long result = factorial(n - 1);
  return result;
}

long long arrangement(unsigned n, unsigned p)
{
  long long result = factorial(n) / factorial(n - p);
  return result;
}

long long combination(unsigned n, unsigned p)
{
  long long result = factorial(n) / (factorial(p) * factorial(n - p));
  return result;
}
