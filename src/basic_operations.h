#include <assert.h>
#include <math.h>

#ifndef LOGARITHM
#define LOGARITHM

/**
  @brief Calculate the logarithm of a number with a given base.
  @param num The number for which the logarithm will be calculated.
  @param base The base of the logarithm.
  @return The logarithm of the number with the given base.
*/

double logarithm(double num, double base)
{
  double result = log(num) / log(base);
  return result;
}

#endif /* LOGARITHM */

#ifndef NTH_ROOT
#define NTH_ROOT

/**
  @brief Calculate the nth root of a radicand.
  @param radicand The number to take the nth root of.
  @param degree The degree of the root.
  @return The nth root of the radicand.
*/

double nthRoot(double radicand, double degree)
{
  double result;
  assert(degree != 0);
  result = pow(radicand, (1 / degree));
  return result;
}

#endif /* NTH_ROOT */

#ifndef ABS_FLOAT
#define ABS_FLOAT

/**
  @brief Calculate the absolute value of a number.
  @param num The number for which the absolute value will be calculated.
  @return The absolute value of the number.
*/

double absf(double num)
{
  return (num >= 0) ? num : -num;
}

#endif /* ABS_FLOAT */

#ifndef ROUND_TO
#define ROUND_TO

/**
  @brief Round a number to a specified number of decimal places.
  @param num The number to be rounded.
  @param decimalPlaces The number of decimal places to round to.
  @return The rounded number.
*/

double roundTo(double num, unsigned decimalPlaces)
{
  double result, base10 = pow(10, decimalPlaces);
  result = round(num * base10) / base10;
  return result;
}

#endif /* ROUND_TO */
