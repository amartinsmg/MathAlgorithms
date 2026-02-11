#include <assert.h>
#include <math.h>
#include "area_surface.h"
#include "statistics.h"
#include "volume.h"

#ifndef GEOMETRY_H
#define GEOMETRY_H

/**
  @brief Converts degrees to radians.
  @param degrees The angle in degrees.
  @return The angle converted to radians.
*/

double degrees2radians(double degrees)
{
  double result = degrees / 180 * M_PI;
  return result;
}

/**
  @brief Converts radians to degrees.
  @param radians The angle in radians.
  @return The angle converted to degrees.
*/

double radians2degrees(double radians)
{
  double result = radians / M_PI * 180;
  return result;
}

/**
  @brief Calculates the distance between two points.
  @param ax The x-coordinate of the first point.
  @param ay The y-coordinate of the first point.
  @param bx The x-coordinate of the second point.
  @param by The y-coordinate of the second point.
  @return The distance between the two points.
*/

double distancePoints(double ax, double ay, double bx, double by)
{
  double result = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
  return result;
}

/**
  @brief Calculates the midpoint between two points.
  @param ax The x-coordinate of the first point.
  @param ay The y-coordinate of the first point.
  @param bx The x-coordinate of the second point.
  @param by The y-coordinate of the second point.
  @return A dynamically allocated array of size 2 containing the x-coordinate and y-coordinate of the midpoint.
  @note It is the caller's responsibility to free the memory allocated for the array.
*/

double *midpointPoints(double ax, double ay, double bx, double by)
{
  double *result = (double *)malloc(sizeof(*result) * 2),
         x[2] = {ax, bx},
         y[2] = {ay, by};
  result[0] = mean(x, 2);
  result[1] = mean(y, 2);
  return result;
}

/**
  @brief Calculates the slope of a line.
  @param x1 The x-coordinate of the first point.
  @param y1 The y-coordinate of the first point.
  @param x2 The x-coordinate of the second point.
  @param y2 The y-coordinate of the second point.
  @return The slope of the line.
  @pre The two points must not be the same.
*/

double slopeOfLine(double x1, double y1, double x2, double y2)
{
  double result;
  assert(x1 != x2);
  result = (y2 - y1) / (x2 - x1);
  return result;
}

/**
  @brief Calculates the angle of incline of a line.
  @param x1 The x-coordinate of the first point.
  @param y1 The y-coordinate of the first point.
  @param x2 The x-coordinate of the second point.
  @param y2 The y-coordinate of the second point.
  @return The angle of incline of the line in radians.
*/

double angleOfInclineLine(double x1, double y1, double x2, double y2)
{
  double result = atan(slopeOfLine(x1, y1, x2, y2));
  return result;
}

/**
  @brief Calculates the equation of a line.
  @param x1 The x-coordinate of the first point.
  @param y1 The y-coordinate of the first point.
  @param x2 The x-coordinate of the second point.
  @param y2 The y-coordinate of the second point.
  @return A dynamically allocated array of size 2 containing the slope and y-intercept of the line.
  @note It is the caller's responsibility to free the memory allocated for the array.
  @pre The two points must not be the same.
*/

double *equationOfLine(double x1, double y1, double x2, double y2)
{
  double *result = (double *)malloc(sizeof(*result) * 2);
  result[0] = slopeOfLine(x1, y1, x2, y2);
  result[1] = y1 - result[0] * x1;
  return result;
}

/**
  @brief Calculates the distance between a point and a line.
  @param inclinationLine The inclination (slope) of the line.
  @param yInterceptLine The y-intercept of the line.
  @param xPoint The x-coordinate of the point.
  @param yPoint The y-coordinate of the point.
  @return The distance between the point and the line.
*/

double distancePointLine(double inclinationLine, double yInterceptLine, double xPoint, double yPoint)
{
  double result = fabs(inclinationLine * xPoint - yPoint + yInterceptLine) /
                  sqrt(pow(inclinationLine, 2) + 1);
  return result;
}

/**
  @brief Calculates the perimeter of a circle.
  @param radius The radius of the circle.
  @return The perimeter of the circle.
*/

double circlePerimeter(double radius)
{
  double result = 2 * M_PI * radius;
  return result;
}

/**
  @brief Calculates the number of diagonals in a polygon.
  @param nOfSides The number of sides of the polygon.
  @return The number of diagonals in the polygon.
  @pre The number of sides must be greater than 0.
*/

int nOfDiagnonalsPolygon(int nOfSides)
{
  double result;
  assert(nOfSides >= 3);
  result = nOfSides * (nOfSides - 3) / 2;
  return result;
}

/**
  @brief Calculates the sum of interior angles in a convex polygon.
  @param nOfSides The number of sides of the polygon.
  @return The sum of interior angles in the convex polygon, in radians.
  @pre The number of sides must be greater than 0.
*/

double convexPolygonSumInteriorAngles(double nOfSides)
{
  double result;
  assert(nOfSides >= 3);
  result = (nOfSides - 2) * M_PI;
  return result;
}

/**
  @brief Calculates the measure of each interior angle in a regular polygon.
  @param nOfSides The number of sides of the polygon.
  @return The measure of each interior angle in the regular polygon.
  @return The measure of each interior angle in the regular polygon, in radians.
  @pre The number of sides must be greater than 0.
*/

double regularPolygonInteriorAngle(int nOfSides)
{
  double result;
  assert(nOfSides >= 3);
  result = convexPolygonSumInteriorAngles(nOfSides) / nOfSides;
  return result;
}

/**
  @brief Calculates the measure of each exterior angle in a convex polygon.
  @param nOfSides The number of sides of the polygon.
  @return The measure of each exterior angle in the convex polygon, in radians.
  @pre The number of sides must be greater than 0.
*/

double convexPolygonExteriorAngle(int nOfSides)
{
  double result;
  assert(nOfSides >= 3);
  result = 2 * M_PI / nOfSides;
  return result;
}

#endif /* GEOMETRY_H */
