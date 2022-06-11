#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589793

double squareArea(double side)
{
  if (side < 0)
    exit(1);
  double area = pow(side, 2);
  return area;
}

double retangleArea(double width, double length)
{
  if (width < 0 || length < 0)
    exit(1);
  double area = width * length;
  return area;
}

double regularPoligonArea(double side, unsigned nOfSides)
{
  if (side < 0)
    exit(1);
  double apothen = side / (2 * tan(180 / nOfSides)),
         perimeter = side * nOfSides,
         area = perimeter * apothen / 2;
  return area;
}

double triangleBaseHeightArea(double base, double height)
{
  if (base < 0 || height < 0)
    exit(1);
  double area = base * height / 2;
  return area;
}

double triangleABGamaArea(double a, double b, double gama)
{
  if (a < 0 || b < 0)
    exit(1);
  double area = a * b * sin(gama) / 2;
  return area;
}

double triangleABCArea(double a, double b, double c)
{
  if (a < 0 || b < 0 || c < 0)
    exit(1);
  double s = (a + b + c) / 2,
         area = sqrt(s * (s - a) * (s - b) * (s - c));
  return area;
}

double parallelogramArea(double base, double height)
{
  if (base < 0 || height < 0)
    exit(1);
  double area = base * height;
  return area;
}

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  if (largerBase < 0 || smallerBase < 0 || height < 0)
    exit(1);
  double area = (largerBase + smallerBase) * height / 2;
  return area;
}

double rhombus(double largerDiagonal, double smallerDiagonal)
{
  if (largerDiagonal < 0 || smallerDiagonal < 0)
    exit(1);
  double area = largerDiagonal * smallerDiagonal / 2;
  return area;
}

double circleArea(double radius)
{
  if (radius < 0)
    exit(1);
  double area = PI * pow(radius, 2);
  return area;
}

double circularSectorAngleArea(double theta, double radius)
{
  if (radius < 0)
    exit(1);
  double area = theta * pow(radius, 2) / 2;
  return area;
}

double circulaSectorArcArea(double arc, double radius)
{
  if (radius < 0 || arc < 0)
    exit(1);
  double area = arc * radius / 2;
  return area;
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  if (semiMajorAxis < 0 || semiMinorAxis < 0)
    exit(1);
  double area = PI * semiMajorAxis * semiMinorAxis;
  return area;
}

double sphereArea(double radius)
{
  if (radius < 0)
    exit(1);
  double area = 4 * PI * pow(radius, 2);
  return area;
}

double cubeArea(double side)
{
  if (side < 0)
    exit(1);
  double area = 6 * pow(side, 2);
  return area;
}

double cuboidArea(double width, double length, double height)
{
  if (width < 0 || length < 0 || height < 0)
    exit(1);
  double area = 2 * ((width * length) + (length * height) + (width * height));
  return area;
}

double cylinderArea(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    exit(1);
  double area = 2 * PI * baseRadius * (baseRadius + height);
  return area;
}

double coneArea(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    exit(1);
  double area = PI * baseRadius * (baseRadius + height);
  return area;
}
