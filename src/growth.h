#include <math.h>

double simpleGrowth(double initial, double rate, double interval)
{
  double result = initial * (1 + rate * interval);
  return result;
}

double simpleGrowthRate(double initial, double final, double interval)
{
  double result = (final / initial - 1) / interval;
  return result;
}

double compoundedGrowth(double initial, double rate, double interval)
{
  double result = initial * pow((1 + rate), interval);
  return result;
}

double compoundedGrowthRate(double initial, double final, double interval)
{
  double result = pow((final / initial), (1 / interval));
  return result;
}
