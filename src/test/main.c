#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <armstrong_numbers.h>
#include <basic_operations.h>
#include <combinatorics.h>
#include <factorial.h>
#include <gcd.h>
#include <geometry.h>
#include <growth.h>
#include <happy_numbers.h>
#include <lcm.h>
#include <percentage.h>
#include <perfect_numbers.h>
#include <prime_factorization.h>
#include <prime_numbers.h>
#include <probability_distribution.h>
#include <statistics.h>
#include <trigonometry.h>
#include "include/array_cmp.h"
#include "include/test.h"

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
  test(1, arrayCmp(arr1, arr3, 8));
  test(2, arrayCmp(arr2, arr4, 7));
  free(arr3);
  free(arr4);
  test(3, roundTo(M_PI, 2) == 3.14);
  test(4, roundTo(sqrt(2), 2) == 1.41);
  test(5, mean(arr5, 8) == 3.75);
  test(6, roundTo(mean(arr6, 7), 6) == 13.285714);
  test(7, roundTo(geometricMean(arr5, 8), 6) == 3.07143);
  test(8, roundTo(geometricMean(arr6, 7), 6) == 4.757802);
  test(9, roundTo(harmonicMean(arr5, 8), 6) == 2.704918);
  test(10, roundTo(harmonicMean(arr6, 7), 6) == 3.245917);
  test(11, roundTo(trimmedMean(arr5, 8, 12), 6) == 2.833333);
  test(12, trimmedMean(arr6, 7, 14) == 3.6);
  test(13, median(arr5, 8) == 2.5);
  test(14, median(arr6, 7) == 3);
  test(15, mode(arr5, 8, &nOfModes)[0] == 2 && nOfModes == 1);
  test(16, mode(arr6, 7, &nOfModes)[0] == 3 && nOfModes == 1);
  test(17, min(arr5, 8) == 2);
  test(18, min(arr6, 7) == 2);
  test(19, max(arr5, 8) == 11);
  test(20, max(arr6, 7) == 73);
  test(21, range(arr5, 8) == 9);
  test(22, range(arr6, 7) == 71);
  test(23, midrange(arr5, 8) == 4.5);
  test(24, midrange(arr6, 7) == 35.5);
  test(25, roundTo(variance(arr5, 8), 6) == 8.4375);
  test(26, roundTo(variance(arr6, 7), 6) == 596.775510);
  test(27, roundTo(sampleVariance(arr5, 8), 6) == 9.642857);
  test(28, roundTo(sampleVariance(arr6, 7), 6) == 696.238095);
  test(29, roundTo(standardDeviation(arr5, 8), 6) == 2.904738);
  test(30, roundTo(standardDeviation(arr6, 7), 6) == 24.428989);
  test(31, roundTo(sampleStandardDeviation(arr5, 8), 6) == 3.105295);
  test(32, roundTo(sampleStandardDeviation(arr6, 7), 6) == 26.386324);
  arr5[3] = 3;
  arr5 = mode(arr5, 8, &nOfModes);
  test(33, arr5[0] == 2 && arr5[1] == 3 && nOfModes == 2);
  free(arr5);
  test(34, roundTo(weightedMean(matrix1, 8), 6) == 2.933333);
  test(35, roundTo(weightedMean(matrix2, 7), 6) == 3.731183);
  free(matrix1);
  free(matrix2);
  test(36, arr7[0] == 3 && arr7[1] == -2);
  arr7 = equationOfLine(3, 7, 5, 11);
  test(37, arr7[0] == 2 && arr7[1] == 1);
  arr7 = midpointPoints(1, 1, 2, 4);
  test(38, arr7[0] == 1.5 && arr7[1] == 2.5);
  arr7 = midpointPoints(3, 7, 5, 11);
  test(39, arr7[0] == 4 && arr7[1] == 9);
  free(arr7);
  test(40, isPrime(7919));
  test(41, !isPrime(5329));
  test(42, isPerfect(6));
  test(43, !isPerfect(7));
  test(44, isHappy(23));
  test(45, !isHappy(73));
  test(46, isArmstrong(370));
  test(47, !isArmstrong(125));
  test(48, nthRoot(4096, 4) == 8);
  test(49, round(nthRoot(389017, 3)) == 73);
  test(50, logarithm(1024, 4) == 5);
  test(51, logarithm(389017, 73) == 3);
  test(52, nPercentOfX(725, 5) == 36.25);
  test(53, nPercentOfX(1024, 25) == 256);
  test(54, nIsWhatPercentOfX(95, 7.6) == 8);
  test(55, nIsWhatPercentOfX(128, 16) == 12.5);
  test(56, simpleGrowth(5, 0.05, 3) == 5.75);
  test(57, simpleGrowth(140, 0.1, 4) == 196);
  test(58, roundTo(simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
  test(59, roundTo(simpleGrowthRate(145, 153, 3), 6) == 0.018391);
  test(60, roundTo(compoundedGrowth(5, 0.2, 3), 6) == 8.64);
  test(61, roundTo(compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092);
  test(62, roundTo(compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
  test(63, roundTo(compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08);
  test(64, gcd(40, 96) == 8);
  test(65, gcd(42, 9) == 3);
  test(66, lcm(6, 15) == 30);
  test(67, lcm(39, 9) == 117);
  test(68, factorial(20) == 2432902008176640000);
  test(69, factorial(17) == 355687428096000);
  test(70, permutation(6) == 720);
  test(71, permutation(8) == 40320);
  test(72, cyclePermutation(9) == 40320);
  test(73, cyclePermutation(6) == 120);
  test(74, arrangement(17, 11) == 494010316800);
  test(75, arrangement(9, 6) == 60480);
  test(76, combination(19, 15) == 3876);
  test(77, combination(9, 5) == 126);
  sprintf(str, "%e", factoriallf(60));
  test(78, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
  sprintf(str, "%e", factoriallf(73));
  test(79, strcmp(str, "4.470115e+105") == 0);
  sprintf(str, "%e", permutationlf(40));
  test(80, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
  sprintf(str, "%e", permutationlf(27));
  test(81, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
  sprintf(str, "%e", cyclePermutationlf(36));
  test(82, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
  sprintf(str, "%e", cyclePermutationlf(33));
  test(83, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
  test(84, round(arrangementlf(60, 6)) == 36045979200);
  test(85, round(arrangementlf(100, 7)) == 80678106432000);
  test(86, round(combinationlf(30, 21)) == 14307150);
  test(87, round(combinationlf(29, 15)) == 77558760);
  test(88, roundTo(binominal(10, 0.2, 6), 6) == 0.005505);
  test(89, binominal(4, 0.25, 1) == 0.421875);
  test(90, roundTo(poisson(0.45, 4), 5) == 0.00109);
  test(91, roundTo(poisson(0.75, 5), 5) == 0.00093);
  test(92, roundTo(gaussianCDF(0, 1, 3.5), 5) == 0.99977);
  test(93, roundTo(gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
  test(94, hypotenuse(3, 4) == 5);
  test(95, roundTo(hypotenuse(7, 8), 5) == 10.63015);
  test(96, roundTo(sideRightTriangle(4, 2), 6) == 3.464102);
  test(97, sideRightTriangle(15, 12) == 9);
  test(98, roundTo(sideTriangleLC(4, 3, degrees2radians(60)), 6) == 3.605551);
  test(99, roundTo(sideTriangleLC(9, 7, degrees2radians(30)), 5) == 4.56955);
  test(100, round(radians2degrees(angleTriangleLC(2, 4, 3.464102))) == 30);
  test(101, roundTo(angleTriangleLC(5, 7, 9), 5) == 0.58569);
  test(102, roundTo(sideTriangleLS(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979);
  test(103, roundTo(sideTriangleLS(degrees2radians(45), 8, degrees2radians(30)), 5) == 11.31371);
  test(104, round(radians2degrees(angleTriangleLS(4, 4, degrees2radians(45)))) == 45);
  test(105, roundTo(angleTriangleLS(10, 8, degrees2radians(30)), 5) == 0.67513);
  test(106, triangleArea1(4, 5) == 10);
  test(107, triangleArea1(7, 8) == 28);
  test(108, roundTo(triangleArea2(2, 4, degrees2radians(60)), 4) == 3.4641);
  test(109, roundTo(triangleArea2(8, 7, degrees2radians(54)), 5) == 22.65248);
  test(110, triangleArea3(3, 4, 5) == 6);
  test(111, roundTo(triangleArea3(10, 8, 5), 5) == 19.81004);
  test(112, squareArea(4) == 16);
  test(113, squareArea(7) == 49);
  test(114, retangleArea(4, 6) == 24);
  test(115, retangleArea(3, 7) == 21);
  test(116, rhombusArea(5, 6) == 15);
  test(117, rhombusArea(7, 8) == 28);
  test(118, parallelogramArea1(3, 5) == 15);
  test(119, parallelogramArea1(4, 7) == 28);
  test(120, roundTo(parallelogramArea2(4, 6, degrees2radians(30)), 6) == 12);
  test(121, roundTo(parallelogramArea2(7, 5, degrees2radians(36)), 6) == 20.572484);
  test(122, trapezoidArea(7, 5, 3) == 18);
  test(123, trapezoidArea(8, 12, 4) == 40);
  test(124, roundTo(regularPolygonArea(7, 3), 5) == 21.21762);
  test(125, roundTo(regularPolygonArea(5, 6), 4) == 64.9519);
  test(126, roundTo(circleArea(4), 6) == 50.265482);
  test(127, roundTo(circleArea(8), 6) == 201.06193);
  test(128, roundTo(circularSectorArea1(degrees2radians(45), 4), 6) == 6.283185);
  test(129, roundTo(circularSectorArea1(degrees2radians(30), 7), 6) == 12.82817);
  test(130, circularSectorArea2(6, 4) == 12);
  test(131, roundTo(circularSectorArea2(3, 5), 6) == 7.5);
  test(132, roundTo(ellipseArea(4, 6), 6) == 75.398224);
  test(133, roundTo(ellipseArea(3, 5), 6) == 47.12389);
  test(134, cubeArea(4) == 96);
  test(135, cubeArea(8) == 384);
  test(136, cuboidArea(4, 5, 6) == 148);
  test(137, cuboidArea(7, 3, 5) == 142);
  test(138, prismArea(16, 16, 5) == 112);
  test(139, prismArea(21.21762, 21, 9) == 231.43524);
  test(140, regularPrismArea(4, 4, 5) == 112);
  test(141, roundTo(regularPrismArea(3, 3, 7), 6) == 70.794229);
  test(142, roundTo(pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
  test(143, pyramidArea(16, 16, 5) == 56);
  test(144, roundTo(regularPyramidArea(3, 4, 4), 6) == 34.632011);
  test(145, roundTo(regularPyramidArea(4, 6, 7), 6) == 135.292215);
  test(146, roundTo(cylinderArea(2, 5.5), 6) == 94.24778);
  test(147, roundTo(cylinderArea(4, 8), 6) == 301.592895);
  test(148, roundTo(coneArea(4, 6), 6) == 140.88287);
  test(149, roundTo(coneArea(3.5, 7), 6) == 124.53849);
  test(150, roundTo(sphereArea(4), 6) == 201.06193);
  test(151, roundTo(sphereArea(7), 6) == 615.75216);
  test(152, cubeVol(4) == 64);
  test(153, cubeVol(8) == 512);
  test(154, cuboidVol(4, 5, 6) == 120);
  test(155, cuboidVol(7, 3, 5) == 105);
  test(156, round(prismVol(16, 5)) == 80);
  test(157, round(prismVol(20, 7)) == 140);
  test(158, round(regularPrismVol(4, 4, 5)) == 80);
  test(159, roundTo(regularPrismVol(3, 3, 7), 6) == 27.2798);
  test(160, round(pyramidVol(9, 4)) == 12);
  test(161, roundTo(pyramidVol(16, 5), 6) == 26.666667);
  test(162, round(regularPyramidVol(3, 4, 4)) == 12);
  test(163, round(regularPyramidVol(4, 6, 7)) == 97);
  test(164, roundTo(cylinderVol(2, 5.5), 6) == 69.115038);
  test(165, roundTo(cylinderVol(4, 8), 6) == 402.12386);
  test(166, roundTo(coneVol(4, 6), 6) == 100.530965);
  test(167, roundTo(coneVol(3.5, 7), 6) == 89.79719);
  test(168, roundTo(sphereVol(4), 6) == 268.082573);
  test(169, roundTo(sphereVol(7), 6) == 1436.75504);
  test(170, distancePoints(-1, -1, 2, 3) == 5);
  test(171, roundTo(distancePoints(1, 2, 7, 11), 6) == 10.816654);
  test(172, roundTo(distancePointLine(3, -2, 0, 0), 6) == 0.632456);
  test(173, roundTo(distancePointLine(1, -5, 2, 2), 6) == 3.535534);
  test(174, slopeOfLine(1, 1, 2, 4) == 3);
  test(175, slopeOfLine(-4, 1, 5, 7) == 2.0 / 3);
  test(176, roundTo(radians2degrees(angleOfInclineLine(1, 1, 2, 4)), 6) == 71.565051);
  test(177, roundTo(radians2degrees(angleOfInclineLine(-4, 1, 5, 7)), 6) == 33.690068);
  test(178, roundTo(circlePerimeter(5), 6) == 31.415927);
  test(179, roundTo(circlePerimeter(7), 6) == 43.982297);
  test(180, nOfDiagnonalsPolygon(6) == 9);
  test(181, nOfDiagnonalsPolygon(4) == 2);
  test(182, round(radians2degrees(convexPolygonSumInteriorAngles(5))) == 540);
  test(183, round(radians2degrees(convexPolygonSumInteriorAngles(6))) == 720);
  test(184, round(radians2degrees(regularPolygonInteriorAngle(5))) == 108);
  test(185, round(radians2degrees(regularPolygonInteriorAngle(6))) == 120);
  test(186, round(radians2degrees(convexPolygonExteriorAngle(5))) == 72);
  test(187, round(radians2degrees(convexPolygonExteriorAngle(6))) == 60);
  test(188, nOfDiagnonalsPolygon(3) == 0);
  test(189, round(radians2degrees(convexPolygonSumInteriorAngles(3))) == 180);
  test(190, round(radians2degrees(regularPolygonInteriorAngle(3))) == 60);
  test(191, round(radians2degrees(convexPolygonExteriorAngle(3))) == 120);

  puts("Passed all tests successfully!");

  return 0;
}
