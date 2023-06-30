#include <stdbool.h>

/**
  @brief Checks whether the given number is a perfect number.
  @param num The number to be checked.
  @return True if the number is a perfect number, false otherwise.
*/

bool isPerfect(long long num)
{
  long long sum = 0;
  int i;
  for (i = 1; i < num; i++)
  {
    if (num % i == 0)
      sum += i;
  }
  if (sum == num)
    return true;
  return false;
}
