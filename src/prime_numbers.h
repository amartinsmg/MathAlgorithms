#include <stdbool.h>

/**
  @brief Checks whether the given number is a prime number.
  @param num The number to be checked.
  @return True if the number is a prime number, false otherwise.
*/

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
