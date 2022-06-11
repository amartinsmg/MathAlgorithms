#include <stdlib.h>

int isPrime(long long num)
{
  for (int i = 2; num % i && i <= num; i++)
  {
    if (i * i > num)
      return 1;
  }
  return 0;
}