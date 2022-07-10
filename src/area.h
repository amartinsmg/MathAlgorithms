#include <assert.h>
#include <math.h>
#include "trigonometry.h"

#define PI 3.141592653589793

double squareArea(double side)
{
  assert(side > 0);
  double area = pow(side, 2);
  return area;
}

double retangleArea(double width, double length)
{
  assert(width > 0 && length > 0);
  double area = width * length;
  return area;
}

double regularPolygonArea(double side, int nOfSides)
{
  assert(side > 0);
  double apothen = side / (2 * tan(PI / nOfSides)),
         perimeter = side * nOfSides,
         area = perimeter * apothen / 2;
  return area;
}

double triangleBaseHeightArea(double base, double height)
{
  assert(base > 0 && height > 0);
  double area = base * height / 2;
  return area;
}

double triangleABGamaArea(double a, double b, double gama)
{
  assert(a > 0 && b > 0);
  double area = a * b * sin(gama) / 2;
  return area;
}

double triangleABCArea(double a, double b, double c)
{
  assert(a > 0 && b > 0 && c > 0);
  double s = (a + b + c) / 2,
         area = sqrt(s * (s - a) * (s - b) * (s - c));
  return area;
}

double parallelogramArea(double base, double height)
{
  assert(base > 0 && height > 0);
  double area = base * height;
  return area;
}

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  assert(largerBase > 0 && smallerBase > 0 && height > 0);
  double area = (largerBase + smallerBase) * height / 2;
  return area;
}

double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  assert(largerDiagonal > 0 && smallerDiagonal > 0);
  double area = largerDiagonal * smallerDiagonal / 2;
  return area;
}

double circleArea(double radius)
{
  assert(radius > 0);
  double area = PI * pow(radius, 2);
  return area;
}

double circularSectorAngleArea(double theta, double radius)
{
  assert(radius > 0);
  double area = theta * pow(radius, 2) / 2;
  return area;
}

double circulaSectorArcArea(double arc, double radius)
{
  assert(radius > 0 && arc > 0);
  double area = arc * radius / 2;
  return area;
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  assert(semiMajorAxis > 0 && semiMinorAxis > 0);
  double area = PI * semiMajorAxis * semiMinorAxis;
  return area;
}

double cubeArea(double side)
{
  assert(side > 0);
  double area = 6 * pow(side, 2);
  return area;
}

double cuboidArea(double width, double length, double height)
{
  assert(width > 0 && length > 0 && height > 0);
  double area = 2 * ((width * length) + (length * height) + (width * height));
  return area;
}

double prismArea(double baseArea, double basePerimeter, double height)
{
  assert(baseArea > 0 && basePerimeter > 0 && height > 0);
  double result = 2 * baseArea + basePerimeter * height;
  return result;
}

double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides;
  return prismArea(baseArea, basePerimeter, height);
}

double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  assert(baseArea > 0 && basePerimeter > 0 && slantHeight > 0);
  double result = baseArea + basePerimeter * slantHeight / 2;
  return result;
}

double regularPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides,
         apothen = baseSide / (2 * tan(PI / nOfBaseSides)),
         slantHeight = hypotenusePythagorean(apothen, heigth);
  return pyramidArea(baseArea, basePerimeter, slantHeight);
}

double sphereArea(double radius)
{
  assert(radius > 0);
  double area = 4 * PI * pow(radius, 2);
  return area;
}

double cylinderArea(double baseRadius, double height)
{
  assert(baseRadius > 0 && height > 0);
  double area = 2 * PI * baseRadius * (baseRadius + height);
  return area;
}

double coneArea(double baseRadius, double height)
{
  assert(baseRadius > 0 && height > 0);
  double area = circleArea(baseRadius) + PI * baseRadius * hypotenusePythagorean(height, baseRadius);
  return area;
}
