#include <3DGeo/maths.hh>

int Maths::CalcMNewton(int mass, int dist, int timeunit)
{
  if (timeunit == 0)
    {
      printf("ERROR: timeunit (frequency) = 0 !\n");
      return (mass * dist);
    }
  return (1000 * mass * dist / (timeunit * timeunit));
}

int Maths::Max(const int a, const int b)
{
    return ((a>b)?a:b);
}

int Maths::Min(const int a, const int b)
{
    return ((a>b)?b:a);
}

int Maths::GetMinAbs(int wanted, unsigned int limit)
{
    if (wanted >= 0)
      return (Min(wanted, limit));
    return (-Min(-wanted, limit));
}

double Maths::ToRad(double angle)
{
    return (M_PI * angle / (double)180);
}

double Maths::ToDeg(double angle)
{
    return ((double)180 * angle / M_PI);
}

double Maths::ArcToAngle(double arcLenght, double radiusLenght)
{
    return (arcLenght / radiusLenght);
}

unsigned int Maths::AbsVal(const int value)
{
    if (value < 0)
      return (-value);
    return (value);
}

double Maths::AbsValF(const double value)
{
    if (value < 0)
      return (-value);
    return (value);
}

int Maths::Sign(int val)
{
    if (val < 0)
      return (-1);
    return (1);
}

int Maths::DSign(double val)
{
    if (val < 0)
      return (-1);
    return (1);
}

int Maths::NSign(int val)
{
    if (val == 0)
        return (0);
    return (Sign(val));
}

int Maths::DNSign(double val)
{
    if (val == 0)
        return (0);
    return (DSign(val));
}
