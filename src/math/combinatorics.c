#include "internal/mathlib_c.h"
#include <errno.h>
#include <stdio.h>

unsigned long long permutation(unsigned num) {
  unsigned long long result;
  result = factorial(num);
  return result;
}

unsigned long long cyclePermutation(unsigned num) {
  if (num <= 1)
    return 1;
  unsigned long long result;
  result = factorial(num - 1);
  return result;
}

unsigned long long arrangement(unsigned total, unsigned selected) {
  if (total == 0 || selected > total) {
    errno = EDOM;
    perror("Error calculating arrangement");
    return 0;
  }
  unsigned long long result;
  result = factorial(total) / factorial(total - selected);
  return result;
}

unsigned long long combination(unsigned total, unsigned selected) {
  if (total == 0 || selected > total) {
    errno = EDOM;
    perror("Error calculating combination");
    return 0;
  }
  unsigned long long result;
  result =
      factorial(total) / (factorial(selected) * factorial(total - selected));
  return result;
}

double permutationlf(unsigned num) {
  double result = factoriallf(num);
  return result;
}

double cyclePermutationlf(unsigned num) {
  if (num <= 1)
    return 1;
  double result = factoriallf(num - 1);
  return result;
}

double arrangementlf(unsigned total, unsigned selected) {
  if (total == 0 || selected > total)
    return NAN;
  double result = factoriallf(total) / factoriallf(total - selected);
  return result;
}

double combinationlf(unsigned total, unsigned selected) {
  if (total == 0 || selected > total)
    return NAN;
  double result = factoriallf(total) /
                  (factoriallf(selected) * factoriallf(total - selected));
  return result;
}
