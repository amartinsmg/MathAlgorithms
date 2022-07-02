int isPrime(long long num)
{
  if (!(num % 2))
  {
    if (num == 2)
      return 1;
    else
      return 0;
  }
  for (int i = 3; num % i && i <= num; i += 2)
  {
    if (i * i > num)
      return 1;
  }
  return 0;
}
