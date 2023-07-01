#include <assert.h>
#include <math.h>
#include "trigonometry.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/**
  @brief Calculate the area of a triangle given the base and height.
  @param base The length of the base of the triangle.
  @param height The height of the triangle.
  @return The area of the triangle.
*/

double triangleArea1(double base, double height)
{
  double result;
  assert(base > 0 && height > 0);
  result = base * height / 2;
  return result;
}

/**
  @brief Calculate the area of a triangle given two sides and an angle between them.
  @param sideA The length of side A of the triangle.
  @param sideB The length of side B of the triangle.
  @param angleGama The angle between sides A and B, in radians.
  @return The area of the triangle.
*/

double triangleArea2(double sideA, double sideB, double angleGama)
{
  double result;
  assert(sideA > 0 && sideB > 0 && angleGama > 0 && angleGama < M_PI);
  result = sideA * sideB * sin(angleGama) / 2;
  return result;
}

/**
  @brief Calculate the area of a triangle given three sides.
  @param sideA The length of side A of the triangle.
  @param sideB The length of side B of the triangle.
  @param sideC The length of side C of the triangle.
  @return The area of the triangle.
*/

double triangleArea3(double sideA, double sideB, double SideC)
{
  double result, s;
  assert(sideA > 0 && sideB > 0 && SideC > 0);
  s = (sideA + sideB + SideC) / 2;
  result = sqrt(s * (s - sideA) * (s - sideB) * (s - SideC));
  return result;
}

/**
  @brief Calculate the area of a square.
  @param side The length of the side of the square.
  @return The area of the square.
*/

double squareArea(double side)
{
  double result;
  assert(side > 0);
  result = pow(side, 2);
  return result;
}

/**
  @brief Calculate the area of a rectangle.
  @param width The width of the rectangle.
  @param length The length of the rectangle.
  @return The area of the rectangle.
*/

double retangleArea(double width, double length)
{
  double result;
  assert(width > 0 && length > 0);
  result = width * length;
  return result;
}

/**
  @brief Calculate the area of a rhombus given the lengths of the larger diagonal and smaller diagonal.
  @param largerDiagonal The length of the larger diagonal of the rhombus.
  @param smallerDiagonal The length of the smaller diagonal of the rhombus.
  @return The area of the rhombus.
*/

double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  double result;
  assert(largerDiagonal > 0 && smallerDiagonal > 0);
  result = largerDiagonal * smallerDiagonal / 2;
  return result;
}

/**
  @brief Calculate the area of a parallelogram given the base and height.
  @param base The length of the base of the parallelogram.
  @param height The height of the parallelogram.
  @return The area of the parallelogram.
*/

double parallelogramArea1(double base, double height)
{
  double result;
  assert(base > 0 && height > 0);
  result = base * height;
  return result;
}

/**
  @brief Calculate the area of a parallelogram given the lengths of two sides and the angle between them.
  @param sideA The length of one side of the parallelogram.
  @param sideB The length of the adjacent side of the parallelogram.
  @param angleBetweenAB The angle between sideA and sideB, in radians.
  @return The area of the parallelogram.
*/

double parallelogramArea2(double sideA, double sideB, double angleBeetweenAB)
{
  double result;
  assert(sideA > 0 && sideB > 0 && angleBeetweenAB > 0 && angleBeetweenAB < M_PI);
  result = sideA * sideB * sin(angleBeetweenAB);
  return result;
}

/**
  @brief Calculate the area of a trapezoid given the lengths of the larger base, smaller base, and height.
  @param largerBase The length of the larger base of the trapezoid.
  @param smallerBase The length of the smaller base of the trapezoid.
  @param height The height of the trapezoid.
  @return The area of the trapezoid.
*/

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  double result;
  assert(largerBase > 0 && smallerBase > 0 && height > 0);
  result = (largerBase + smallerBase) * height / 2;
  return result;
}

/**
  @brief Calculate the area of a regular polygon.
  @param side The length of one side of the polygon.
  @param nOfSides The number of sides of the polygon.
  @return The area of the regular polygon.
*/

double regularPolygonArea(double side, int nOfSides)
{
  double apothen, perimeter, result;
  assert(side > 0 && nOfSides > 0);
  apothen = side / (2 * tan(M_PI / nOfSides));
  perimeter = side * nOfSides;
  result = perimeter * apothen / 2;
  return result;
}

/**
  @brief Calculate the area of a circle given the radius.
  @param radius The radius of the circle.
  @return The area of the circle.
*/

double circleArea(double radius)
{
  double result;
  assert(radius > 0);
  result = M_PI * pow(radius, 2);
  return result;
}

/**
  @brief Calculate the area of a circular sector given the central angle and radius.
  @param angle The central angle of the circular sector, in radians.
  @param radius The radius of the circular sector.
  @return The area of the circular sector.
*/

double circularSectorArea1(double angle, double radius)
{
  double result;
  assert(radius > 0 && angle >= 0);
  result = angle * pow(radius, 2) / 2;
  return result;
}

/**
  @brief Calculate the area of a circular sector given the arc length and radius.
  @param arc The length of the arc of the circular sector.
  @param radius The radius of the circular sector.
  @return The area of the circular sector.
*/

double circularSectorArea2(double arc, double radius)
{
  double result;
  assert(radius > 0 && arc >= 0);
  result = arc * radius / 2;
  return result;
}

/**
  @brief Calculate the area of an ellipse given the semi-major axis and semi-minor axis.
  @param semiMajorAxis The length of the semi-major axis of the ellipse.
  @param semiMinorAxis The length of the semi-minor axis of the ellipse.
  @return The area of the ellipse.
*/

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  double result;
  assert(semiMajorAxis > 0 && semiMinorAxis > 0);
  result = M_PI * semiMajorAxis * semiMinorAxis;
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

double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
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

double regularPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides,
         apothen = baseSide / (2 * tan(M_PI / nOfBaseSides)),
         slantHeight = hypotenuse(apothen, heigth);
  return pyramidArea(baseArea, basePerimeter, slantHeight);
}

double sphereArea(double radius)
{
  double result;
  assert(radius > 0);
  result = 4 * M_PI * pow(radius, 2);
  return result;
}

double cylinderArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = 2 * M_PI * baseRadius * (baseRadius + height);
  return result;
}

double coneArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = circleArea(baseRadius) + M_PI * baseRadius * hypotenuse(height, baseRadius);
  return result;
}
