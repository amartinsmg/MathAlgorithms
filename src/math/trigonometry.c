#include "internal/mathlib_c.h"

double hypotenuse(double sideA, double sideB) {
  if (sideA <= 0 || sideB <= 0)
    return NAN;

  double result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

double sideRTriangle(double hypotenuse, double sideA) {
  if (sideA <= 0 || hypotenuse <= sideA)
    return NAN;

  double result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

double sideTriangleLC(double sideA, double sideB, double oppositeAng) {
  if (sideA <= 0 || sideB <= 0 || oppositeAng <= 0 || oppositeAng >= M_PI)
    return NAN;

  double result = sqrt(pow(sideA, 2) + pow(sideB, 2) -
                       (2 * sideA * sideB * cos(oppositeAng)));
  return result;
}

double angTriangleLC(double oppositeSide, double sideA, double sideB) {
  if (sideA <= 0 || sideB <= 0 || oppositeSide <= 0 ||
      oppositeSide >= sideA + sideB || oppositeSide <= fabs(sideA - sideB))
    return NAN;

  double result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) /
                       (2 * sideA * sideB));
  return result;
}

double sideTriangleLS(double oppositeAng, double sideA, double oppositeang2A) {
  if (sideA <= 0 || oppositeAng <= 0 || oppositeAng >= M_PI ||
      oppositeang2A <= 0 || oppositeang2A >= M_PI)
    return NAN;

  double result = sideA / sin(oppositeang2A) * sin(oppositeAng);
  return result;
}

double angTriangleLS(double oppositeSide, double sideA, double oppositeang2A) {
  if (oppositeSide <= 0 || sideA <= 0 || oppositeang2A <= 0 ||
      oppositeang2A >= M_PI || oppositeSide > sideA / sin(oppositeang2A))
    return NAN;

  double result = asin(oppositeSide / (sideA / sin(oppositeang2A)));
  return result;
}
