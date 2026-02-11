#include <assert.h>
#include <math.h>

#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

/**
  @brief Calculate the hypotenuse of a right triangle.
  @param sideA The length of side A of the right triangle.
  @param sideB The length of side B of the right triangle.
  @return The length of the hypotenuse.
*/

double hypotenuse(double sideA, double sideB)
{
  double result;
  assert(sideA > 0 && sideB > 0);
  result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

/**
  @brief Calculate the length of a side in a right triangle.
  @param hypotenuse The length of the hypotenuse of the right triangle.
  @param sideA The length of one of the other sides of the right triangle.
  @return The length of the side.
*/

double sideRightTriangle(double hypotenuse, double sideA)
{
  double result;
  assert(sideA > 0 && hypotenuse > sideA);
  result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

/**
  @brief Calculate the length of a side in a triangle using the Law of Cosines.
  @param sideA The length of side A of the triangle.
  @param sideB The length of side B of the triangle.
  @param oppositeAngle The measure of the angle opposite to the side whose length is being calculated.
  @return The length of the side.
*/

double sideTriangleLC(double sideA, double sideB, double oppositeAngle)
{
  double result;
  assert(sideA > 0 && sideB > 0 && oppositeAngle > 0 && oppositeAngle < M_PI);
  result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(oppositeAngle)));
  return result;
}

/**
  @brief Calculate the measure of an angle in a triangle using the Law of Cosines.
  @param oppositeSide The length of the side opposite to the angle.
  @param sideA The length of one of the other sides of the triangle.
  @param sideB The length of the other side of the triangle.
  @return The measure of the angle in radians.
*/

double angleTriangleLC(double oppositeSide, double sideA, double sideB)
{
  double result;
  assert(sideA > 0 && sideB > 0 && oppositeSide > 0 &&
         oppositeSide < sideA + sideB && oppositeSide > fabs(sideA - sideB));
  result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) / (2 * sideA * sideB));
  return result;
}

/**
  @brief Calculate the length of a side in a triangle using the Law of Sines.
  @param oppositeAngle The measure of the angle opposite to the side whose length is being calculated.
  @param sideA The length of one of the other sides of the triangle.
  @param oppositeAngle2A The measure of the other angle opposite to side A.
  @return The length of the side.
*/

double sideTriangleLS(double oppositeAngle, double sideA, double oppositeAngle2A)
{
  double result;
  assert(sideA > 0 && oppositeAngle > 0 && oppositeAngle < M_PI &&
         oppositeAngle2A > 0 && oppositeAngle2A < M_PI);
  result = sideA / sin(oppositeAngle2A) * sin(oppositeAngle);
  return result;
}

/**
  @brief Calculate the measure of an angle in a triangle using the Law of Sines.
  @param oppositeSide The length of the side opposite to the angle.
  @param sideA The length of one of the other sides of the triangle.
  @param oppositeAngle2A The measure of the other angle opposite to side A.
  @return The measure of the angle in radians.
*/

double angleTriangleLS(double oppositeSide, double sideA, double oppositeAngle2A)
{
  double result;
  assert(oppositeSide > 0 && sideA > 0 && oppositeAngle2A > 0 && oppositeAngle2A < M_PI &&
         oppositeSide <= sideA / sin(oppositeAngle2A));
  result = asin(oppositeSide / (sideA / sin(oppositeAngle2A)));
  return result;
}

#endif /* TRIGONOMETRY_H */
