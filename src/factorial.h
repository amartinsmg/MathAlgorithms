#include <assert.h>

/* The function factorial() works well for numbers <= 20,
  for numbers > 20 use the function factoriallf(), that
  uses double precision float to store the result, allowing
  numbers grether than 9223372036854776000 to be represented
  using exponential form */

long long factorial(int num)
{
  assert(num >= 0);
  long long result = 1;
  for (int i = 1; i <= num; i++)
    result *= i;
  return result;
}

double factoriallf(int num)
{
  assert(num >= 0);
  double result = 1;
  for (int i = 1; i <= num; i++)
    result *= i;
  return result;
}
