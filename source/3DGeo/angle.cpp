#include <3DGeo/angle.hh>

Angle::Angle()
{
    _val = 0;
}

Angle::Angle(double rad)
{
    _val = convert(rad);
    simplify();
}

double Angle::GetRad() const
{
    return (unConvert(_val));
}

double Angle::GetDeg() const
{
    return (RadToDeg(GetRad()));
}

double Angle::Cos() const
{
    return (cos(unConvert(_val)));
}

double Angle::Sin() const
{
    return (sin(unConvert(_val)));
}

double Angle::Tan() const
{
    return (tan(unConvert(_val)));
}

Angle &Angle::operator=(const Angle &b)
{
    _val = b._val;
    simplify();
    return (*this);
}

Angle &Angle::operator=(const double &b)
{
    _val = convert(b);
    simplify();
    return (*this);
}

Angle Angle::operator+(const Angle &b) const
{
    Angle ret(unConvert(_val + b._val));

    return (ret);
}

Angle Angle::operator-(const Angle &b) const
{
    Angle ret(unConvert(_val - b._val));

    return (ret);
}

Angle Angle::operator-() const
{
    Angle ret(-unConvert(_val));

    return (ret);
}

Angle Angle::operator*(const int &b) const
{
    Angle ret(unConvert(_val) * (double)b);

    return (ret);
}

Angle Angle::operator/(const int &b) const
{
    Angle ret(unConvert(_val) / (double)b);

    return (ret);
}

double Angle::DegToRad(double deg)
{
    return (M_PI * deg / (double)180);
}

double Angle::RadToDeg(double rad)
{
    return ((double)180 * rad / M_PI);
}

string Angle::Serialize()
{
    stringstream stream;

    stream << _val;

    return (stream.str());
}

void Angle::UnSerialize(istringstream *stream)
{
    int value;

    (*stream) >> value;

    _val = value;
}

void Angle::simplify()
{
    while (_val > 2 * ANGLE_MAX_VALUE)
        _val -= (2 * ANGLE_MAX_VALUE);
    while (_val < 2 * (-ANGLE_MAX_VALUE))
        _val += (2 * ANGLE_MAX_VALUE);
    if (_val > ANGLE_MAX_VALUE)
        _val -= 2 * ANGLE_MAX_VALUE;
    else if (_val < -ANGLE_MAX_VALUE)
        _val += 2 * ANGLE_MAX_VALUE;
}

int Angle::convert(double rad) const
{
    return ((int)(rad * ANGLE_CONVERSION));
}

double Angle::unConvert(int val) const
{
    return ((double)val / (double)ANGLE_CONVERSION);
}

ostream &operator<<(ostream& os, const Angle& x)
{
    os << x.GetDeg();
    return (os);
}
