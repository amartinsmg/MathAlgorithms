#include "internal/mathlib_c.h"
#include <stdlib.h>

double deg2rad(double degrees) {
  double result = degrees / 180 * M_PI;
  return result;
}

double rad2deg(double radians) {
  double result = radians / M_PI * 180;
  return result;
}

double distancePoints(double aX, double aY, double bX, double bY) {
  double result = sqrt(pow((bX - aX), 2) + pow((bY - aY), 2));
  return result;
}

double *midpoint(double aX, double aY, double bX, double bY) {
  double *result = (double *)malloc(2 * sizeof(double));
  if (result != NULL) {
    double x[2] = {aX, bX};
    double y[2] = {aY, bY};
    result[0] = mean(x, 2);
    result[1] = mean(y, 2);
  }

  return result;
}

double slopeLine(double aX, double aY, double bX, double bY) {
  if (aX == bX)
    return NAN;
  double result = (bY - aY) / (bX - aX);
  return result;
}

double inclinationLine(double aX, double aY, double bX, double bY) {
  double result = atan(slopeLine(aX, aY, bX, bY));
  return result;
}

double lineYIntercept(double aX, double aY, double bX, double bY) {
  if (aX == bX)
    return NAN;
  double result = aY - (slopeLine(aX, aY, bX, bY) * aX);
  return result;
}

double distancePointLine(double inclination, double yIntercept, double pX,
                         double pY) {
  double result = fabs((inclination * pX) - pY + yIntercept) /
                  sqrt(pow(inclination, 2) + 1);
  return result;
}

double circlePerimeter(double radius) {
  if (radius < 0)
    return NAN;
  double result = 2 * M_PI * radius;
  return result;
}

int polygonDiagonals(int nOfSides) {
  if (nOfSides < 3)
    return 0;
  int result;
  result = nOfSides * (nOfSides - 3) / 2;
  return result;
}

double convexPolySumIntAng(double nOfSides) {
  if (nOfSides < 3)
    return NAN;
  double result = (nOfSides - 2) * M_PI;
  return result;
}

double regPolygonIAng(int nOfSides) {
  if (nOfSides < 3)
    return NAN;
  double result = convexPolySumIntAng(nOfSides) / nOfSides;
  return result;
}

double convexPolyExtAngle(int nOfSides) {
  if (nOfSides < 3)
    return NAN;
  double result = 2 * M_PI / nOfSides;
  return result;
}
