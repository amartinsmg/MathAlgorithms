#include <stdbool.h>

bool isPrime(long long num)
{
  int i = 3;
  if (!(num % 2))
  {
    if (num == 2)
      return true;
    else
      return false;
  }
  while (num % i && i <= num)
  {
    if (i * i > num)
      return true;
    i += 2;
  }
  return false;
}
