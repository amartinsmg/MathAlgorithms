#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <armstrong_numbers.h>
#include <geometry.h>
#include <growth.h>
#include <happy_numbers.h>
#include <lcm.h>
#include <perfect_numbers.h>
#include <prime_factorization.h>
#include <prime_numbers.h>
#include <probability_distribution.h>

/**
  @brief Main function to test mathematical algorithms.
  This is the main function used to test different mathematical algorithms
  by comparing the results with pre-calculated values. It serves as a testing
  ground for verifying the correctness of the algorithms.
  @return An integer representing the exit status of the program.
*/

int main()
{
  char str[100];
  int i;
  unsigned nOfModes;
  long long arr1[8] = {2, 2, 2, 2, 3, 3, 5, 11},
            arr2[7] = {2, 2, 3, 3, 3, 7, 73},
            *arr3 = primeFactors(7920),
            *arr4 = primeFactors(55188);
  double *arr5 = (double *)malloc(sizeof(*arr5) * 8),
         *arr6 = (double *)malloc(sizeof(*arr5) * 7),
         *arr7 = equationOfLine(1, 1, 2, 4),
         **matrix1 = (double **)malloc(sizeof(*matrix1) * 8),
         **matrix2 = (double **)malloc(sizeof(*matrix2) * 7);
  for (i = 0; i < 8; i++)
    matrix1[i] = (double *)malloc(sizeof(**matrix1) * 2);
  for (i = 0; i < 7; i++)
    matrix2[i] = (double *)malloc(sizeof(**matrix2) * 2);
  for (i = 0; i < 8; i++)
    arr5[i] = matrix1[i][0] = matrix1[7 - i][1] = (double)arr1[i];
  for (i = 0; i < 7; i++)
    arr6[i] = matrix2[i][0] = matrix2[6 - i][1] = (double)arr2[i];
  for (i = 0; i < 64; i++)
    assert((i < 8 ? arr1[i] : 0) == arr3[i]);
  for (i = 0; i < 64; i++)
    assert((i < 8 ? arr2[i] : 0) == arr4[i]);
  free(arr3);
  free(arr4);
  assert(roundTo(M_PI, 2) == 3.14);
  assert(roundTo(sqrt(2), 2) == 1.41);
  assert(mean(arr5, 8) == 3.75);
  assert(roundTo(mean(arr6, 7), 6) == 13.285714);
  assert(roundTo(geometricMean(arr5, 8), 6) == 3.07143);
  assert(roundTo(geometricMean(arr6, 7), 6) == 4.757802);
  assert(roundTo(harmonicMean(arr5, 8), 6) == 2.704918);
  assert(roundTo(harmonicMean(arr6, 7), 6) == 3.245917);
  assert(roundTo(trimmedMean(arr5, 8, 12), 6) == 2.833333);
  assert(trimmedMean(arr6, 7, 14) == 3.6);
  assert(median(arr5, 8) == 2.5);
  assert(median(arr6, 7) == 3);
  assert(mode(arr5, 8, &nOfModes)[0] == 2 && nOfModes == 1);
  assert(mode(arr6, 7, &nOfModes)[0] == 3 && nOfModes == 1);
  assert(min(arr5, 8) == 2);
  assert(min(arr6, 7) == 2);
  assert(max(arr5, 8) == 11);
  assert(max(arr6, 7) == 73);
  assert(range(arr5, 8) == 9);
  assert(range(arr6, 7) == 71);
  assert(midrange(arr5, 8) == 4.5);
  assert(midrange(arr6, 7) == 35.5);
  assert(roundTo(variance(arr5, 8), 6) == 8.4375);
  assert(roundTo(variance(arr6, 7), 6) == 596.775510);
  assert(roundTo(sampleVariance(arr5, 8), 6) == 9.642857);
  assert(roundTo(sampleVariance(arr6, 7), 6) == 696.238095);
  assert(roundTo(standardDeviation(arr5, 8), 6) == 2.904738);
  assert(roundTo(standardDeviation(arr6, 7), 6) == 24.428989);
  assert(roundTo(sampleStandardDeviation(arr5, 8), 6) == 3.105295);
  assert(roundTo(sampleStandardDeviation(arr6, 7), 6) == 26.386324);
  arr5[3] = 3;
  arr5 = mode(arr5, 8, &nOfModes);
  assert(arr5[0] == 2 && arr5[1] == 3 && nOfModes == 2);
  free(arr5);
  assert(roundTo(weightedMean(matrix1, 8), 6) == 2.933333);
  assert(roundTo(weightedMean(matrix2, 7), 6) == 3.731183);
  free(matrix1);
  free(matrix2);
  assert(arr7[0] == 3 && arr7[1] == -2);
  arr7 = equationOfLine(3, 7, 5, 11);
  assert(arr7[0] == 2 && arr7[1] == 1);
  arr7 = midpointPoints(1, 1, 2, 4);
  assert(arr7[0] == 1.5 && arr7[1] == 2.5);
  arr7 = midpointPoints(3, 7, 5, 11);
  assert(arr7[0] == 4 && arr7[1] == 9);
  free(arr7);
  assert(isPrime(7919));
  assert(!isPrime(5329));
  assert(isPerfect(6));
  assert(!isPerfect(7));
  assert(isHappy(23));
  assert(!isHappy(73));
  assert(isArmstrong(370));
  assert(!isArmstrong(125));
  assert(nthRoot(4096, 4) == 8);
  assert(round(nthRoot(389017, 3)) == 73);
  assert(logarithm(1024, 4) == 5);
  assert(logarithm(389017, 73) == 3);
  assert(nPercentOfX(725, 5) == 36.25);
  assert(nPercentOfX(1024, 25) == 256);
  assert(nIsWhatPercentOfX(95, 7.6) == 8);
  assert(nIsWhatPercentOfX(128, 16) == 12.5);
  assert(simpleGrowth(5, 0.05, 3) == 5.75);
  assert(simpleGrowth(140, 0.1, 4) == 196);
  assert(roundTo(simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
  assert(roundTo(simpleGrowthRate(145, 153, 3), 6) == 0.018391);
  assert(roundTo(compoundedGrowth(5, 0.2, 3), 6) == 8.64);
  assert(roundTo(compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092);
  assert(roundTo(compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
  assert(roundTo(compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08);
  assert(gcd(40, 96) == 8);
  assert(gcd(42, 9) == 3);
  assert(lcm(6, 15) == 30);
  assert(lcm(39, 9) == 117);
  assert(factorial(20) == 2432902008176640000);
  assert(factorial(17) == 355687428096000);
  assert(permutation(6) == 720);
  assert(permutation(8) == 40320);
  assert(cyclePermutation(9) == 40320);
  assert(cyclePermutation(6) == 120);
  assert(arrangement(17, 11) == 494010316800);
  assert(arrangement(9, 6) == 60480);
  assert(combination(19, 15) == 3876);
  assert(combination(9, 5) == 126);
  sprintf(str, "%e", factoriallf(60));
  assert(strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
  sprintf(str, "%e", factoriallf(73));
  assert(strcmp(str, "4.470115e+105") == 0);
  sprintf(str, "%e", permutationlf(40));
  assert(strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
  sprintf(str, "%e", permutationlf(27));
  assert(strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
  sprintf(str, "%e", cyclePermutationlf(36));
  assert(strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
  sprintf(str, "%e", cyclePermutationlf(33));
  assert(strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
  assert(round(arrangementlf(60, 6)) == 36045979200);
  assert(round(arrangementlf(100, 7)) == 80678106432000);
  assert(round(combinationlf(30, 21)) == 14307150);
  assert(round(combinationlf(29, 15)) == 77558760);
  assert(roundTo(binominal(10, 0.2, 6), 6) == 0.005505);
  assert(binominal(4, 0.25, 1) == 0.421875);
  assert(roundTo(poisson(0.45, 4), 5) == 0.00109);
  assert(roundTo(poisson(0.75, 5), 5) == 0.00093);
  assert(roundTo(gaussianCDF(0, 1, 3.5), 5) == 0.99977);
  assert(roundTo(gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
  assert(hypotenuse(3, 4) == 5);
  assert(roundTo(hypotenuse(7, 8), 5) == 10.63015);
  assert(roundTo(sideRightTriangle(4, 2), 6) == 3.464102);
  assert(sideRightTriangle(15, 12) == 9);
  assert(roundTo(sideTriangleLC(4, 3, degrees2radians(60)), 6) == 3.605551);
  assert(roundTo(sideTriangleLC(9, 7, degrees2radians(30)), 5) == 4.56955);
  assert(round(radians2degrees(angleTriangleLC(2, 4, 3.464102))) == 30);
  assert(roundTo(angleTriangleLC(5, 7, 9), 5) == 0.58569);
  assert(roundTo(sideTriangleLS(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979);
  assert(roundTo(sideTriangleLS(degrees2radians(45), 8, degrees2radians(30)), 5) == 11.31371);
  assert(round(radians2degrees(angleTriangleLS(4, 4, degrees2radians(45)))) == 45);
  assert(roundTo(angleTriangleLS(10, 8, degrees2radians(30)), 5) == 0.67513);
  assert(triangleArea1(4, 5) == 10);
  assert(roundTo(triangleArea2(2, 4, degrees2radians(60)), 4) == 3.4641);
  assert(triangleArea3(3, 4, 5) == 6);
  assert(squareArea(4) == 16);
  assert(retangleArea(4, 6) == 24);
  assert(rhombusArea(4, 6) == 12);
  assert(parallelogramArea1(3, 5) == 15);
  assert(roundTo(parallelogramArea2(4, 6, M_PI / 6), 6) == 12);
  assert(trapezoidArea(7, 5, 3) == 18);
  assert(roundTo(regularPolygonArea(5, 6), 4) == 64.9519);
  assert(roundTo(circleArea(4), 6) == 50.265482);
  assert(roundTo(circularSectorArea1(degrees2radians(45), 4), 6) == 6.283185);
  assert(circularSectorArea2(6, 4) == 12);
  assert(roundTo(ellipseArea(4, 6), 6) == 75.398224);
  assert(cubeArea(4) == 96);
  assert(cuboidArea(4, 5, 6) == 148);
  assert(prismArea(16, 16, 5) == 112);
  assert(regularPrismArea(4, 4, 5) == 112);
  assert(roundTo(pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
  assert(roundTo(regularPyramidArea(3, 4, 4), 6) == 34.632011);
  assert(roundTo(cylinderArea(2, 5.5), 6) == 94.24778);
  assert(roundTo(coneArea(4, 6), 6) == 140.88287);
  assert(roundTo(sphereArea(4), 6) == 201.06193);
  assert(cubeVol(4) == 64);
  assert(cuboidVol(4, 5, 6) == 120);
  assert(round(prismVol(16, 5)) == 80);
  assert(round(regularPrismVol(4, 4, 5)) == 80);
  assert(round(pyramidVol(9, 4)) == 12);
  assert(round(regularPyramidVol(3, 4, 4)) == 12);
  assert(roundTo(cylinderVol(2, 5.5), 6) == 69.115038);
  assert(roundTo(coneVol(4, 6), 6) == 100.530965);
  assert(roundTo(sphereVol(4), 6) == 268.082573);
  assert(distancePoints(-1, -1, 2, 3) == 5);
  assert(roundTo(distancePointLine(3, -2, 0, 0), 6) == 0.632456);
  assert(slopeOfLine(1, 1, 2, 4) == 3);
  assert(roundTo(radians2degrees(angleOfInclineLine(1, 1, 2, 4)), 6) == 71.565051);
  assert(roundTo(circlePerimeter(5), 6) == 31.415927);
  assert(nOfDiagnonalsPolygon(6) == 9);
  assert(round(radians2degrees(regularPolygonSumInteriorAngles(5))) == 540);
  assert(round(radians2degrees(regularPolygonInteriorAngle(5))) == 108);
  assert(round(radians2degrees(regularPolygonExteriorAngle(5))) == 72);

  puts("Passed all tests successfully!");

  return 0;
}
