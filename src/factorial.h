#include <assert.h>

#ifndef FACTORIAL_H
#define FACTORIAL_H

/**
  @brief Calculate the factorial of a number.
  @param num The number for which factorial is to be calculated.
  @return The factorial of the number.
  @pre num must be a non-negative number.
  @note This function is suitable for numbers up to 20. For numbers > 20 use the functions factoriallf() that use double precision
  float to store the result, allowing numbers grether than 9223372036854776000 to be represented using exponential form.
 */

long long factorial(int num)
{
  long long result = 1;
  int i;
  assert(num >= 0);
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

/**
  @brief Calculate the factorial of a number using double precision.
  @param num The number for which factorial is to be calculated.
  @return The factorial of the number.
  @pre num must be a non-negative number (double precision).
 */

double factoriallf(int num)
{
  double result = 1;
  int i;
  assert(num >= 0);
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

#endif /* FACTORIAL_H */
