#include <stdbool.h>

/**
  @brief Checks whether the given number is a prime number.
  @param num The number to be checked.
  @return True if the number is a prime number, false otherwise.
*/

bool isPrime(long long num)
{
  int i;
  if (!(num % 2))
    return num == 2 ? true : false;
  for (i = 3; num % i && i <= num; i += 2)
    if (i * i > num)
      return true;
  return false;
}
