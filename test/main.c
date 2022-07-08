#include <stdio.h>
#include <assert.h>
#include "prime_numbers.h"
#include "perfect_numbers.h"
#include "happy_numbers.h"
#include "armstrong_numbers.h"

int main() {
  assert(isPrime(7919));
  assert(isPrime(5329) == false);
  assert(isPerfect(6));
  assert(isPerfect(7) == false);
  assert(isHappy(23));
  assert(isHappy(73) == false);
  assert(isArmstrong(370));
  assert(isArmstrong(125) == false);


  printf("Passed all tests successfully!\n");

  return 0;
}
