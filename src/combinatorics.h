#include "factorial.h"

#ifndef COMBINATORICS_H
#define COMBINATORICS_H

/**
  @note The functions permutation(), cyclepermutation(), arrangement()  and combination() work well for numbers <= 20, for numbers > 20
  use the functions permutationlf(), cyclepermutationlf(), arrangementlf() and combinationlf() that use double precision float to store
  the result, allowing numbers grether than 9223372036854776000 to be represented using exponential form.
*/

/**
 * @brief Calculate the cycle permutation of a number.
 *
 * @param num The number for which cycle permutation is to be calculated.
 *
 * @return The permutation of the number.
 */

long long permutation(int num)
{
  if (num < 0)
    return NAN;
  long long result;
  result = factorial(num);
  return result;
}

/**
 * @brief Calculate the cycle permutation of a number.
 *
 * @param num The number for which cycle permutation is to be calculated.
 *
 * @return The cycle permutation of the number.
 */

long long cyclePermutation(int num)
{
  if (num < 1)
    return NAN;
  long long result;
  result = factorial(num - 1);
  return result;
}

/**
 * @brief Calculate the arrangement of selecting 'selected' items from 'total' items.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The arrangement of selecting 'selected' items from 'total' items.
 */

long long arrangement(int total, int selected)
{
  if (total <= 0 || selected < 0 || selected > total)
    return NAN;
  long long result;
  result = factorial(total) / factorial(total - selected);
  return result;
}

/**
 * @brief Calculate the combination of selecting 'selected' items from 'total' items.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The combination of selecting 'selected' items from 'total' items.
 */

long long combination(int total, int selected)
{
  if (total <= 0 || selected < 0 || selected > total)
    return NAN;
  long long result;
  result = factorial(total) / (factorial(selected) * factorial(total - selected));
  return result;
}

/**
 * @brief Calculate the permutation of a number using double precision.
 *
 * @param num The number for which permutation is to be calculated.
 *
 * @return The permutation of the number (double precision).
 */

double permutationlf(int num)
{
  if (num < 0)
    return NAN;
  double result;
  result = factoriallf(num);
  return result;
}

/**
 * @brief Calculate the cycle permutation of a number using double precision.
 *
 * @param num The number for which permutation is to be calculated.
 *
 * @return The cycle permutation of the number (double precision).
 */

double cyclePermutationlf(int num)
{
  if (num < 1)
    return NAN;
  double result;
  result = factoriallf(num - 1);
  return result;
}

/**
 * @brief Calculate the arrangement of selecting 'selected' items from 'total' items using double precision.
 *
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 *
 * @return The arrangement of selecting 'selected' items from 'total' items (double precision).
 */

double arrangementlf(int total, int selected)
{
  if (total <= 0 || selected < 0 || selected > total)
    return NAN;
  double result;
  result = factoriallf(total) / factoriallf(total - selected);
  return result;
}

/**
 * @brief Calculate the combination of selecting 'selected' items from 'total' items using double precision.
 * 
 * @param total The total number of items.
 * @param selected The number of items to be selected.
 * 
 * @return The combination of selecting 'selected' items from 'total' items (double precision).
 */

double combinationlf(int total, int selected)
{
  if (total <= 0 || selected < 0 || selected > total)
    return NAN;
  double result;
  result = factoriallf(total) / (factoriallf(selected) * factoriallf(total - selected));
  return result;
}

#endif /* COMBINATORICS_H */
