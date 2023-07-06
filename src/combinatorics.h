#include <assert.h>
#include "factorial.h"

#ifndef COMBINATORICS_H
#define COMBINATORICS_H

/**
  @note The functions permutation(), cyclepermutation(), arrangement()  and combination() work well for numbers <= 20, for numbers > 20
  use the functions permutationlf(), cyclepermutationlf(), arrangementlf() and combinationlf() that use double precision float to store
  the result, allowing numbers grether than 9223372036854776000 to be represented using exponential form.
*/

/**
  @brief Calculate the cycle permutation of a number.
  @param num The number for which cycle permutation is to be calculated.
  @return The permutation of the number.
  @pre num must be greater than 0.
*/

long long permutation(int num)
{
  long long result;
  assert(num > 0);
  result = factorial(num);
  return result;
}

/**
  @brief Calculate the cycle permutation of a number.
  @param num The number for which cycle permutation is to be calculated.
  @return The cycle permutation of the number.
  @pre num must be greater than 0.
*/

long long cyclePermutation(int num)
{
  long long result;
  assert(num > 0);
  result = factorial(num - 1);
  return result;
}

/**
  @brief Calculate the arrangement of selecting 'selected' items from 'total' items.
  @param total The total number of items.
  @param selected The number of items to be selected.
  @return The arrangement of selecting 'selected' items from 'total' items.
  @pre total must be greater than 0, selected must be greater than or equal to 0.
*/

long long arrangement(int total, int selected)
{
  long long result;
  assert(total > 0 && selected >= 0);
  result = factorial(total) / factorial(total - selected);
  return result;
}

/**
  @brief Calculate the combination of selecting 'selected' items from 'total' items.
  @param total The total number of items.
  @param selected The number of items to be selected.
  @return The combination of selecting 'selected' items from 'total' items.
  @pre total must be greater than 0, selected must be greater than or equal to 0, selected must be less than or equal to total.
*/

long long combination(int total, int selected)
{
  long long result;
  assert(total > 0 && selected >= 0 && selected <= total);
  result = factorial(total) / (factorial(selected) * factorial(total - selected));
  return result;
}

/**
  @brief Calculate the permutation of a number using double precision.
  @param num The number for which permutation is to be calculated.
  @return The permutation of the number (double precision).
  @pre num must be greater than 0.
*/

double permutationlf(int num)
{
  double result;
  assert(num > 0);
  result = factoriallf(num);
  return result;
}

/**
  @brief Calculate the cycle permutation of a number using double precision.
  @param num The number for which permutation is to be calculated.
  @return The cycle permutation of the number (double precision).
  @pre num must be greater than 0.
*/

double cyclePermutationlf(int num)
{
  double result;
  assert(num > 0);
  result = factoriallf(num - 1);
  return result;
}

/**
  @brief Calculate the arrangement of selecting 'selected' items from 'total' items using double precision.
  @param total The total number of items.
  @param selected The number of items to be selected.
  @return The arrangement of selecting 'selected' items from 'total' items (double precision).
  @pre total must be greater than 0, selected must be greater than or equal to 0.
*/

double arrangementlf(int total, int selected)
{
  double result;
  assert(total > 0 && selected >= 0);
  result = factoriallf(total) / factoriallf(total - selected);
  return result;
}

/**
  @brief Calculate the combination of selecting 'selected' items from 'total' items using double precision.
  @param total The total number of items.
  @param selected The number of items to be selected.
  @return The combination of selecting 'selected' items from 'total' items (double precision).
  @pre total must be greater than 0, selected must be greater than or equal to 0, selected must be less than or equal to total.
*/

double combinationlf(int total, int selected)
{
  double result;
  assert(total > 0 && selected >= 0 && selected <= total);
  result = factoriallf(total) / (factoriallf(selected) * factoriallf(total - selected));
  return result;
}

#endif /* COMBINATORICS_H */
