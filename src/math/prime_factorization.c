#include "internal/mathlib_c.h"
#include "utils/vector.h"

long long *primeFactors(long long num, size_t *size) {
  long long i;
  long long *result;
  Vector factors = vector_init(sizeof(long long));

  while (num > 1)
    for (i = 2; i <= num; i++)
      if (!(num % i)) {
        vector_append(&factors, &i);
        num /= i;
        break;
      }

  result = vector_get_values(&factors);
  *size = factors.length;
  vector_free(&factors);

  return result;
}
