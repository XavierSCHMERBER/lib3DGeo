/*!
 * \file vect.cpp
 * \brief Contains class representation of a mathematical tri-dimensional vector (and related operations)
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/vect.hh>
#include <3DGeo/orientation.hh>

Vect::Vect()
{
    _x = 0;
    _y = 0;
    _z = 0;
}

Vect::Vect(int x, int y, int z)
{
    _x = x;
    _y = y;
    _z = z;
}

double Vect::Norm() const
{
    return (sqrt(_x * _x + _y * _y + _z * _z));
}

double Vect::GetAngle(const Vect b)
{
    int neg = 1;

    if (_x * b.Y() - _y * b.X() < 0)
      neg = -1;

    return (neg * Maths::ToDeg(acos((*this * b) / (Norm() * b.Norm()))));
}

Orientation Vect::GetOrientation()
{
    Orientation tmp = Orientation(Angle(Maths::Sign(_x) * Angle::DegToRad(Vect(0, 0, 100).GetAngle(Vect(_x, 0, _z)))),
                                  Angle(Maths::Sign(_y) * Angle::DegToRad(Vect(0, 0, 100).GetAngle(Vect(0, _y, _z)))),
                                  Angle(0));

    return (tmp);
}

Vect Vect::RotX(double angle)
{
    Vect res = Vect(_x, _y * cos(angle) - _z * sin(angle), _y * sin(angle) + _z * cos(angle));
    (*this) = res;
    return (*this);
}

Vect Vect::RotY(double angle)
{
    Vect res = Vect(_x * cos(angle) + _z * sin(angle), _y, - _x * sin(angle) + _z * cos(angle));
    (*this) = res;
    return (*this);
}

Vect Vect::RotZ(double angle)
{
    Vect res = Vect(_x * cos(angle) - _y * sin(angle), _x * sin(angle) + _y * cos(angle), _z);
    (*this) = res;
    return (*this);
}

Vect &Vect::operator=(const Vect &b)
{
    _x = b.X();
    _y = b.Y();
    _z = b.Z();
    return (*this);
}

Vect Vect::operator+(const Vect &b)
{
    return (Vect(_x + b.X(), _y + b.Y(), _z + b.Z()));
}

Vect Vect::operator-(const Vect &b)
{
    return (Vect(_x - b.X(), _y - b.Y(), _z - b.Z()));
}

Vect Vect::operator-()
{
    return (Vect(-_x, -_y, -_z));
}

Vect Vect::operator*(const int &b)
{
    return (Vect(_x * b, _y * b, _z * b));
}

Vect Vect::operator/(const int &b)
{
    return (Vect(_x / b, _y / b, _z / b));
}

int Vect::operator*(const Vect &b)
{
    return (_x * b.X() + _y * b.Y() + _z * b.Z());
}

int Vect::X() const
{
    return (_x);
}

int Vect::Y() const
{
    return (_y);
}

int Vect::Z() const
{
    return (_z);
}

ostream &operator<<(ostream& os, const Vect& x)
{
    os << "{" << x.X() << "; " << x.Y() << "; " << x.Z() << "}";
    return (os);
}
