#include <assert.h>
#include "area.h"

double cubeVol(double side)
{
  double result; 
  assert(side > 0);
  result = pow(side, 3);
  return result;
}

double cuboidVol(double length, double width, double height)
{
  double result; 
  assert(width > 0 && length > 0 && height > 0);
  result = length * width * height;
  return result;
}

double prismVol(double baseArea, double height)
{
  double result; 
  assert(baseArea > 0 && height > 0);
  result = baseArea * height;
  return result;
}

double regPrismVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regPolygonArea(baseSide, nOfBaseSides);
  return prismVol(baseArea, height);
}

double pyramidVol(double baseArea, double height)
{
  double result; 
  assert(baseArea > 0 && height > 0);
  result = baseArea * height / 3;
  return result;
}

double regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regPolygonArea(baseSide, nOfBaseSides);
  return pyramidVol(baseArea, height);
}

double sphereVol(double radius)
{
  double result; 
  assert(radius > 0);
  result = 4 * M_PI * pow(radius, 3) / 3;
  return result;
}

double cylinderVol(double baseRadius, double height)
{
  double result; 
  assert(baseRadius > 0 && height > 0);
  result = circleArea(baseRadius) * height;
  return result;
}

double coneVol(double baseRadius, double height)
{
  double result; 
  assert(baseRadius > 0 && height > 0);
  result = circleArea(baseRadius) * height / 3;
  return result;
}
