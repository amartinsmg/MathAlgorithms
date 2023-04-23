#include <assert.h>

/**
  This function calculates the factorial of the given integer using a for loop.
  This function is suitable for numbers up to 20.
  @param num The integer for which to calculate the factorial.
  @return The factorial of the given integer as a long long value.
  @pre num must be a non-negative integer.
  @post The return value is the product of all positive integers less than or equal
  to num
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
  This function calculates the factorial of the given integer using a for loop.
  This function is suitable for numbers greater than 20. It uses a double precision
  float to store the result, allowing numbers greater than 9223372036854776000 to
  be represented using exponential form.
  @param num The integer for which to calculate the factorial.
  @return The factorial of the given integer as a double value.
  @pre num must be a non-negative integer.
  @post The return value is the product of all positive integers less than or equal
  to num.
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
