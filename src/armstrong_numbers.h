#include <stdbool.h>
#include <math.h>

bool isArmstrong(long long num)
{
  int k = floor(log10(num)) + 1;
  long long n = num,
            sum = 0;
  for (int i = 0; i < k; i++)
  {
    sum += pow((n % 10), k);
    n /= 10;
  }
  if (sum == num)
    return true;
  return false;
}
