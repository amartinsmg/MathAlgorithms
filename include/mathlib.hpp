#ifndef MATHLIB_HPP
#define MATHLIB_HPP

#include <vector>

#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


namespace Math
{

namespace internal
{
  extern "C"
  {
  #include "internal/mathlib_c.h"
  }
} // namespace internal

/**
 * @brief Structure representing a point in 2D space.
 */
struct Point
{
  double x;
  double y;
};

/* -------------------------------------------------------------------------
 * Area — plane shapes
 * ---------------------------------------------------------------------- */

static inline double triangleArea1(double base, double height)
{
  return internal::triangleArea1(base, height);
}

static inline double triangleArea2(double sideA, double sideB, double angleGama)
{
  return internal::triangleArea2(sideA, sideB, angleGama);
}

static inline double triangleArea3(double sideA, double sideB, double sideC)
{
  return internal::triangleArea3(sideA, sideB, sideC);
}

static inline double squareArea(double side)
{
  return internal::squareArea(side);
}

static inline double rectangleArea(double width, double length)
{
  return internal::rectangleArea(width, length);
}

static inline double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  return internal::rhombusArea(largerDiagonal, smallerDiagonal);
}

static inline double parallelogramArea1(double base, double height)
{
  return internal::parallelogramArea1(base, height);
}

static inline double parallelogramArea2(double sideA, double sideB, double angleBetweenAB)
{
  return internal::parallelogramArea2(sideA, sideB, angleBetweenAB);
}

static inline double trapezoidArea(double largerBase, double smallerBase, double height)
{
  return internal::trapezoidArea(largerBase, smallerBase, height);
}

static inline double regPolygonArea(double side, int nOfSides)
{
  return internal::regPolygonArea(side, nOfSides);
}

static inline double circleArea(double radius)
{
  return internal::circleArea(radius);
}

static inline double circularSectorArea1(double angle, double radius)
{
  return internal::circularSectorArea1(angle, radius);
}

static inline double circularSectorArea2(double arc, double radius)
{
  return internal::circularSectorArea2(arc, radius);
}

static inline double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  return internal::ellipseArea(semiMajorAxis, semiMinorAxis);
}

/* -------------------------------------------------------------------------
 * Area — solid surfaces
 * ---------------------------------------------------------------------- */

static inline double cubeArea(double side)
{
  return internal::cubeArea(side);
}

static inline double cuboidArea(double width, double length, double height)
{
  return internal::cuboidArea(width, length, height);
}

static inline double prismArea(double baseArea, double basePerimeter, double height)
{
  return internal::prismArea(baseArea, basePerimeter, height);
}

static inline double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  return internal::regularPrismArea(baseSide, nOfBaseSides, height);
}

static inline double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  return internal::pyramidArea(baseArea, basePerimeter, slantHeight);
}

static inline double regPyramidArea(double baseSide, int nOfBaseSides, double height)
{
  return internal::regPyramidArea(baseSide, nOfBaseSides, height);
}

static inline double cylinderArea(double baseRadius, double height)
{
  return internal::cylinderArea(baseRadius, height);
}

static inline double coneArea(double baseRadius, double height)
{
  return internal::coneArea(baseRadius, height);
}

static inline double sphereArea(double radius)
{
  return internal::sphereArea(radius);
}

/* -------------------------------------------------------------------------
 * Volume
 * ---------------------------------------------------------------------- */

static inline double cubeVol(double side)
{
  return internal::cubeVol(side);
}

static inline double cuboidVol(double length, double width, double height)
{
  return internal::cuboidVol(length, width, height);
}

static inline double prismVol(double baseArea, double height)
{
  return internal::prismVol(baseArea, height);
}

static inline double regularPrismVol(double baseSide, int nOfBaseSides, double height)
{
  return internal::regularPrismVol(baseSide, nOfBaseSides, height);
}

static inline double pyramidVol(double baseArea, double height)
{
  return internal::pyramidVol(baseArea, height);
}

static inline double regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  return internal::regPyramidVol(baseSide, nOfBaseSides, height);
}

static inline double cylinderVol(double baseRadius, double height)
{
  return internal::cylinderVol(baseRadius, height);
}

static inline double coneVol(double baseRadius, double height)
{
  return internal::coneVol(baseRadius, height);
}

static inline double sphereVol(double radius)
{
  return internal::sphereVol(radius);
}

/* -------------------------------------------------------------------------
 * Geometry — Point API
 * ---------------------------------------------------------------------- */

static inline double distancePoints(Point a, Point b)
{
  return internal::distancePoints(a.x, a.y, b.x, b.y);
}

static inline Point midpoint(Point a, Point b)
{
  double *out = internal::midpoint(a.x, a.y, b.x, b.y);
  Point result = {out[0], out[1]};
  internal::freeArray(out);
  return result;}

static inline double slopeLine(Point a, Point b)
{
  return internal::slopeLine(a.x, a.y, b.x, b.y);
}

static inline double inclinationLine(Point a, Point b)
{
  return internal::inclinationLine(a.x, a.y, b.x, b.y);
}

static inline double lineYIntercept(Point a, Point b)
{
  return internal::lineYIntercept(a.x, a.y, b.x, b.y);
}

static inline double distancePointLine(double inclination, double yIntercept, Point p)
{
  return internal::distancePointLine(inclination, yIntercept, p.x, p.y);
}

static inline double circlePerimeter(double radius)
{
  return internal::circlePerimeter(radius);
}

static inline int polygonDiagonals(int nOfSides)
{
  return internal::polygonDiagonals(nOfSides);
}

static inline double convexPolySumIntAng(double nOfSides)
{
  return internal::convexPolySumIntAng(nOfSides);
}

static inline double regPolygonIAng(int nOfSides)
{
  return internal::regPolygonIAng(nOfSides);
}

static inline double convexPolyExtAngle(int nOfSides)
{
  return internal::convexPolyExtAngle(nOfSides);
}

/* -------------------------------------------------------------------------
 * Trigonometry
 * ---------------------------------------------------------------------- */

static inline double deg2rad(double degrees)
{
  return internal::deg2rad(degrees);
}

static inline double rad2deg(double radians)
{
  return internal::rad2deg(radians);
}

static inline double hypotenuse(double sideA, double sideB)
{
  return internal::hypotenuse(sideA, sideB);
}

static inline double sideRTriangle(double hyp, double sideA)
{
  return internal::sideRTriangle(hyp, sideA);
}

static inline double sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  return internal::sideTriangleLC(sideA, sideB, oppositeAng);
}

static inline double angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  return internal::angTriangleLC(oppositeSide, sideA, sideB);
}

static inline double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  return internal::sideTriangleLS(oppositeAng, sideA, oppositeAng2A);
}

static inline double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  return internal::angTriangleLS(oppositeSide, sideA, oppositeAng2A);
}

/* -------------------------------------------------------------------------
 * Basic operations
 * ---------------------------------------------------------------------- */

static inline double logarithm(double num, double base)
{
  return internal::logarithm(num, base);
}

static inline double nthRoot(double radicand, double degree)
{
  return internal::nthRoot(radicand, degree);
}

static inline double roundTo(double num, int decimalPlaces)
{
  return internal::roundTo(num, decimalPlaces);
}

/* -------------------------------------------------------------------------
 * Combinatorics
 * ---------------------------------------------------------------------- */

static inline long long permutation(int num)
{
  return internal::permutation(num);
}

static inline long long cyclePermutation(int num)
{
  return internal::cyclePermutation(num);
}

static inline long long arrangement(int total, int selected)
{
  return internal::arrangement(total, selected);
}

static inline long long combination(int total, int selected)
{
  return internal::combination(total, selected);
}

static inline double permutationlf(int num)
{
  return internal::permutationlf(num);
}

static inline double cyclePermutationlf(int num)
{
  return internal::cyclePermutationlf(num);
}

static inline double arrangementlf(int total, int selected)
{
  return internal::arrangementlf(total, selected);
}

static inline double combinationlf(int total, int selected)
{
  return internal::combinationlf(total, selected);
}

static inline long long factorial(int num)
{
  return internal::factorial(num);
}

static inline double factoriallf(int num)
{
  return internal::factoriallf(num);
}

/* -------------------------------------------------------------------------
 * Number theory
 * ---------------------------------------------------------------------- */

static inline long long gcd(long long x, long long y)
{
  return internal::gcd(x, y);
}

static inline long long lcm(long long x, long long y)
{
  return internal::lcm(x, y);
}

static inline bool isArmstrong(long long num)
{
  return internal::isArmstrong(num);
}

static inline bool isHappy(long long num)
{
  return internal::isHappy(num);
}

static inline bool isPerfect(long long num)
{
  return internal::isPerfect(num);
}

static inline bool isPrime(long long num)
{
  return internal::isPrime(num);
}

static inline std::vector<long long> primeFactors(long long num)
{
  size_t size;
  long long *arr = internal::primeFactors(num, &size);
  std::vector<long long> result(arr, arr + size);
  internal::freeArray(arr);
  return result;
}

/* -------------------------------------------------------------------------
 * Percentage
 * ---------------------------------------------------------------------- */

static inline double nPercentOfX(double x, double n)
{
  return internal::nPercentOfX(x, n);
}

static inline double nIsWhatPercentOfX(double x, double n)
{
  return internal::nIsWhatPercentOfX(x, n);
}

/* -------------------------------------------------------------------------
 * Growth
 * ---------------------------------------------------------------------- */

static inline double simpGrowth(double initial, double rate, double interval)
{
  return internal::simpGrowth(initial, rate, interval);
}

static inline double simpGrowthRate(double initial, double final_, double interval)
{
  return internal::simpGrowthRate(initial, final_, interval);
}

static inline double compGrowth(double initial, double rate, double interval)
{
  return internal::compGrowth(initial, rate, interval);
}

static inline double compGrowthRate(double initial, double final_, double interval)
{
  return internal::compGrowthRate(initial, final_, interval);
}

/* -------------------------------------------------------------------------
 * Probability distributions
 * ---------------------------------------------------------------------- */

static inline double binominal(int trials, double successProb, int success)
{
  return internal::binominal(trials, successProb, success);
}

static inline double poisson(double lambda, int x)
{
  return internal::poisson(lambda, x);
}

static inline double gaussianCDF(double mu, double stdDev, double x)
{
  return internal::gaussianCDF(mu, stdDev, x);
}

/* -------------------------------------------------------------------------
 * Statistics — std::vector API
 * ---------------------------------------------------------------------- */

static inline double mean(const std::vector<double> &v)
{
  return internal::mean(v.data(), v.size());
}

static inline double trimmedMean(const std::vector<double> &v, double percentage)
{
  return internal::trimmedMean(v.data(), v.size(), percentage);
}

static inline double geometricMean(const std::vector<double> &v)
{
  return internal::geometricMean(v.data(), v.size());
}

static inline double harmonicMean(const std::vector<double> &v)
{
  return internal::harmonicMean(v.data(), v.size());
}

static inline double median(const std::vector<double> &v)
{
  return internal::median(v.data(), v.size());
}

static inline std::vector<double> mode(const std::vector<double> &v)
{
  size_t size;
  double *arr = internal::mode(v.data(), v.size(), &size);
  std::vector<double> result(arr, arr + size);
  internal::freeArray(arr);
  return result;
}

static inline double min(const std::vector<double> &v)
{
  return internal::min(v.data(), v.size());
}

static inline double max(const std::vector<double> &v)
{
  return internal::max(v.data(), v.size());
}

static inline double range(const std::vector<double> &v)
{
  return internal::range(v.data(), v.size());
}

static inline double midrange(const std::vector<double> &v)
{
  return internal::midrange(v.data(), v.size());
}

static inline double variance(const std::vector<double> &v)
{
  return internal::variance(v.data(), v.size());
}

static inline double stdDev(const std::vector<double> &v)
{
  return internal::stdDev(v.data(), v.size());
}

static inline double sampleVariance(const std::vector<double> &v)
{
  return internal::sampleVariance(v.data(), v.size());
}

static inline double sampleStdDev(const std::vector<double> &v)
{
  return internal::sampleStdDev(v.data(), v.size());
}

} // namespace Math

#endif /* MATHLIB_HPP */