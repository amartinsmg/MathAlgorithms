#include <math.h>

double simpleInterest(double principal, double rate, double time)
{
  double result = principal * (1 + rate * time);
  return result;
}

double compoundInterest(double principal, double rate, double time)
{
  double result = principal * pow((1 + rate), time);
  return result;
}
