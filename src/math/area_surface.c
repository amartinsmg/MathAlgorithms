#include "internal/mathlib_c.h"

double cubeArea(double side) {
  if (side < 0)
    return NAN;
  double result = 6 * pow(side, 2);
  return result;
}

double cuboidArea(double width, double length, double height) {
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result = 2 * ((width * length) + (length * height) + (width * height));
  return result;
}

double prismArea(double baseArea, double basePerimeter, double height) {
  if (baseArea < 0 || basePerimeter < 0 || height < 0)
    return NAN;
  double result = (2 * baseArea) + (basePerimeter * height);
  return result;
}

double regularPrismArea(double baseSide, int nOfBaseSides, double height) {
  if (baseSide < 0 || nOfBaseSides < 0 || height < 0)
    return NAN;
  double baseArea = regPolygonArea(baseSide, nOfBaseSides);
  double basePerimeter = baseSide * nOfBaseSides;
  double result = prismArea(baseArea, basePerimeter, height);
  return result;
}

double pyramidArea(double baseArea, double basePerimeter, double slantHeight) {
  if (baseArea < 0 || basePerimeter < 0 || slantHeight < 0)
    return NAN;
  double result = baseArea + (basePerimeter * slantHeight / 2);
  return result;
}

double regPyramidArea(double baseSide, int nOfBaseSides, double height) {
  if (baseSide < 0 || nOfBaseSides < 0 || height < 0)
    return NAN;
  double baseArea = regPolygonArea(baseSide, nOfBaseSides);
  double basePerimeter = baseSide * nOfBaseSides;
  double apothen = baseSide / (2 * tan(M_PI / nOfBaseSides));
  double slantHeight = hypotenuse(apothen, height);
  double result = pyramidArea(baseArea, basePerimeter, slantHeight);
  return result;
}

double cylinderArea(double baseRadius, double height) {
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result = 2 * M_PI * baseRadius * (baseRadius + height);
  return result;
}

double coneArea(double baseRadius, double height) {
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result = circleArea(baseRadius) +
                  M_PI * baseRadius * hypotenuse(height, baseRadius);
  return result;
}

double sphereArea(double radius) {
  if (radius < 0)
    return NAN;
  double result = 4 * M_PI * pow(radius, 2);
  return result;
}
