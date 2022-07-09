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
#include "statistical_measure.h"
#include "trigonometry.h"

double roundTo(double num, unsigned decimalPlaces)
{
  int base10 = pow(10, decimalPlaces);
  return round(num * base10) / base10;
}

int main()
{
  char str[100];
  int i;
  long long *array1 = (long long *)calloc(sizeof(long long), 64),
            *array2 = primeFactors(7920);
  double *array3 = (double *)calloc(sizeof(double), 8),
         **array4 = (double **)malloc(sizeof(double) * 8);
  for (i = 0; i < 8; i++)
    array4[i] = (double *)malloc(sizeof(double) * 2);
  array1[0] = array3[0] = array4[0][0] = array4[7][1] = 2;
  array1[1] = array3[1] = array4[1][0] = array4[6][1] = 2;
  array1[2] = array3[2] = array4[2][0] = array4[5][1] = 2;
  array1[3] = array3[3] = array4[3][0] = array4[4][1] = 2;
  array1[4] = array3[4] = array4[4][0] = array4[3][1] = 3;
  array1[5] = array3[5] = array4[5][0] = array4[2][1] = 3;
  array1[6] = array3[6] = array4[6][0] = array4[1][1] = 5;
  array1[7] = array3[7] = array4[7][0] = array4[0][1] = 11;
  for (i = 0; i < 64; i++)
    assert(array1[i] == array2[i]);
  free(array1);
  free(array2);
  assert(mean(array3, 8) == 3.75);
  assert(roundTo(variance(array3, 8), 6) == 8.4375);
  assert(roundTo(sampleVariance(array3, 8), 6) == 9.642857);
  assert(roundTo(standardDeviation(array3, 8), 6) == 2.904738);
  assert(roundTo(sampleStandardDeviation(array3, 8), 6) == 3.105295);
  assert(roundTo(geometricMean(array3, 8), 6) == 3.07143);
  assert(roundTo(harmonicMean(array3, 8), 6) == 2.704918);
  free(array3);
  assert(roundTo(weightedMean(array4, 8), 6) == 2.933333);
  free(array4);

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
  assert(strcmp(str, "8.320987e+081") == 0);
  sprintf(str, "%e", permutationlf(40));
  assert(strcmp(str, "8.159153e+047") == 0);
  sprintf(str, "%e", cyclePermutationlf(36));
  assert(strcmp(str, "1.033315e+040") == 0);
  sprintf(str, "%e", factoriallf(60));
  assert(strcmp(str, "8.320987e+081") == 0);
  assert(round(arrangementlf(60, 6)) == 36045979200);
  assert(round(combinationlf(30, 21)) == 14307150);
  assert(roundTo(binominal(10, 6, 0.2), 6) == 0.005505);
  assert(roundTo(poisson(4, 0.45), 5) == 0.00109);
  assert(roundTo(gaussianCDF(3.5, 0, 1), 5) == 0.99977);
  assert(roundTo(gaussianCDF(135000, 150000, 5000), 5) == 0.00135);
  assert(hypotenusePythagorean(3, 4) == 5);
  assert(roundTo(sideByPythagorean(4, 2), 6) == 3.464102);
  assert(roundTo(sideByLawOfCos(4, 3, degrees2radians(60)), 6) == 3.605551);
  assert((radians2degrees(angleByLawOfCos(2, 4, 3.464102))) == 30);
  assert(roundTo(sideByLawOfSin(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979);
  assert(round(radians2degrees(angleByLawOfSin(4, 4, degrees2radians(45)))) == 45);
  assert(distanceBetweenPoits(-1, -1, 2, 3) == 5);

  // printf("%f\n", radians2degrees(angleByLawOfCos(2, 4, 3.464102)));

  printf("Passed all tests successfully!\n");

  return 0;
}
