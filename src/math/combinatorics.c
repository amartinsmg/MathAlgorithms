#include "internal/mathlib_c.h"
#include <errno.h>
#include <stdio.h>

long long permutation(int num) {
  long long result;
  result = factorial(num);
  return result;
}

long long cyclePermutation(int num) {
  if (num <= 1)
    return 1;
  long long result;
  result = factorial(num - 1);
  return result;
}

long long arrangement(int total, int selected) {
  if (total <= 0 || selected > total) {
    errno = EDOM;
    perror("Error calculating arrangement");
    return 0;
  }
  long long result;
  result = factorial(total) / factorial(total - selected);
  return result;
}

long long combination(int total, int selected) {
  if (total <= 0 || selected > total) {
    errno = EDOM;
    perror("Error calculating combination");
    return 0;
  }
  long long result;
  result =
      factorial(total) / (factorial(selected) * factorial(total - selected));
  return result;
}

double permutationlf(int num) {
  double result = factoriallf(num);
  return result;
}

double cyclePermutationlf(int num) {
  if (num == 1 || num == 0)
    return 1;
  double result = factoriallf(num - 1);
  return result;
}

double arrangementlf(int total, int selected) {
  if (total <= 0 || selected > total)
    return NAN;
  double result = factoriallf(total) / factoriallf(total - selected);
  return result;
}

double combinationlf(int total, int selected) {
  if (total <= 0 || selected > total)
    return NAN;
  double result = factoriallf(total) /
                  (factoriallf(selected) * factoriallf(total - selected));
  return result;
}
