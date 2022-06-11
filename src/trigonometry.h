#include <math.h>

double findSideByPythagorean(double sideA, double sideB)
{
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

double findSideByLawOfCos(double sideA, double sideB, double angleGama)
{
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(angleGama)));
  return result;
}
