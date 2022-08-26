#include <assert.h>
#include <math.h>
#include "trigonometry.h"

#define PI 3.141592653589793

double squareArea(double side)
{
  double result;
  assert(side > 0);
  result = pow(side, 2);
  return result;
}

double retangleArea(double width, double length)
{
  double result;
  assert(width > 0 && length > 0);
  result = width * length;
  return result;
}

double regPolygonArea(double side, int nOfSides)
{
  double apothen, perimeter, result;
  assert(side > 0 && nOfSides > 0);
  apothen = side / (2 * tan(PI / nOfSides));
  perimeter = side * nOfSides;
  result = perimeter * apothen / 2;
  return result;
}

double triangleA1(double base, double height)
{
  double result;
  assert(base > 0 && height > 0);
  result = base * height / 2;
  return result;
}

double triangleA2(double sideA, double sideB, double angleGama)
{
  double result;
  assert(sideA > 0 && sideB > 0 && angleGama > 0 && angleGama < PI);
  result = sideA * sideB * sin(angleGama) / 2;
  return result;
}

double triangleA3(double sideA, double sideB, double SideC)
{
  double result, s;
  assert(sideA > 0 && sideB > 0 && SideC > 0);
  s = (sideA + sideB + SideC) / 2;
  result = sqrt(s * (s - sideA) * (s - sideB) * (s - SideC));
  return result;
}

double parallelogramArea(double base, double height)
{
  double result;
  assert(base > 0 && height > 0);
  result = base * height;
  return result;
}

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  double result;
  assert(largerBase > 0 && smallerBase > 0 && height > 0);
  result = (largerBase + smallerBase) * height / 2;
  return result;
}

double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  double result;
  assert(largerDiagonal > 0 && smallerDiagonal > 0);
  result = largerDiagonal * smallerDiagonal / 2;
  return result;
}

double circleArea(double radius)
{
  double result;
  assert(radius > 0);
  result = PI * pow(radius, 2);
  return result;
}

double circularSecA1(double angle, double radius)
{
  double result;
  assert(radius > 0 && angle >= 0);
  result = angle * pow(radius, 2) / 2;
  return result;
}

double circulaSecA2(double arc, double radius)
{
  double result;
  assert(radius > 0 && arc >= 0);
  result = arc * radius / 2;
  return result;
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  double result;
  assert(semiMajorAxis > 0 && semiMinorAxis > 0);
  result = PI * semiMajorAxis * semiMinorAxis;
  return result;
}

double cubeArea(double side)
{
  double result;
  assert(side > 0);
  result = 6 * pow(side, 2);
  return result;
}

double cuboidArea(double width, double length, double height)
{
  double result;
  assert(width > 0 && length > 0 && height > 0);
  result = 2 * ((width * length) + (length * height) + (width * height));
  return result;
}

double prismArea(double baseArea, double basePerimeter, double height)
{
  double result;
  assert(baseArea > 0 && basePerimeter > 0 && height > 0);
  result = 2 * baseArea + basePerimeter * height;
  return result;
}

double regPrismArea(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides;
  return prismArea(baseArea, basePerimeter, height);
}

double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  double result;
  assert(baseArea > 0 && basePerimeter > 0 && slantHeight > 0);
  result = baseArea + basePerimeter * slantHeight / 2;
  return result;
}

double regPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  double baseArea = regPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides,
         apothen = baseSide / (2 * tan(PI / nOfBaseSides)),
         slantHeight = hypotenuse(apothen, heigth);
  return pyramidArea(baseArea, basePerimeter, slantHeight);
}

double sphereArea(double radius)
{
  double result;
  assert(radius > 0);
  result = 4 * PI * pow(radius, 2);
  return result;
}

double cylinderArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = 2 * PI * baseRadius * (baseRadius + height);
  return result;
}

double coneArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = circleArea(baseRadius) + PI * baseRadius * hypotenuse(height, baseRadius);
  return result;
}
