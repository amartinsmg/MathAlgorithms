#include <stdlib.h>

long long *primeFactors(long long num)
{
  long long i, *factors = (long long *)calloc(64, sizeof(*factors)),
               length = 0;
  while (num > 1)
  {
    for (i = 2; i <= num; i++)
    {
      if (!(num % i))
      {
        factors[length++] = i;
        num /= i;
        break;
      }
    }
  }
  return factors;
}
