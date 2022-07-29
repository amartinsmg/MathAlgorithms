#include <assert.h>
#include <math.h>

double hypotenusePythagorean(double sideA, double sideB)
{
  assert(sideA > 0 && sideB > 0);
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

double sideByPythagorean(double hypotenuse, double sideA)
{
  assert(sideA > 0 && hypotenuse > 0);
  double result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

double sideByLawOfCos(double sideA, double sideB, double oppositeAngle)
{
  assert(sideA > 0 && sideB > 0 && oppositeAngle > 0);
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(oppositeAngle)));
  return result;
}

double angleByLawOfCos(double oppositeSide, double sideA, double sideB)
{
  assert(sideA > 0 && sideB > 0 && oppositeSide > 0);
  double result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) / (2 * sideA * sideB));
  return result;
}

double sideByLawOfSin(double oppositeAngle, double sideA, double oppositeAngle2A)
{
  assert(sideA > 0 && oppositeAngle > 0 && oppositeAngle2A > 0);
  double result = sideA / sin(oppositeAngle2A) * sin(oppositeAngle);
  return result;
}

double angleByLawOfSin(double oppositeSide, double sideA, double oppositeAngle2A)
{
  assert(oppositeSide > 0 && sideA > 0 && oppositeAngle2A > 0);
  double result = asin(oppositeSide / (sideA / sin(oppositeAngle2A)));
  return result;
}
