#include "internal/mathlib_c.h"
#include <errno.h>
#include <stdio.h>

unsigned long long factorial(unsigned num) {
  if (num > 20) {
    errno = ERANGE;
    perror("Error calculating factorial");
    return 0;
  }

  unsigned long long result = 1;
  unsigned i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

double factoriallf(unsigned num) {
  double result = 1;
  unsigned i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}
