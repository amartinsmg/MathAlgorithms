#include <assert.h>
#include "area.h"

#define PI 3.141592653589793

double cubeVolume(double side)
{
  assert(side >= 0);
  double volume = pow(side, 3);
  return volume;
}

double cuboidVolume(double length, double width, double height)
{
  assert(width >= 0 || length >= 0 || height >= 0);
  double volume = length * width * height;
  return volume;
}

double primsVolume(double baseArea, double height)
{
  assert(baseArea >= 0 || height >= 0);
  double volume = baseArea * height;
  return volume;
}

double regularPrismVolume(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPoligonArea(baseSide, nOfBaseSides);
  return primsVolume(baseArea, height);
}

double pyramidVolume(double baseArea, double height)
{
  assert(baseArea >= 0 || height >= 0);
  double volume = baseArea * height / 3;
  return volume;
}

double regularPyramidVolume(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPoligonArea(baseSide, nOfBaseSides);
  return pyramidVolume(baseArea, height);
}

double sphereVolume(double radius)
{
  assert(radius >= 0);
  double volume = 4 * PI * pow(radius, 3) / 3;
  return volume;
}

double coneVolume(double baseRadius, double height)
{
  assert(baseRadius >= 0 || height >= 0);
  double volume = circleArea(baseRadius) * height / 3;
  return volume;
}

double circularCylinder(double baseRadius, double height)
{
  assert(baseRadius >= 0 || height >= 0);
  double volume = circleArea(baseRadius) * height;
  return volume;
}
