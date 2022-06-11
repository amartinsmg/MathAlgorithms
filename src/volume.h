#include <stdlib.h>
#include "area.h"

double cubeVolume(double side)
{
  if (side < 0)
    exit(1);
  double volume = pow(side, 3);
  return volume;
}

double cuboidVolume(double length, double width, double height)
{
  if (width < 0 || length < 0 || height < 0)
    exit(1);
  double volume = length * width * height;
  return volume;
}

double primsVolume(double baseArea, double height)
{
  if (baseArea < 0 || height < 0)
    exit(1);
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
  if (baseArea < 0 || height < 0)
    exit(1);
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
  if (radius < 0)
    exit(1);
  double volume = 4 * PI * pow(radius, 3) / 3;
  return volume;
}

double coneVolume(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    exit(1);
  double volume = circleArea(baseRadius) * height / 3;
  return volume;
}

double circularCylinder(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    exit(1);
  double volume = circleArea(baseRadius) * height;
  return volume;
}
