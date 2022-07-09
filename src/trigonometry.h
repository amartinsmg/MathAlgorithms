#include <math.h>

double hypotenusePythagorean(double sideA, double sideB)
{
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

double sideByPythagorean(double hypotenuse, double sideA)
{
  double result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

double sideByLawOfCos(double sideA, double sideB, double oppositeAngle)
{
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(oppositeAngle)));
  return result;
}

double angleByLawOfCos(double oppositeSide, double sideA, double sideB)
{
  double result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) / (2 * sideA * sideB));
  return result;
}

double sideByLawOfSin(double oppositeAngle, double sideA, double oppositeAngle2A)
{
  double result = sideA / sin(oppositeAngle2A) * sin(oppositeAngle);
  return result;
}

double angleByLawOfSin(double oppositeSide, double sideA, double oppositeAngle2A)
{
  double result = asin(oppositeSide / (sideA / sin(oppositeAngle2A)));
  return result;
}
