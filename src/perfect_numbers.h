#include <stdbool.h>

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
