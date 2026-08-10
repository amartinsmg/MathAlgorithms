#include "internal/mathlib_c.h"

double cubeVol(double side) {
  if (side < 0)
    return NAN;

  double result = pow(side, 3);
  return result;
}

double cuboidVol(double length, double width, double height) {
  if (width < 0 || length < 0 || height < 0)
    return NAN;

  double result = length * width * height;
  return result;
}

double prismVol(double baseArea, double height) {
  if (baseArea < 0 || height < 0)
    return NAN;

  double result = baseArea * height;
  return result;
}

double regularPrismVol(double baseSide, int nOfbaseSides, double height) {
  double baseArea = regPolygonArea(baseSide, nOfbaseSides);
  double result = prismVol(baseArea, height);
  return result;
}

double pyramidVol(double baseArea, double height) {
  if (baseArea < 0 || height < 0)
    return NAN;
  double result = baseArea * height / 3;
  return result;
}

double regPyramidVol(double baseSide, int nOfbaseSides, double height) {
  double baseArea = regPolygonArea(baseSide, nOfbaseSides);
  double result = pyramidVol(baseArea, height);
  return result;
}

double cylinderVol(double baseRadius, double height) {
  if (baseRadius < 0 || height < 0)
    return NAN;

  double result = circleArea(baseRadius) * height;
  return result;
}

double coneVol(double baseRadius, double height) {
  if (baseRadius < 0 || height < 0)
    return NAN;

  double result = circleArea(baseRadius) * height / 3;
  return result;
}

double sphereVol(double radius) {
  if (radius < 0)
    return NAN;

  double result = 4 * M_PI * pow(radius, 3) / 3;
  return result;
}
