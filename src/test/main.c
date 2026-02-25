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
 * @brief Main function to test mathematical algorithms.
 * This is the main function used to test different mathematical algorithms
 * by comparing the results with pre-calculated values. It serves as a testing
 * ground for verifying the correctness of the algorithms.
 * 
 * @return An integer representing the exit status of the program.
*/

int main()
{
  char str[100];
  unsigned nOfModes;
  int i;
  const int SIZE_OF_MATRIZ1 = 8,
            SIZE_OF_MATRIZ2 = 7;
  long long arr1[8] = {2, 2, 2, 2, 3, 3, 5, 11},
            arr2[7] = {2, 2, 3, 3, 3, 7, 73},
            *arr3 = primeFactors(7920),
            *arr4 = primeFactors(55188);
  double *arr5 = NULL,
         *arr6 = (double *)malloc(sizeof(*arr6) * 8),
         *arr7 = (double *)malloc(sizeof(*arr7) * 7),
         *arr8 = equationOfLine(1, 1, 2, 4),
         **matrix1 = (double **)malloc(sizeof(*matrix1) * SIZE_OF_MATRIZ1),
         **matrix2 = (double **)malloc(sizeof(*matrix2) * SIZE_OF_MATRIZ2);

  for (i = 0; i < SIZE_OF_MATRIZ1; i++)
    matrix1[i] = (double *)malloc(sizeof(**matrix1) * 2);
  for (i = 0; i < SIZE_OF_MATRIZ2; i++)
    matrix2[i] = (double *)malloc(sizeof(**matrix2) * 2);
  for (i = 0; i < 8; i++)
    arr6[i] = matrix1[i][0] = matrix1[7 - i][1] = (double)arr1[i];
  for (i = 0; i < 7; i++)
    arr7[i] = matrix2[i][0] = matrix2[6 - i][1] = (double)arr2[i];
  if (test(1, arrayCmp(arr1, arr3, 8)) != 0)
    goto cleanup;
  if (test(2, arrayCmp(arr2, arr4, 7)) != 0)
    goto cleanup;
  if (test(3, roundTo(M_PI, 2) == 3.14) != 0)
    goto cleanup;
  if (test(4, roundTo(sqrt(2), 2) == 1.41) != 0)
    goto cleanup;
  if (test(5, mean(arr6, 8) == 3.75) != 0)
    goto cleanup;
  if (test(6, roundTo(mean(arr7, 7), 6) == 13.285714) != 0)
    goto cleanup;
  if (test(7, roundTo(geometricMean(arr6, 8), 6) == 3.07143) != 0)
    goto cleanup;
  if (test(8, roundTo(geometricMean(arr7, 7), 6) == 4.757802) != 0)
    goto cleanup;
  if (test(9, roundTo(harmonicMean(arr6, 8), 6) == 2.704918) != 0)
    goto cleanup;
  if (test(10, roundTo(harmonicMean(arr7, 7), 6) == 3.245917) != 0)
    goto cleanup;
  if (test(11, roundTo(trimmedMean(arr6, 8, 12), 6) == 2.833333) != 0)
    goto cleanup;
  if (test(12, trimmedMean(arr7, 7, 14) == 3.6) != 0)
    goto cleanup;
  if (test(13, median(arr6, 8) == 2.5) != 0)
    goto cleanup;
  if (test(14, median(arr7, 7) == 3) != 0)
    goto cleanup;
  arr5 = mode(arr6, 8, &nOfModes);
  if (test(15, arr5[0] == 2 && nOfModes == 1) != 0)
    goto cleanup;
  free(arr5);
  arr5 = mode(arr7, 7, &nOfModes);
  if (test(16, arr5[0] == 3 && nOfModes == 1) != 0)
    goto cleanup;
  if (test(17, min(arr6, 8) == 2) != 0)
    goto cleanup;
  if (test(18, min(arr7, 7) == 2) != 0)
    goto cleanup;
  if (test(19, max(arr6, 8) == 11) != 0)
    goto cleanup;
  if (test(20, max(arr7, 7) == 73) != 0)
    goto cleanup;
  if (test(21, range(arr6, 8) == 9) != 0)
    goto cleanup;
  if (test(22, range(arr7, 7) == 71) != 0)
    goto cleanup;
  if (test(23, midrange(arr6, 8) == 4.5) != 0)
    goto cleanup;
  if (test(24, midrange(arr7, 7) == 35.5) != 0)
    goto cleanup;
  if (test(25, roundTo(variance(arr6, 8), 6) == 8.4375) != 0)
    goto cleanup;
  if (test(26, roundTo(variance(arr7, 7), 6) == 596.775510) != 0)
    goto cleanup;
  if (test(27, roundTo(sampleVariance(arr6, 8), 6) == 9.642857) != 0)
    goto cleanup;
  if (test(28, roundTo(sampleVariance(arr7, 7), 6) == 696.238095) != 0)
    goto cleanup;
  if (test(29, roundTo(standardDeviation(arr6, 8), 6) == 2.904738) != 0)
    goto cleanup;
  if (test(30, roundTo(standardDeviation(arr7, 7), 6) == 24.428989) != 0)
    goto cleanup;
  if (test(31, roundTo(sampleStandardDeviation(arr6, 8), 6) == 3.105295) != 0)
    goto cleanup;
  if (test(32, roundTo(sampleStandardDeviation(arr7, 7), 6) == 26.386324) != 0)
    goto cleanup;
  arr6[3] = 3;
  free(arr5);
  arr5 = mode(arr6, 8, &nOfModes);
  if (test(33, arr5[0] == 2 && arr5[1] == 3 && nOfModes == 2) != 0)
    goto cleanup;
  if (test(34, roundTo(weightedMean(matrix1, 8), 6) == 2.933333) != 0)
    goto cleanup;
  if (test(35, roundTo(weightedMean(matrix2, 7), 6) == 3.731183) != 0)
    goto cleanup;
  if (test(36, arr8[0] == 3 && arr8[1] == -2) != 0)
    goto cleanup;
  free(arr8);
  arr8 = equationOfLine(3, 7, 5, 11);
  if (test(37, arr8[0] == 2 && arr8[1] == 1) != 0)
    goto cleanup;
  free(arr8);
  arr8 = midpointPoints(1, 1, 2, 4);
  if (test(38, arr8[0] == 1.5 && arr8[1] == 2.5) != 0)
    goto cleanup;
  free(arr8);
  arr8 = midpointPoints(3, 7, 5, 11);
  if (test(39, arr8[0] == 4 && arr8[1] == 9) != 0)
    goto cleanup;
  if (test(40, isPrime(7919)) != 0)
    goto cleanup;
  if (test(41, !isPrime(5329)) != 0)
    goto cleanup;
  if (test(42, isPerfect(6)) != 0)
    goto cleanup;
  if (test(43, !isPerfect(7)) != 0)
    goto cleanup;
  if (test(44, isHappy(23)) != 0)
    goto cleanup;
  if (test(45, !isHappy(73)) != 0)
    goto cleanup;
  if (test(46, isArmstrong(370)) != 0)
    goto cleanup;
  if (test(47, !isArmstrong(125)) != 0)
    goto cleanup;
  if (test(48, nthRoot(4096, 4) == 8) != 0)
    goto cleanup;
  if (test(49, round(nthRoot(389017, 3)) == 73) != 0)
    goto cleanup;
  if (test(50, logarithm(1024, 4) == 5) != 0)
    goto cleanup;
  if (test(51, logarithm(389017, 73) == 3) != 0)
    goto cleanup;
  if (test(52, nPercentOfX(725, 5) == 36.25) != 0)
    goto cleanup;
  if (test(53, nPercentOfX(1024, 25) == 256) != 0)
    goto cleanup;
  if (test(54, nIsWhatPercentOfX(95, 7.6) == 8) != 0)
    goto cleanup;
  if (test(55, nIsWhatPercentOfX(128, 16) == 12.5) != 0)
    goto cleanup;
  if (test(56, simpleGrowth(5, 0.05, 3) == 5.75) != 0)
    goto cleanup;
  if (test(57, simpleGrowth(140, 0.1, 4) == 196) != 0)
    goto cleanup;
  if (test(58, roundTo(simpleGrowthRate(5, 5.5, 4), 6) == 0.025) != 0)
    goto cleanup;
  if (test(59, roundTo(simpleGrowthRate(145, 153, 3), 6) == 0.018391) != 0)
    goto cleanup;
  if (test(60, roundTo(compoundedGrowth(5, 0.2, 3), 6) == 8.64) != 0)
    goto cleanup;
  if (test(61, roundTo(compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092) != 0)
    goto cleanup;
  if (test(62, roundTo(compoundedGrowthRate(5, 8.64, 3), 6) == 0.2) != 0)
    goto cleanup;
  if (test(63, roundTo(compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08) != 0)
    goto cleanup;
  if (test(64, gcd(40, 96) == 8) != 0)
    goto cleanup;
  if (test(65, gcd(42, 9) == 3) != 0)
    goto cleanup;
  if (test(66, lcm(6, 15) == 30) != 0)
    goto cleanup;
  if (test(67, lcm(39, 9) == 117) != 0)
    goto cleanup;
  if (test(68, factorial(20) == 2432902008176640000) != 0)
    goto cleanup;
  if (test(69, factorial(17) == 355687428096000) != 0)
    goto cleanup;
  if (test(70, permutation(6) == 720) != 0)
    goto cleanup;
  if (test(71, permutation(8) == 40320) != 0)
    goto cleanup;
  if (test(72, cyclePermutation(9) == 40320) != 0)
    goto cleanup;
  if (test(73, cyclePermutation(6) == 120) != 0)
    goto cleanup;
  if (test(74, arrangement(17, 11) == 494010316800) != 0)
    goto cleanup;
  if (test(75, arrangement(9, 6) == 60480) != 0)
    goto cleanup;
  if (test(76, combination(19, 15) == 3876) != 0)
    goto cleanup;
  if (test(77, combination(9, 5) == 126) != 0)
    goto cleanup;
  sprintf(str, "%e", factoriallf(60));
  if (test(78, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0) != 0)
    goto cleanup;
  sprintf(str, "%e", factoriallf(73));
  if (test(79, strcmp(str, "4.470115e+105") == 0) != 0)
    goto cleanup;
  sprintf(str, "%e", permutationlf(40));
  if (test(80, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0) != 0)
    goto cleanup;
  sprintf(str, "%e", permutationlf(27));
  if (test(81, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0) != 0)
    goto cleanup;
  sprintf(str, "%e", cyclePermutationlf(36));
  if (test(82, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0) != 0)
    goto cleanup;
  sprintf(str, "%e", cyclePermutationlf(33));
  if (test(83, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0) != 0)
    goto cleanup;
  if (test(84, round(arrangementlf(60, 6)) == 36045979200) != 0)
    goto cleanup;
  if (test(85, round(arrangementlf(100, 7)) == 80678106432000) != 0)
    goto cleanup;
  if (test(86, round(combinationlf(30, 21)) == 14307150) != 0)
    goto cleanup;
  if (test(87, round(combinationlf(29, 15)) == 77558760) != 0)
    goto cleanup;
  if (test(88, roundTo(binominal(10, 0.2, 6), 6) == 0.005505) != 0)
    goto cleanup;
  if (test(89, binominal(4, 0.25, 1) == 0.421875) != 0)
    goto cleanup;
  if (test(90, roundTo(poisson(0.45, 4), 5) == 0.00109) != 0)
    goto cleanup;
  if (test(91, roundTo(poisson(0.75, 5), 5) == 0.00093) != 0)
    goto cleanup;
  if (test(92, roundTo(gaussianCDF(0, 1, 3.5), 5) == 0.99977) != 0)
    goto cleanup;
  if (test(93, roundTo(gaussianCDF(150000, 5000, 135000), 5) == 0.00135) != 0)
    goto cleanup;
  if (test(94, hypotenuse(3, 4) == 5) != 0)
    goto cleanup;
  if (test(95, roundTo(hypotenuse(7, 8), 5) == 10.63015) != 0)
    goto cleanup;
  if (test(96, roundTo(sideRightTriangle(4, 2), 6) == 3.464102) != 0)
    goto cleanup;
  if (test(97, sideRightTriangle(15, 12) == 9) != 0)
    goto cleanup;
  if (test(98, roundTo(sideTriangleLC(4, 3, degrees2radians(60)), 6) == 3.605551) != 0)
    goto cleanup;
  if (test(99, roundTo(sideTriangleLC(9, 7, degrees2radians(30)), 5) == 4.56955) != 0)
    goto cleanup;
  if (test(100, round(radians2degrees(angleTriangleLC(2, 4, 3.464102))) == 30) != 0)
    goto cleanup;
  if (test(101, roundTo(angleTriangleLC(5, 7, 9), 5) == 0.58569) != 0)
    goto cleanup;
  if (test(102, roundTo(sideTriangleLS(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979) != 0)
    goto cleanup;
  if (test(103, roundTo(sideTriangleLS(degrees2radians(45), 8, degrees2radians(30)), 5) == 11.31371) != 0)
    goto cleanup;
  if (test(104, round(radians2degrees(angleTriangleLS(4, 4, degrees2radians(45)))) == 45) != 0)
    goto cleanup;
  if (test(105, roundTo(angleTriangleLS(10, 8, degrees2radians(30)), 5) == 0.67513) != 0)
    goto cleanup;
  if (test(106, triangleArea1(4, 5) == 10) != 0)
    goto cleanup;
  if (test(107, triangleArea1(7, 8) == 28) != 0)
    goto cleanup;
  if (test(108, roundTo(triangleArea2(2, 4, degrees2radians(60)), 4) == 3.4641) != 0)
    goto cleanup;
  if (test(109, roundTo(triangleArea2(8, 7, degrees2radians(54)), 5) == 22.65248) != 0)
    goto cleanup;
  if (test(110, triangleArea3(3, 4, 5) == 6) != 0)
    goto cleanup;
  if (test(111, roundTo(triangleArea3(10, 8, 5), 5) == 19.81004) != 0)
    goto cleanup;
  if (test(112, squareArea(4) == 16) != 0)
    goto cleanup;
  if (test(113, squareArea(7) == 49) != 0)
    goto cleanup;
  if (test(114, retangleArea(4, 6) == 24) != 0)
    goto cleanup;
  if (test(115, retangleArea(3, 7) == 21) != 0)
    goto cleanup;
  if (test(116, rhombusArea(5, 6) == 15) != 0)
    goto cleanup;
  if (test(117, rhombusArea(7, 8) == 28) != 0)
    goto cleanup;
  if (test(118, parallelogramArea1(3, 5) == 15) != 0)
    goto cleanup;
  if (test(119, parallelogramArea1(4, 7) == 28) != 0)
    goto cleanup;
  if (test(120, roundTo(parallelogramArea2(4, 6, degrees2radians(30)), 6) == 12) != 0)
    goto cleanup;
  if (test(121, roundTo(parallelogramArea2(7, 5, degrees2radians(36)), 6) == 20.572484) != 0)
    goto cleanup;
  if (test(122, trapezoidArea(7, 5, 3) == 18) != 0)
    goto cleanup;
  if (test(123, trapezoidArea(8, 12, 4) == 40) != 0)
    goto cleanup;
  if (test(124, roundTo(regularPolygonArea(7, 3), 5) == 21.21762) != 0)
    goto cleanup;
  if (test(125, roundTo(regularPolygonArea(5, 6), 4) == 64.9519) != 0)
    goto cleanup;
  if (test(126, roundTo(circleArea(4), 6) == 50.265482) != 0)
    goto cleanup;
  if (test(127, roundTo(circleArea(8), 6) == 201.06193) != 0)
    goto cleanup;
  if (test(128, roundTo(circularSectorArea1(degrees2radians(45), 4), 6) == 6.283185) != 0)
    goto cleanup;
  if (test(129, roundTo(circularSectorArea1(degrees2radians(30), 7), 6) == 12.82817) != 0)
    goto cleanup;
  if (test(130, circularSectorArea2(6, 4) == 12) != 0)
    goto cleanup;
  if (test(131, roundTo(circularSectorArea2(3, 5), 6) == 7.5) != 0)
    goto cleanup;
  if (test(132, roundTo(ellipseArea(4, 6), 6) == 75.398224) != 0)
    goto cleanup;
  if (test(133, roundTo(ellipseArea(3, 5), 6) == 47.12389) != 0)
    goto cleanup;
  if (test(134, cubeArea(4) == 96) != 0)
    goto cleanup;
  if (test(135, cubeArea(8) == 384) != 0)
    goto cleanup;
  if (test(136, cuboidArea(4, 5, 6) == 148) != 0)
    goto cleanup;
  if (test(137, cuboidArea(7, 3, 5) == 142) != 0)
    goto cleanup;
  if (test(138, prismArea(16, 16, 5) == 112) != 0)
    goto cleanup;
  if (test(139, prismArea(21.21762, 21, 9) == 231.43524) != 0)
    goto cleanup;
  if (test(140, regularPrismArea(4, 4, 5) == 112) != 0)
    goto cleanup;
  if (test(141, roundTo(regularPrismArea(3, 3, 7), 6) == 70.794229) != 0)
    goto cleanup;
  if (test(142, roundTo(pyramidArea(9, 12, 4.2720018), 6) == 34.632011) != 0)
    goto cleanup;
  if (test(143, pyramidArea(16, 16, 5) == 56) != 0)
    goto cleanup;
  if (test(144, roundTo(regularPyramidArea(3, 4, 4), 6) == 34.632011) != 0)
    goto cleanup;
  if (test(145, roundTo(regularPyramidArea(4, 6, 7), 6) == 135.292215) != 0)
    goto cleanup;
  if (test(146, roundTo(cylinderArea(2, 5.5), 6) == 94.24778) != 0)
    goto cleanup;
  if (test(147, roundTo(cylinderArea(4, 8), 6) == 301.592895) != 0)
    goto cleanup;
  if (test(148, roundTo(coneArea(4, 6), 6) == 140.88287) != 0)
    goto cleanup;
  if (test(149, roundTo(coneArea(3.5, 7), 6) == 124.53849) != 0)
    goto cleanup;
  if (test(150, roundTo(sphereArea(4), 6) == 201.06193) != 0)
    goto cleanup;
  if (test(151, roundTo(sphereArea(7), 6) == 615.75216) != 0)
    goto cleanup;
  if (test(152, cubeVol(4) == 64) != 0)
    goto cleanup;
  if (test(153, cubeVol(8) == 512) != 0)
    goto cleanup;
  if (test(154, cuboidVol(4, 5, 6) == 120) != 0)
    goto cleanup;
  if (test(155, cuboidVol(7, 3, 5) == 105) != 0)
    goto cleanup;
  if (test(156, round(prismVol(16, 5)) == 80) != 0)
    goto cleanup;
  if (test(157, round(prismVol(20, 7)) == 140) != 0)
    goto cleanup;
  if (test(158, round(regularPrismVol(4, 4, 5)) == 80) != 0)
    goto cleanup;
  if (test(159, roundTo(regularPrismVol(3, 3, 7), 6) == 27.2798) != 0)
    goto cleanup;
  if (test(160, round(pyramidVol(9, 4)) == 12) != 0)
    goto cleanup;
  if (test(161, roundTo(pyramidVol(16, 5), 6) == 26.666667) != 0)
    goto cleanup;
  if (test(162, round(regularPyramidVol(3, 4, 4)) == 12) != 0)
    goto cleanup;
  if (test(163, round(regularPyramidVol(4, 6, 7)) == 97) != 0)
    goto cleanup;
  if (test(164, roundTo(cylinderVol(2, 5.5), 6) == 69.115038) != 0)
    goto cleanup;
  if (test(165, roundTo(cylinderVol(4, 8), 6) == 402.12386) != 0)
    goto cleanup;
  if (test(166, roundTo(coneVol(4, 6), 6) == 100.530965) != 0)
    goto cleanup;
  if (test(167, roundTo(coneVol(3.5, 7), 6) == 89.79719) != 0)
    goto cleanup;
  if (test(168, roundTo(sphereVol(4), 6) == 268.082573) != 0)
    goto cleanup;
  if (test(169, roundTo(sphereVol(7), 6) == 1436.75504) != 0)
    goto cleanup;
  if (test(170, distancePoints(-1, -1, 2, 3) == 5) != 0)
    goto cleanup;
  if (test(171, roundTo(distancePoints(1, 2, 7, 11), 6) == 10.816654) != 0)
    goto cleanup;
  if (test(172, roundTo(distancePointLine(3, -2, 0, 0), 6) == 0.632456) != 0)
    goto cleanup;
  if (test(173, roundTo(distancePointLine(1, -5, 2, 2), 6) == 3.535534) != 0)
    goto cleanup;
  if (test(174, slopeOfLine(1, 1, 2, 4) == 3) != 0)
    goto cleanup;
  if (test(175, slopeOfLine(-4, 1, 5, 7) == 2.0 / 3) != 0)
    goto cleanup;
  if (test(176, roundTo(radians2degrees(angleOfInclineLine(1, 1, 2, 4)), 6) == 71.565051) != 0)
    goto cleanup;
  if (test(177, roundTo(radians2degrees(angleOfInclineLine(-4, 1, 5, 7)), 6) == 33.690068) != 0)
    goto cleanup;
  if (test(178, roundTo(circlePerimeter(5), 6) == 31.415927) != 0)
    goto cleanup;
  if (test(179, roundTo(circlePerimeter(7), 6) == 43.982297) != 0)
    goto cleanup;
  if (test(180, nOfDiagnonalsPolygon(6) == 9) != 0)
    goto cleanup;
  if (test(181, nOfDiagnonalsPolygon(4) == 2) != 0)
    goto cleanup;
  if (test(182, round(radians2degrees(convexPolygonSumInteriorAngles(5))) == 540) != 0)
    goto cleanup;
  if (test(183, round(radians2degrees(convexPolygonSumInteriorAngles(6))) == 720) != 0)
    goto cleanup;
  if (test(184, round(radians2degrees(regularPolygonInteriorAngle(5))) == 108) != 0)
    goto cleanup;
  if (test(185, round(radians2degrees(regularPolygonInteriorAngle(6))) == 120) != 0)
    goto cleanup;
  if (test(186, round(radians2degrees(convexPolygonExteriorAngle(5))) == 72) != 0)
    goto cleanup;
  if (test(187, round(radians2degrees(convexPolygonExteriorAngle(6))) == 60) != 0)
    goto cleanup;
  if (test(188, nOfDiagnonalsPolygon(3) == 0) != 0)
    goto cleanup;
  if (test(189, round(radians2degrees(convexPolygonSumInteriorAngles(3))) == 180) != 0)
    goto cleanup;
  if (test(190, round(radians2degrees(regularPolygonInteriorAngle(3))) == 60) != 0)
    goto cleanup;
  if (test(191, round(radians2degrees(convexPolygonExteriorAngle(3))) == 120) != 0)
    goto cleanup;
  if (test(192, arrangement(7, 0) == 1) != 0)
    goto cleanup;
  if (test(193, arrangementlf(7, 0) == 1) != 0)
    goto cleanup;
  if (test(194, roundTo(sideTriangleLC(5, 7, degrees2radians(179)), 5) == 11.99956) != 0)
    goto cleanup;
  if (test(195, roundTo(logarithm(1000, 10), 6) == 3) != 0)
    goto cleanup;

  puts("Passed all tests successfully!\n");

  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(arr8);
  for (i = 0; i < SIZE_OF_MATRIZ1; i++)
    free(matrix1[i]);
  for (i = 0; i < SIZE_OF_MATRIZ2; i++)
    free(matrix2[i]);
  free(matrix1);
  free(matrix2);

  return 0;

cleanup:
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(arr8);
  for (i = 0; i < SIZE_OF_MATRIZ1; i++)
    free(matrix1[i]);
  for (i = 0; i < SIZE_OF_MATRIZ2; i++)
    free(matrix2[i]);
  free(matrix1);
  free(matrix2);

  return -1;
}
