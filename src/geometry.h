#include <math.h>
#include "./area.h"
#include "./volume.h"

#define PI 3.141592653589793

double degrees2radians(double degrees)
{
  return degrees / 180 * PI;
}

double radians2degrees(double radians)
{
  return radians / PI * 180;
}

double distanceBetweenPoits(double ax, double ay, double bx, double by)
{
  double dist = sqrt(pow((bx - ax), 2) + pow((by - ay), 2));
  return dist;
}


