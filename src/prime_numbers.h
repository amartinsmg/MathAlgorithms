#include <stdbool.h>

bool isPrime(long long num)
{
  if (!(num % 2))
  {
    if (num == 2)
      return true;
    else
      return false;
  }
  for (int i = 3; num % i && i <= num; i += 2)
  {
    if (i * i > num)
      return true;
  }
  return false;
}
