#include "internal/mathlib_c.h"

double triangleArea1(double base, double height) {
  if (base < 0 || height <= 0)
    return NAN;
  double result = base * height / 2;
  return result;
}

double triangleArea2(double sideA, double sideB, double angleGama) {
  if (sideA < 0 || sideB < 0 || angleGama < 0 || angleGama > M_PI)
    return NAN;
  double result = sideA * sideB * sin(angleGama) / 2;
  return result;
}

double triangleArea3(double sideA, double sideB, double sideC) {
  if (sideA < 0 || sideB < 0 || sideC < 0)
    return NAN;
  double s = (sideA + sideB + sideC) / 2;
  double result = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
  return result;
}

double squareArea(double side) {
  if (side < 0)
    return NAN;
  double result = pow(side, 2);
  return result;
}

double rectangleArea(double width, double length) {
  if (width < 0 || length < 0)
    return NAN;
  double result = width * length;
  return result;
}

double rhombusArea(double largerDiagonal, double smallerDiagonal) {
  if (largerDiagonal < 0 || smallerDiagonal < 0)
    return NAN;
  double result = largerDiagonal * smallerDiagonal / 2;
  return result;
}

double parallelogramArea1(double base, double height) {
  if (base < 0 || height < 0)
    return NAN;
  double result = base * height;
  return result;
}

double parallelogramArea2(double sideA, double sideB, double angleBetweenAB) {
  if (sideA < 0 || sideB < 0 || angleBetweenAB < 0 || angleBetweenAB > M_PI)
    return NAN;
  double result = sideA * sideB * sin(angleBetweenAB);
  return result;
}

double trapezoidArea(double largerBase, double smallerBase, double height) {
  if (largerBase < 0 || smallerBase < 0 || height < 0)
    return NAN;
  double result = (largerBase + smallerBase) * height / 2;
  return result;
}

double regPolygonArea(double side, int nOfSides) {
  if (side < 0 || nOfSides < 3)
    return NAN;
  double apothen = side / (2 * tan(M_PI / nOfSides));
  double perimeter = side * nOfSides;
  double result = perimeter * apothen / 2;
  return result;
}

double circleArea(double radius) {
  if (radius < 0)
    return NAN;
  double result = M_PI * pow(radius, 2);
  return result;
}

double circularSectorArea1(double angle, double radius) {
  if (radius < 0 || angle < 0 || angle > 2 * M_PI)
    return NAN;
  double result = angle * pow(radius, 2) / 2;
  return result;
}

double circularSectorArea2(double arc, double radius) {
  if (radius < 0 || arc < 0 || arc > M_PI * 2 * radius)
    return NAN;
  double result = arc * radius / 2;
  return result;
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis) {
  if (semiMajorAxis < 0 || semiMinorAxis < 0)
    return NAN;
  double result = M_PI * semiMajorAxis * semiMinorAxis;
  return result;
}
