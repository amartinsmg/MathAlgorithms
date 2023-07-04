#include <assert.h>
#include <math.h>
#include "basic_operations.h"

/**
  @brief Calculate the value after simple growth.
  @param initial The initial value.
  @param rate The growth rate.
  @param interval The time interval.
  @return The calculated value after simple growth.
*/

double simpleGrowth(double initial, double rate, double interval)
{
  double result;
  assert(interval >= 0);
  result = initial * (1 + rate * interval);
  return result;
}

/**
  @brief Calculate the simple growth rate.
  @param initial The initial value.
  @param final The final value.
  @param interval The time interval.
  @return The calculated simple growth rate.
*/

double simpleGrowthRate(double initial, double final, double interval)
{
  double result;
  assert(initial != 0 && interval > 0);
  result = (final / initial - 1) / interval;
  return result;
}

/**
  @brief Calculate the value after compounded growth.
  @param initial The initial value.
  @param rate The growth rate.
  @param interval The time interval.
  @return The calculated value after compounded growth.
*/

double compoundedGrowth(double initial, double rate, double interval)
{
  double result;
  assert(interval >= 0);
  result = initial * pow((1 + rate), interval);
  return result;
}

/**
  @brief Calculate the compounded growth rate.
  @param initial The initial value.
  @param final The final value.
  @param interval The time interval.
  @return The calculated compounded growth rate.
*/

double compoundedGrowthRate(double initial, double final, double interval)
{
  double result;
  assert(initial != 0 && interval > 0);
  result = nthRoot((final / initial), interval) - 1;
  return result;
}
