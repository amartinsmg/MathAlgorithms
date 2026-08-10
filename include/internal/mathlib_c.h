#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#include <math.h>
#include <stdbool.h>
#include <stddef.h>

/* -------------------------------------------------------------------------
 * Memory
 * ---------------------------------------------------------------------- */

/**
 * @brief Free a pointer returned by this library.
 *
 * @param ptr Pointer to free.
 */
void freeArray(void *ptr); 

/* -------------------------------------------------------------------------
 * Area — plane shapes
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the area of a triangle given base and height.
 *
 * @param base   Triangle base.
 * @param height Triangle height.
 * @return Area of the triangle.
 */
double triangleArea1(double base, double height);

/**
 * @brief Calculate the area of a triangle given two sides and the angle between
 * them.
 *
 * @param sideA      First side.
 * @param sideB      Second side.
 * @param angleGama  Angle between sideA and sideB (radians).
 * @return Area of the triangle.
 */
double triangleArea2(double sideA, double sideB, double angleGama);

/**
 * @brief Calculate the area of a triangle given three sides (Heron's formula).
 *
 * @param sideA First side.
 * @param sideB Second side.
 * @param sideC Third side.
 * @return Area of the triangle.
 */
double triangleArea3(double sideA, double sideB, double sideC);

/**
 * @brief Calculate the area of a square.
 *
 * @param side Side length.
 * @return Area of the square.
 */
double squareArea(double side);

/**
 * @brief Calculate the area of a rectangle.
 *
 * @param width  Rectangle width.
 * @param length Rectangle length.
 * @return Area of the rectangle.
 */
double rectangleArea(double width, double length);

/**
 * @brief Calculate the area of a rhombus.
 *
 * @param largerDiagonal  Larger diagonal.
 * @param smallerDiagonal Smaller diagonal.
 * @return Area of the rhombus.
 */
double rhombusArea(double largerDiagonal, double smallerDiagonal);

/**
 * @brief Calculate the area of a parallelogram given base and height.
 *
 * @param base   Parallelogram base.
 * @param height Parallelogram height.
 * @return Area of the parallelogram.
 */
double parallelogramArea1(double base, double height);

/**
 * @brief Calculate the area of a parallelogram given two sides and the angle
 * between them.
 *
 * @param sideA            First side.
 * @param sideB            Second side.
 * @param angleBetweenAB   Angle between sideA and sideB (radians).
 * @return Area of the parallelogram.
 */
double parallelogramArea2(double sideA, double sideB, double angleBetweenAB);

/**
 * @brief Calculate the area of a trapezoid.
 *
 * @param largerBase  Larger parallel base.
 * @param smallerBase Smaller parallel base.
 * @param height      Trapezoid height.
 * @return Area of the trapezoid.
 */
double trapezoidArea(double largerBase, double smallerBase, double height);

/**
 * @brief Calculate the area of a regular polygon.
 *
 * @param side      Side length.
 * @param nOfSides  Number of sides.
 * @return Area of the regular polygon.
 */
double regPolygonArea(double side, int nOfSides);

/**
 * @brief Calculate the area of a circle.
 *
 * @param radius Circle radius.
 * @return Area of the circle.
 */
double circleArea(double radius);

/**
 * @brief Calculate the area of a circular sector given a central angle.
 *
 * @param angle  Central angle (radians).
 * @param radius Circle radius.
 * @return Area of the circular sector.
 */
double circularSectorArea1(double angle, double radius);

/**
 * @brief Calculate the area of a circular sector given arc length.
 *
 * @param arc    Arc length.
 * @param radius Circle radius.
 * @return Area of the circular sector.
 */
double circularSectorArea2(double arc, double radius);

/**
 * @brief Calculate the area of an ellipse.
 *
 * @param semiMajorAxis Semi-major axis.
 * @param semiMinorAxis Semi-minor axis.
 * @return Area of the ellipse.
 */
double ellipseArea(double semiMajorAxis, double semiMinorAxis);

/* -------------------------------------------------------------------------
 * Area — solid surfaces
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the surface area of a cube.
 *
 * @param side Side length.
 * @return Surface area of the cube.
 */
double cubeArea(double side);

/**
 * @brief Calculate the surface area of a cuboid.
 *
 * @param width  Cuboid width.
 * @param length Cuboid length.
 * @param height Cuboid height.
 * @return Surface area of the cuboid.
 */
double cuboidArea(double width, double length, double height);

/**
 * @brief Calculate the surface area of a prism.
 *
 * @param baseArea      Area of the base.
 * @param basePerimeter Perimeter of the base.
 * @param height        Prism height.
 * @return Surface area of the prism.
 */
double prismArea(double baseArea, double basePerimeter, double height);

/**
 * @brief Calculate the surface area of a regular prism.
 *
 * @param baseSide     Side length of the regular base.
 * @param nOfBaseSides Number of sides of the base.
 * @param height       Prism height.
 * @return Surface area of the regular prism.
 */
double regularPrismArea(double baseSide, int nOfBaseSides, double height);

/**
 * @brief Calculate the surface area of a pyramid.
 *
 * @param baseArea      Area of the base.
 * @param basePerimeter Perimeter of the base.
 * @param slantHeight   Slant height of the pyramid.
 * @return Surface area of the pyramid.
 */
double pyramidArea(double baseArea, double basePerimeter, double slantHeight);

/**
 * @brief Calculate the surface area of a regular pyramid.
 *
 * @param baseSide     Side length of the regular base.
 * @param nOfBaseSides Number of sides of the base.
 * @param height       Pyramid height.
 * @return Surface area of the regular pyramid.
 */
double regPyramidArea(double baseSide, int nOfBaseSides, double height);

/**
 * @brief Calculate the surface area of a cylinder.
 *
 * @param baseRadius Base radius.
 * @param height     Cylinder height.
 * @return Surface area of the cylinder.
 */
double cylinderArea(double baseRadius, double height);

/**
 * @brief Calculate the surface area of a cone.
 *
 * @param baseRadius Base radius.
 * @param height     Cone height.
 * @return Surface area of the cone.
 */
double coneArea(double baseRadius, double height);

/**
 * @brief Calculate the surface area of a sphere.
 *
 * @param radius Sphere radius.
 * @return Surface area of the sphere.
 */
double sphereArea(double radius);

/* -------------------------------------------------------------------------
 * Volume
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the volume of a cube.
 *
 * @param side Side length.
 * @return Volume of the cube.
 */
double cubeVol(double side);

/**
 * @brief Calculate the volume of a cuboid.
 *
 * @param length Cuboid length.
 * @param width  Cuboid width.
 * @param height Cuboid height.
 * @return Volume of the cuboid.
 */
double cuboidVol(double length, double width, double height);

/**
 * @brief Calculate the volume of a prism.
 *
 * @param baseArea Base area.
 * @param height   Prism height.
 * @return Volume of the prism.
 */
double prismVol(double baseArea, double height);

/**
 * @brief Calculate the volume of a regular prism.
 *
 * @param baseSide     Side length of the regular base.
 * @param nOfBaseSides Number of sides of the base.
 * @param height       Prism height.
 * @return Volume of the regular prism.
 */
double regularPrismVol(double baseSide, int nOfBaseSides, double height);

/**
 * @brief Calculate the volume of a pyramid.
 *
 * @param baseArea Base area.
 * @param height   Pyramid height.
 * @return Volume of the pyramid.
 */
double pyramidVol(double baseArea, double height);

/**
 * @brief Calculate the volume of a regular pyramid.
 *
 * @param baseSide     Side length of the regular base.
 * @param nOfBaseSides Number of sides of the base.
 * @param height       Pyramid height.
 * @return Volume of the regular pyramid.
 */
double regPyramidVol(double baseSide, int nOfBaseSides, double height);

/**
 * @brief Calculate the volume of a cylinder.
 *
 * @param baseRadius Base radius.
 * @param height     Cylinder height.
 * @return Volume of the cylinder.
 */
double cylinderVol(double baseRadius, double height);

/**
 * @brief Calculate the volume of a cone.
 *
 * @param baseRadius Base radius.
 * @param height     Cone height.
 * @return Volume of the cone.
 */
double coneVol(double baseRadius, double height);

/**
 * @brief Calculate the volume of a sphere.
 *
 * @param radius Sphere radius.
 * @return Volume of the sphere.
 */
double sphereVol(double radius);

/* -------------------------------------------------------------------------
 * Geometry
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the distance between two points.
 *
 * @param aX X coordinate of point A.
 * @param aY Y coordinate of point A.
 * @param bX X coordinate of point B.
 * @param bY Y coordinate of point B.
 * @return Euclidean distance between A and B.
 */
double distancePoints(double aX, double aY, double bX, double bY);

/**
 * @brief Calculate the midpoint between two points.
 *
 * Caller is responsible for freeing the returned pointer with freeArray().
 *
 * @param aX X coordinate of point A.
 * @param aY Y coordinate of point A.
 * @param bX X coordinate of point B.
 * @param bY Y coordinate of point B.
 * @return Heap-allocated array of two doubles {x, y}, or NULL on allocation
 * failure.
 */
double *midpoint(double aX, double aY, double bX, double bY);

/**
 * @brief Calculate the slope of the line through two points.
 *
 * @param aX X coordinate of point A.
 * @param aY Y coordinate of point A.
 * @param bX X coordinate of point B.
 * @param bY Y coordinate of point B.
 * @return Slope of the line.
 */
double slopeLine(double aX, double aY, double bX, double bY);

/**
 * @brief Calculate the inclination angle of the line through two points.
 *
 * @param aX X coordinate of point A.
 * @param aY Y coordinate of point A.
 * @param bX X coordinate of point B.
 * @param bY Y coordinate of point B.
 * @return Inclination angle in radians.
 */
double inclinationLine(double aX, double aY, double bX, double bY);

/**
 * @brief Calculate the y-intercept of the line through two points.
 *
 * @param aX X coordinate of point A.
 * @param aY Y coordinate of point A.
 * @param bX X coordinate of point B.
 * @param bY Y coordinate of point B.
 * @return Y-intercept of the line.
 */
double lineYIntercept(double aX, double aY, double bX, double bY);

/**
 * @brief Calculate the distance from a point to a line.
 *
 * @param inclination  Slope (m) of the line.
 * @param yIntercept   Y-intercept (b) of the line.
 * @param pX           X coordinate of the point.
 * @param pY           Y coordinate of the point.
 * @return Distance from the point to the line.
 */
double distancePointLine(double inclination, double yIntercept, double pX,
                         double pY);

/**
 * @brief Calculate the perimeter of a circle.
 *
 * @param radius Circle radius.
 * @return Perimeter (circumference) of the circle.
 */
double circlePerimeter(double radius);

/**
 * @brief Calculate the number of diagonals of a convex polygon.
 *
 * @param nOfSides Number of sides.
 * @return Number of diagonals.
 */
int polygonDiagonals(int nOfSides);

/**
 * @brief Calculate the sum of interior angles of a convex polygon.
 *
 * @param nOfSides Number of sides.
 * @return Sum of interior angles in degrees.
 */
double convexPolySumIntAng(double nOfSides);

/**
 * @brief Calculate the interior angle of a regular polygon.
 *
 * @param nOfSides Number of sides.
 * @return Interior angle in degrees.
 */
double regPolygonIAng(int nOfSides);

/**
 * @brief Calculate the exterior angle of a convex polygon.
 *
 * @param nOfSides Number of sides.
 * @return Exterior angle in degrees.
 */
double convexPolyExtAngle(int nOfSides);

/* -------------------------------------------------------------------------
 * Trigonometry
 * ---------------------------------------------------------------------- */

/**
 * @brief Convert degrees to radians.
 *
 * @param degrees Angle in degrees.
 * @return Angle in radians.
 */
double deg2rad(double degrees);

/**
 * @brief Convert radians to degrees.
 *
 * @param radians Angle in radians.
 * @return Angle in degrees.
 */
double rad2deg(double radians);

/**
 * @brief Calculate the hypotenuse of a right triangle.
 *
 * @param sideA First leg.
 * @param sideB Second leg.
 * @return Hypotenuse length.
 */
double hypotenuse(double sideA, double sideB);

/**
 * @brief Calculate a leg of a right triangle given hypotenuse and the other
 * leg.
 *
 * @param hypotenuse Hypotenuse length.
 * @param sideA      Known leg.
 * @return Unknown leg length.
 */
double sideRTriangle(double hypotenuse, double sideA);

/**
 * @brief Calculate a side of a triangle using the law of cosines.
 *
 * @param sideA       First known side.
 * @param sideB       Second known side.
 * @param oppositeAng Angle opposite the unknown side (radians).
 * @return Length of the unknown side.
 */
double sideTriangleLC(double sideA, double sideB, double oppositeAng);

/**
 * @brief Calculate an angle of a triangle using the law of cosines.
 *
 * @param oppositeSide Side opposite the unknown angle.
 * @param sideA        First known side.
 * @param sideB        Second known side.
 * @return Unknown angle in radians.
 */
double angTriangleLC(double oppositeSide, double sideA, double sideB);

/**
 * @brief Calculate a side of a triangle using the law of sines.
 *
 * @param oppositeAng   Angle opposite the unknown side (radians).
 * @param sideA         Known side.
 * @param oppositeAng2A Angle opposite sideA (radians).
 * @return Length of the unknown side.
 */
double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A);

/**
 * @brief Calculate an angle of a triangle using the law of sines.
 *
 * @param oppositeSide  Side opposite the unknown angle.
 * @param sideA         Known side.
 * @param oppositeAng2A Angle opposite sideA (radians).
 * @return Unknown angle in radians.
 */
double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A);

/* -------------------------------------------------------------------------
 * Basic operations
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the logarithm of a number in a given base.
 *
 * @param num  The number.
 * @param base The base.
 * @return Logarithm of num in the given base.
 */
double logarithm(double num, double base);

/**
 * @brief Calculate the nth root of a number.
 *
 * @param radicand The number under the root.
 * @param degree   Root degree.
 * @return nth root of radicand.
 */
double nthRoot(double radicand, double degree);

/**
 * @brief Round a number to a given number of decimal places.
 *
 * @param num           Number to round.
 * @param decimalPlaces Number of decimal places.
 * @return Rounded number.
 */
double roundTo(double num, unsigned decimalPlaces);

/* -------------------------------------------------------------------------
 * Combinatorics
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the number of permutations of n elements (n!).
 *
 * @param num Number of elements.
 * @return Number of permutations.
 */
unsigned long long permutation(unsigned num);

/**
 * @brief Calculate the number of cyclic permutations of n elements ((n-1)!).
 *
 * @param num Number of elements.
 * @return Number of cyclic permutations.
 */
unsigned long long cyclePermutation(unsigned num);

/**
 * @brief Calculate the number of arrangements (partial permutations) P(n,k).
 *
 * @param total    Total number of elements (n).
 * @param selected Number of selected elements (k).
 * @return Number of arrangements.
 */
unsigned long long arrangement(unsigned total, unsigned selected);

/**
 * @brief Calculate the number of combinations C(n,k).
 *
 * @param total    Total number of elements (n).
 * @param selected Number of selected elements (k).
 * @return Number of combinations.
 */
unsigned long long combination(unsigned total, unsigned selected);

/**
 * @brief Calculate the number of permutations of n elements as a double.
 *
 * @param num Number of elements.
 * @return Number of permutations.
 */
double permutationlf(unsigned num);

/**
 * @brief Calculate the number of cyclic permutations of n elements as a double.
 *
 * @param num Number of elements.
 * @return Number of cyclic permutations.
 */
double cyclePermutationlf(unsigned num);

/**
 * @brief Calculate the number of arrangements P(n,k) as a double.
 *
 * @param total    Total number of elements (n).
 * @param selected Number of selected elements (k).
 * @return Number of arrangements.
 */
double arrangementlf(unsigned total, unsigned selected);

/**
 * @brief Calculate the number of combinations C(n,k) as a double.
 *
 * @param total    Total number of elements (n).
 * @param selected Number of selected elements (k).
 * @return Number of combinations.
 */
double combinationlf(unsigned total, unsigned selected);

/**
 * @brief Calculate the factorial of n (n!).
 *
 * @param num Non-negative integer.
 * @return Factorial of num.
 */
unsigned long long factorial(unsigned num);

/**
 * @brief Calculate the factorial of n as a double.
 *
 * @param num Non-negative integer.
 * @return Factorial of num.
 */
double factoriallf(unsigned num);

/* -------------------------------------------------------------------------
 * Number theory
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the greatest common divisor (GCD) of two integers.
 *
 * @param x First integer.
 * @param y Second integer.
 * @return GCD of x and y.
 */
long long gcd(long long x, long long y);

/**
 * @brief Calculate the least common multiple (LCM) of two integers.
 *
 * @param x First integer.
 * @param y Second integer.
 * @return LCM of x and y.
 */
long long lcm(long long x, long long y);

/**
 * @brief Check whether a number is an Armstrong number.
 *
 * @param num Number to check.
 * @return true if Armstrong, false otherwise.
 */
bool isArmstrong(long long num);

/**
 * @brief Check whether a number is a happy number.
 *
 * @param num Number to check.
 * @return true if happy, false otherwise.
 */
bool isHappy(long long num);

/**
 * @brief Check whether a number is a perfect number.
 *
 * @param num Number to check.
 * @return true if perfect, false otherwise.
 */
bool isPerfect(long long num);

/**
 * @brief Check whether a number is prime.
 *
 * @param num Number to check.
 * @return true if prime, false otherwise.
 */
bool isPrime(long long num);

/**
 * @brief Calculate the prime factorization of a number.
 *
 * Caller is responsible for freeing the returned pointer with freeArray().
 *
 * @param num  Number to factorize.
 * @param size Output parameter set to the number of prime factors.
 * @return Heap-allocated array of prime factors, or NULL on allocation failure.
 */
long long *primeFactors(long long num, size_t *size);

/* -------------------------------------------------------------------------
 * Percentage
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate n percent of x.
 *
 * @param x The base value.
 * @param n The percentage.
 * @return n% of x.
 */
double nPercentOfX(double x, double n);

/**
 * @brief Calculate what percentage n is of x.
 *
 * @param x The base value.
 * @param n The partial value.
 * @return Percentage that n represents of x.
 */
double nIsWhatPercentOfX(double x, double n);

/* -------------------------------------------------------------------------
 * Growth
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate simple growth.
 *
 * @param initial  Initial value.
 * @param rate     Growth rate (decimal, e.g. 0.05 for 5%).
 * @param interval Number of periods.
 * @return Final value after simple growth.
 */
double simpGrowth(double initial, double rate, double interval);

/**
 * @brief Calculate the simple growth rate between two values.
 *
 * @param initial  Initial value.
 * @param final    Final value.
 * @param interval Number of periods.
 * @return Simple growth rate.
 */
double simpGrowthRate(double initial, double final, double interval);

/**
 * @brief Calculate compound growth.
 *
 * @param initial  Initial value.
 * @param rate     Growth rate per period (decimal).
 * @param interval Number of periods.
 * @return Final value after compound growth.
 */
double compGrowth(double initial, double rate, double interval);

/**
 * @brief Calculate the compound growth rate between two values.
 *
 * @param initial  Initial value.
 * @param final    Final value.
 * @param interval Number of periods.
 * @return Compound growth rate per period.
 */
double compGrowthRate(double initial, double final, double interval);

/* -------------------------------------------------------------------------
 * Probability distributions
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the binomial probability P(X = success).
 *
 * @param trials      Number of trials (n).
 * @param successProb Probability of success per trial (p).
 * @param success     Number of successes (k).
 * @return P(X = k).
 */
double binominal(int trials, double successProb, int success);

/**
 * @brief Calculate the Poisson probability P(X = x).
 *
 * @param lambda Expected number of events (λ).
 * @param x      Observed number of events.
 * @return P(X = x).
 */
double poisson(double lambda, int x);

/**
 * @brief Calculate the Gaussian (normal) CDF P(X ≤ x).
 *
 * @param mu     Mean (μ).
 * @param stdDev Standard deviation (σ).
 * @param x      Upper bound.
 * @return P(X ≤ x).
 */
double gaussianCDF(double mu, double stdDev, double x);

/* -------------------------------------------------------------------------
 * Statistics
 * ---------------------------------------------------------------------- */

/**
 * @brief Calculate the arithmetic mean of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Arithmetic mean.
 */
double mean(const double *arr, size_t length);

/**
 * @brief Calculate the trimmed mean of an array.
 *
 * @param arr        Input array.
 * @param length     Number of elements.
 * @param percentage Percentage of elements to trim from each end (0–50).
 * @return Trimmed mean.
 */
double trimmedMean(const double *arr, size_t length, double percentage);

/**
 * @brief Calculate the geometric mean of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Geometric mean.
 */
double geometricMean(const double *arr, size_t length);

/**
 * @brief Calculate the harmonic mean of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Harmonic mean.
 */
double harmonicMean(const double *arr, size_t length);

/**
 * @brief Calculate the median of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Median.
 */
double median(const double *arr, size_t length);

/**
 * @brief Calculate the mode(s) of an array.
 *
 * Caller is responsible for freeing the returned pointer with freeArray().
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @param size   Output parameter set to the number of modes found.
 * @return Heap-allocated array of mode values, or NULL on allocation failure.
 */
double *mode(const double *arr, size_t length, size_t *size);

/**
 * @brief Find the minimum value of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Minimum value.
 */
double min(const double *arr, size_t length);

/**
 * @brief Find the maximum value of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Maximum value.
 */
double max(const double *arr, size_t length);

/**
 * @brief Calculate the range (max − min) of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Range.
 */
double range(const double *arr, size_t length);

/**
 * @brief Calculate the midrange ((max + min) / 2) of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Midrange.
 */
double midrange(const double *arr, size_t length);

/**
 * @brief Calculate the population variance of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Population variance.
 */
double variance(const double *arr, size_t length);

/**
 * @brief Calculate the population standard deviation of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Population standard deviation.
 */
double stdDev(const double *arr, size_t length);

/**
 * @brief Calculate the sample variance of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Sample variance.
 */
double sampleVariance(const double *arr, size_t length);

/**
 * @brief Calculate the sample standard deviation of an array.
 *
 * @param arr    Input array.
 * @param length Number of elements.
 * @return Sample standard deviation.
 */
double sampleStdDev(const double *arr, size_t length);
