unsigned gcd(unsigned x, unsigned y)
{
  unsigned remainder = x % y;
  while (remainder)
  {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  return y;
}