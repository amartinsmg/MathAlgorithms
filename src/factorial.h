#include <assert.h>

/* The function factorial() works well for numbers <= 20,
  for numbers > 20 use the function factoriallf(), that
  uses double precision float to store the result, allowing
  numbers grether than 9223372036854776000 to be represented
  using exponential form */

long long factorial(int num)
{
  long long result = 1;
  int i;
  assert(num >= 0);
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}

double factoriallf(int num)
{
  double result = 1;
  int i;
  assert(num >= 0);
  for (i = 1; i <= num; i++)
    result *= i;
  return result;
}
