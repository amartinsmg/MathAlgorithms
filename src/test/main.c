#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "armstrong_numbers.h"
#include "geometry.h"
#include "growth.h"
#include "happy_numbers.h"
#include "lcm.h"
#include "percentage.h"
#include "perfect_numbers.h"
#include "prime_factorization.h"
#include "prime_numbers.h"
#include "probability_distribution.h"

int main()
{
  char str[100];
  int i;
  long long arr1[8] = {2, 2, 2, 2, 3, 3, 5, 11},
            *arr2 = primeFactors(7920);
  double *arr3 = (double *)malloc(sizeof(*arr3) * 8),
         *arr4 = equationOfLine(1, 1, 2, 4),
         **matrix = (double **)malloc(sizeof(*matrix) * 8);
  for (i = 0; i < 8; i++)
    matrix[i] = (double *)malloc(sizeof(**matrix) * 2);
  for (i = 0; i < 8; i++)
    arr3[i] = matrix[i][0] = matrix[7 - i][1] = (double)arr1[i];
  for (i = 0; i < 64; i++)
    assert((i < 8 ? arr1[i] : 0) == arr2[i]);
  free(arr2);
  assert(roundTo(M_PI, 2) == 3.14);
  assert(mean(arr3, 8) == 3.75);
  assert(roundTo(geometricMean(arr3, 8), 6) == 3.07143);
  assert(roundTo(harmonicMean(arr3, 8), 6) == 2.704918);
  assert(min(arr3, 8) == 2);
  assert(max(arr3, 8) == 11);
  assert(rangeStatistics(arr3, 8) == 9);
  assert(roundTo(variance(arr3, 8), 6) == 8.4375);
  assert(roundTo(sampleVariance(arr3, 8), 6) == 9.642857);
  assert(roundTo(standardDeviation(arr3, 8), 6) == 2.904738);
  assert(roundTo(sampleStandardDeviation(arr3, 8), 6) == 3.105295);
  free(arr3);
  assert(roundTo(weightedMean(matrix, 8), 6) == 2.933333);
  free(matrix);
  assert(arr4[0] == 3 && arr4[1] == -2);
  arr4 = midpointPoints(1, 1, 2, 4);
  assert(arr4[0] == 1.5 && arr4[1] == 2.5);
  free(arr4);
  assert(isPrime(7919));
  assert(!isPrime(5329));
  assert(isPerfect(6));
  assert(!isPerfect(7));
  assert(isHappy(23));
  assert(!isHappy(73));
  assert(isArmstrong(370));
  assert(!isArmstrong(125));
  assert(nthRoot(4096, 4) == 8);
  assert(logarithm(1024, 4) == 5);
  assert(absf(-4.25) == 4.25);
  assert(nPercentOfX(725, 5) == 36.25);
  assert(nIsWhatPercentOfX(95, 7.6) == 8);
  assert(simpleGrowth(5, 0.05, 3) == 5.75);
  assert(roundTo(simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
  assert(compoundedGrowth(5, 0.2, 3) == 8.64);
  assert(roundTo(compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
  assert(gcd(40, 96) == 8);
  assert(lcm(6, 15) == 30);
  assert(factorial(20) == 2432902008176640000);
  assert(permutation(6) == 720);
  assert(cyclePermutation(9) == 40320);
  assert(arrangement(17, 11) == 494010316800);
  assert(combination(19, 15) == 3876);
  sprintf(str, "%e", factoriallf(60));
  assert(strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
  sprintf(str, "%e", permutationlf(40));
  assert(strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
  sprintf(str, "%e", cyclePermutationlf(36));
  assert(strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
  assert(round(arrangementlf(60, 6)) == 36045979200);
  assert(round(combinationlf(30, 21)) == 14307150);
  assert(roundTo(binominal(10, 0.2, 6), 6) == 0.005505);
  assert(roundTo(poisson(0.45, 4), 5) == 0.00109);
  assert(roundTo(gaussianCDF(0, 1, 3.5), 5) == 0.99977);
  assert(roundTo(gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
  assert(hypotenuse(3, 4) == 5);
  assert(roundTo(sideRetTriangle(4, 2), 6) == 3.464102);
  assert(roundTo(sideTriangleLC(4, 3, degrees2radians(60)), 6) == 3.605551);
  assert(round(radians2degrees(angleTriangleLC(2, 4, 3.464102))) == 30);
  assert(roundTo(sideTriangleLS(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979);
  assert(round(radians2degrees(angleTriangleLS(4, 4, degrees2radians(45)))) == 45);
  assert(distancePoints(-1, -1, 2, 3) == 5);
  assert(roundTo(distancePointLine(3, -2, 0, 0), 6) == 0.632456);
  assert(slopeOfLine(1, 1, 2, 4) == 3);
  assert(roundTo(radians2degrees(angleOfInclineLine(1, 1, 2, 4)), 6) == 71.565051);
  assert(roundTo(circlePerimeter(5), 6) == 31.415927);
  assert(round(radians2degrees(regPolygonSumInteAngles(5))) == 540);
  assert(round(radians2degrees(regPolygonInteriorAngle(5))) == 108);
  assert(round(radians2degrees(regPolygonExteriorAngle(5))) == 72);
  assert(nOfDiagnonalsPolygon(6) == 9);
  assert(squareArea(4) == 16);
  assert(retangleArea(4, 6) == 24);
  assert(roundTo(regPolygonArea(5, 6), 4) == 64.9519);
  assert(triangleA1(4, 5) == 10);
  assert(roundTo(triangleA2(2, 4, degrees2radians(60)), 4) == 3.4641);
  assert(triangleA3(3, 4, 5) == 6);
  assert(parallelogramArea(3, 5) == 15);
  assert(rhombusArea(4, 6) == 12);
  assert(roundTo(circleArea(4), 6) == 50.265482);
  assert(roundTo(circularSecA1(degrees2radians(45), 4), 6) == 6.283185);
  assert(circulaSecA2(6, 4) == 12);
  assert(roundTo(ellipseArea(4, 6), 6) == 75.398224);
  assert(cubeArea(4) == 96);
  assert(cuboidArea(4, 5, 6) == 148);
  assert(prismArea(16, 16, 5) == 112);
  assert(regPrismArea(4, 4, 5) == 112);
  assert(roundTo(pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
  assert(roundTo(regPyramidArea(3, 4, 4), 6) == 34.632011);
  assert(roundTo(sphereArea(4), 6) == 201.06193);
  assert(roundTo(cylinderArea(2, 5.5), 6) == 94.24778);
  assert(roundTo(coneArea(4, 6), 6) == 140.88287);
  assert(cubeVol(4) == 64);
  assert(cuboidVol(4, 5, 6) == 120);
  assert(round(prismVol(16, 5)) == 80);
  assert(round(regPrismVol(4, 4, 5)) == 80);
  assert(round(pyramidVol(9, 4)) == 12);
  assert(round(regPyramidVol(3, 4, 4)) == 12);
  assert(roundTo(sphereVol(4), 6) == 268.082573);
  assert(roundTo(cylinderVol(2, 5.5), 6) == 69.115038);
  assert(roundTo(coneVol(4, 6), 6) == 100.530965);

  puts("Passed all tests successfully!");

  return 0;
}
