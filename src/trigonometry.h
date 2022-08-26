#include <assert.h>
#include <math.h>

double hypotenuse(double sideA, double sideB)
{
  double result;
  assert(sideA > 0 && sideB > 0);
  result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

double sideRetTriangle(double hypotenuse, double sideA)
{
  double result;
  assert(sideA > 0 && hypotenuse > 0);
  result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

double sideTriangleLC(double sideA, double sideB, double oppositeAngle)
{
  double result;
  assert(sideA > 0 && sideB > 0 && oppositeAngle > 0);
  result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(oppositeAngle)));
  return result;
}

double angleTriangleLC(double oppositeSide, double sideA, double sideB)
{
  double result;
  assert(sideA > 0 && sideB > 0 && oppositeSide > 0);
  result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) / (2 * sideA * sideB));
  return result;
}

double sideTriangleLS(double oppositeAngle, double sideA, double oppositeAngle2A)
{
  double result;
  assert(sideA > 0 && oppositeAngle > 0 && oppositeAngle2A > 0);
  result = sideA / sin(oppositeAngle2A) * sin(oppositeAngle);
  return result;
}

double angleTriangleLS(double oppositeSide, double sideA, double oppositeAngle2A)
{
  double result;
  assert(oppositeSide > 0 && sideA > 0 && oppositeAngle2A > 0);
  result = asin(oppositeSide / (sideA / sin(oppositeAngle2A)));
  return result;
}
