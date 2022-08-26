#include <math.h>

double simpleGrowth(double initial, double rate, double interval)
{
  double result = initial * (1 + rate * interval);
  return result;
}

double simpleGrowthRate(double initial, double final, double interval)
{
  double result;
  assert(initial != 0 && interval != 0);
  result = (final / initial - 1) / interval;
  return result;
}

double compoundedGrowth(double initial, double rate, double interval)
{
  double result = initial * pow((1 + rate), interval);
  return result;
}

double compoundedGrowthRate(double initial, double final, double interval)
{
  double result;
  assert(initial != 0 && interval != 0);
  result = pow((final / initial), (1 / interval)) - 1;
  return result;
}
