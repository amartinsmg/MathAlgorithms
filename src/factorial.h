long long factorial(unsigned num)
{
  long long result = 1;
  for (unsigned i = 1; i <= num; i++)
    result *= i;
  return result;
}