#include <stdbool.h>
#include <stdlib.h>

int _sumOfSquareEachDig(long long num)
{
  long long sum = 0;
  int remainder;
  while (num > 0)
  {
    remainder = num % 10;
    num /= 10;
    sum += remainder * remainder;
  }
  return sum;
}

bool isHappy(long long num)
{
  long long sum, *numSet = (long long *)calloc(64, sizeof(*numSet));
  int i, lenNumSet;
  numSet[0] = num;
  lenNumSet = 1;
  while (true)
  {
    sum = _sumOfSquareEachDig(num);
    if (sum == 1)
      return true;
    else if (sum == 0)
      return false;
    for (i = 0; i < lenNumSet; i++)
    {
      if (numSet[i] == sum)
        return false;
    }
    numSet[lenNumSet++] = sum;
    num = sum;
  }
}
