#include <3DGeo/orientation.hh>

Orientation::Orientation()
{
    _x = Angle(0);
    _y = Angle(0);
    _z = Angle(0);
}

Orientation::Orientation(Angle x, Angle y, Angle z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vect Orientation::GetVect() const
{
    Vect orientVect(100 * (_y + Angle(Y_AXIS_TO_X_BASE)).Cos(), 100 * (_x + Angle(X_AXIS_TO_Y_BASE)).Cos(), 100 * _y.Cos());

    return (orientVect);
}

Vect Orientation::GetInclination() const
{
    return (GetVect());
}

Vect Orientation::GetCompas() const
{
    Vect compasVect(100 * _z.Cos(), 100 * _z.Sin(), 0);

    return (compasVect);
}

Angle Orientation::GetCompasAngle() const
{
    return (Z());
}

Angle Orientation::X() const
{
    return (_x);
}

Angle Orientation::Y() const
{
    return (_y);
}

Angle Orientation::Z() const
{
    return (_z);
}

Orientation &Orientation::operator=(const Orientation &b)
{
    _x = b.X();
    _y = b.Y();
    _z = b.Z();
    return (*this);
}

Orientation Orientation::operator+(const Orientation &b) const
{
    Orientation ret(_x + b.X(), _y + b.Y(), _z + b.Z());

    return (ret);
}

Orientation Orientation::operator-(const Orientation &b) const
{
    Orientation ret(_x - b.X(), _y - b.Y(), _z - b.Z());

    return (ret);
}

Orientation Orientation::operator-() const
{
    Orientation ret(-_x, -_y, -_z);

    return (ret);
}

Orientation Orientation::operator*(const int &b) const
{
    Orientation ret(_x * b, _y * b, _z * b);

    return (ret);
}

Orientation Orientation::operator/(const int &b) const
{
    Orientation ret(_x / b, _y / b, _z / b);

    return (ret);
}

ostream &operator<<(ostream& os, const Orientation& x)
{
    os << "{" << x.X() << "; " << x.Y() << "; " << x.Z() << "}";
    return (os);
}
