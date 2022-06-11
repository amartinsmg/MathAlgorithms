#include <stdlib.h>

int _sumOfSquareEachDig(long long num)
{
  long long sum = 0;
  while (num > 0)
  {
    int remainder = num % 10;
    num /= 10;
    sum += remainder * remainder;
  }
  return sum;
}

int isHappy(long long num)
{
  long long *numSet = (long long *)calloc(64, sizeof(long long));
  numSet[0] = num;
  int lengthNumSet = 1;
  while (1)
  {
    long long sum = _sumOfSquareEachDig(num);
    if (sum == 1)
      return 1;
    for (int i = 0; i < lengthNumSet; i++)
    {
      if (numSet[i] == sum || sum == 0)
        return 0;
    }
    numSet[lengthNumSet++] = sum;
    num = sum;
  }
}
