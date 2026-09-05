#include "internal/mathlib_c.h"
#include <errno.h>
#include <stdio.h>

long long factorial(int num) {
  if (num > 20) {
    errno = ERANGE;
    perror("Error calculating factorial");
    return 0;
  }
  if (num < 0) {
    errno = EINVAL;
    perror("Error calculating factorial");
    return 0;
  }

  long long result = 1;
  int i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

double factoriallf(int num) {
  if (num < 0)
    return NAN;
  double result = 1;
  int i;
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}
