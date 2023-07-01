#include <assert.h>
#include <math.h>
#include "area_shape.h"

/**
  @brief Calculates the surface area of a cube.
  @param side The length of the side of the cube.
  @return The surface area of the cube.
*/

double cubeArea(double side)
{
  double result;
  assert(side > 0);
  result = 6 * pow(side, 2);
  return result;
}

/**
  @brief Calculates the surface area of a cuboid.
  @param width The width of the cuboid.
  @param length The length of the cuboid.
  @param height The height of the cuboid.
  @return The surface area of the cuboid.
*/

double cuboidArea(double width, double length, double height)
{
  double result;
  assert(width > 0 && length > 0 && height > 0);
  result = 2 * ((width * length) + (length * height) + (width * height));
  return result;
}

/**
  @brief Calculates the surface area of a prism.
  @param baseArea The area of the prism's base.
  @param basePerimeter The perimeter of the prism's base.
  @param height The height of the prism.
  @return The surface area of the prism.
*/

double prismArea(double baseArea, double basePerimeter, double height)
{
  double result;
  assert(baseArea > 0 && basePerimeter > 0 && height > 0);
  result = 2 * baseArea + basePerimeter * height;
  return result;
}

/**
  @brief Calculates the surface area of a regular prism.
  @param baseSide The length of the base side of the prism.
  @param nOfBaseSides The number of sides in the base of the prism.
  @param height The height of the prism.
  @return The surface area of the prism.
*/

double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides;
  return prismArea(baseArea, basePerimeter, height);
}

/**
  @brief Calculates the surface area of a pyramid.
  @param baseArea The area of the pyramid's base.
  @param basePerimeter The perimeter of the pyramid's base.
  @param slantHeight The slant height of the pyramid.
  @return The surface area of the pyramid.
*/

double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  double result;
  assert(baseArea > 0 && basePerimeter > 0 && slantHeight > 0);
  result = baseArea + basePerimeter * slantHeight / 2;
  return result;
}

/**
  @brief Calculates the surface area of a regular pyramid.
  @param baseSide The length of the base side of the pyramid.
  @param nOfBaseSides The number of sides in the base of the pyramid.
  @param height The height of the pyramid.
  @return The surface area of the pyramid.
*/

double regularPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides,
         apothen = baseSide / (2 * tan(M_PI / nOfBaseSides)),
         slantHeight = hypotenuse(apothen, heigth);
  return pyramidArea(baseArea, basePerimeter, slantHeight);
}

/**
  @brief Calculates the surface area of a cylinder.
  @param baseRadius The radius of the cylinder's base.
  @param height The height of the cylinder.
  @return The surface area of the cylinder.
*/

double cylinderArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = 2 * M_PI * baseRadius * (baseRadius + height);
  return result;
}

/**
  @brief Calculates the surface area of a cone.
  @param baseRadius The radius of the cone's base.
  @param height The height of the cone.
  @return The surface area of the cone.
*/

double coneArea(double baseRadius, double height)
{
  double result;
  assert(baseRadius > 0 && height > 0);
  result = circleArea(baseRadius) + M_PI * baseRadius * hypotenuse(height, baseRadius);
  return result;
}

/**
  @brief Calculates the surface area of a sphere.
  @param radius The radius of the sphere.
  @return The surface area of the sphere.
*/

double sphereArea(double radius)
{
  double result;
  assert(radius > 0);
  result = 4 * M_PI * pow(radius, 2);
  return result;
}
