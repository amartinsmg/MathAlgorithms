#ifndef MATHLIB_H
#define MATHLIB_H

#include "internal/mathlib_c.h"

/**
 * @brief Structure representing a point in 2D space.
 */
typedef struct {
  double x;
  double y;
} Point;

/* -------------------------------------------------------------------------
 * Geometry — Point API (wraps the flat coordinate functions)
 * ---------------------------------------------------------------------- */

static inline double math_distance_points(Point a, Point b) {
  return distancePoints(a.x, a.y, b.x, b.y);
}

static inline Point math_midpoint(Point a, Point b) {
  double *out = midpoint(a.x, a.y, b.x, b.y);
  Point result = {out[0], out[1]};
  freeArray(out);
  return result;
}

static inline double math_slope_line(Point a, Point b) {
  return slopeLine(a.x, a.y, b.x, b.y);
}

static inline double math_inclination_line(Point a, Point b) {
  return inclinationLine(a.x, a.y, b.x, b.y);
}

static inline double math_line_y_intercept(Point a, Point b) {
  return lineYIntercept(a.x, a.y, b.x, b.y);
}

static inline double math_distance_point_line(double inclination,
                                              double yIntercept, Point p) {
  return distancePointLine(inclination, yIntercept, p.x, p.y);
}

#endif /* MATHLIB_H */
