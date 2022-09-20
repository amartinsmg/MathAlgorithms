#include <stdbool.h>
#include <stdlib.h>

bool isHappy(long long num)
{
  long long sum, *numSet = (long long *)malloc(sizeof(*numSet));
  int i, lenNumSet, remainder;
  numSet[0] = num;
  lenNumSet = 1;
  while (true)
  {
    sum = 0;
    while (num > 0)
    {
      remainder = num % 10;
      num /= 10;
      sum += remainder * remainder;
    }
    if (sum == 1)
      return true;
    for (i = 0; i < lenNumSet; i++)
    {
      if (numSet[i] == sum)
        return false;
    }
    numSet = (long long *)realloc(numSet, sizeof(*numSet) * ++lenNumSet);
    numSet[lenNumSet - 1] = sum;
    num = sum;
  }
}
