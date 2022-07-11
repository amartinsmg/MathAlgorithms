#include <assert.h>
#include "factorial.h"

/* The functions permutation(), cyclepermutation(), arrangement()
  and combination() work well for numbers <= 20, for numbers > 20
  use the functions permutationlf(), cyclepermutationlf(),
  arrangementlf() and combinationlf() that use double precision
  float to store the result, allowing numbers grether than
  9223372036854776000 to be represented using exponential form */

long long permutation(int num)
{
  assert(num > 0);
  long long result = factorial(num);
  return result;
}

long long cyclePermutation(int num)
{
  assert(num > 0);
  long long result = factorial(num - 1);
  return result;
}

long long arrangement(int total, int selected)
{
  assert(total > 0 && selected >= 0);
  long long result = factorial(total) / factorial(total - selected);
  return result;
}

long long combination(int total, int selected)
{
  assert(total > 0 && selected >= 0 && selected <= total);
  long long result = factorial(total) / (factorial(selected) * factorial(total - selected));
  return result;
}

double permutationlf(int num)
{
  assert(num > 0);
  double result = factoriallf(num);
  return result;
}

double cyclePermutationlf(int num)
{
  assert(num > 0);
  double result = factoriallf(num - 1);
  return result;
}

double arrangementlf(int total, int selected)
{
  assert(total > 0 && selected >= 0);
  double result = factoriallf(total) / factoriallf(total - selected);
  return result;
}

double combinationlf(int total, int selected)
{
  assert(total > 0 && selected >= 0 && selected <= total);
  double result = factoriallf(total) / (factoriallf(selected) * factoriallf(total - selected));
  return result;
}
