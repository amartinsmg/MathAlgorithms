#include <stdbool.h>
#include <stdlib.h>

#ifndef HAPPY_NUMBERS_H
#define HAPPY_NUMBERS_H

/**
  @brief Checks whether the given number is a happy number.
  @param num The number to be checked.
  @return True if the number is a happy number, false otherwise.
*/

bool isHappy(long long num)
{
  long long sum,
      *numSet = (long long *)malloc(sizeof(*numSet));
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
      if (numSet[i] == sum)
        return false;
    numSet = (long long *)realloc(numSet, sizeof(*numSet) * ++lenNumSet);
    numSet[lenNumSet - 1] = sum;
    num = sum;
  }
}

#endif /* HAPPY_NUMBERS_H */
