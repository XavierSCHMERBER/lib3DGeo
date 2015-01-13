/*!
 * \file gps.cpp
 * \brief contains the GPS coordinate type container
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/gps.hh>

Gps::Gps()
{
    _lat = 0;
    _lon = 0;
    _alt = 0;
}

Gps::Gps(double lat, double lon, double alt)
{
    _lat = lat;
    _lon = lon;
    _alt = alt;
}

Vect Gps::DistCalc(Gps b)
{
    int x, y, z;
    double tmp;
    double dlat = Maths::ToRad(b._lat - _lat);
    double dlon = Maths::ToRad(b._lon - _lon);

    tmp = sin(dlon/2.0) * sin(dlon/2.0) * cos(Maths::ToRad(_lat)) * cos(Maths::ToRad(b._lat));
    if (EARTH_RADIUS * 2.0 * atan2(sqrt(tmp), sqrt(1.0 - tmp)) > 1000)
    {
        cerr << "Calc GPS distance: error, value is too high (> 1000km)" << endl;
        return (Vect());
    }
    y = EARTH_RADIUS * 2.0 * atan2(sqrt(tmp), sqrt(1.0 - tmp)) * KM_TO_MM * Maths::DSign(dlon);

    tmp = sin(dlat/2.0) * sin(dlat/2.0);
    if (EARTH_RADIUS * 2.0 * atan2(sqrt(tmp), sqrt(1.0 - tmp)) > 1000)
    {
        cerr << "Calc GPS distance: error, value is too high (> 1000km)" << endl;
        return (Vect());
    }
    x = EARTH_RADIUS * 2.0 * atan2(sqrt(tmp), sqrt(1.0 - tmp)) * KM_TO_MM * Maths::DSign(dlat);

    // depend on how the altitude is represented
    z = b._alt - _alt;


    return (Vect(x, y, z));
}

void Gps::AddVect(Vect dist)
{
    double newlon;
    double newlat;

    newlon = Maths::ToRad(_lon) + atan2(sin(dist.Y() / (EARTH_RADIUS * KM_TO_MM)) * cos(Maths::ToRad(_lat)), cos(dist.Y() / (EARTH_RADIUS * KM_TO_MM)) - sin(Maths::ToRad(_lat)) * sin(Maths::ToRad(_lat)));
    newlat = asin(sin(Maths::ToRad(_lat)) * cos(dist.X() / (EARTH_RADIUS * KM_TO_MM)) + cos(Maths::ToRad(_lat)) * sin(dist.X() / (EARTH_RADIUS * KM_TO_MM)));

    _lon = Maths::ToDeg(newlon);
    _lat = Maths::ToDeg(newlat);
    // depend on how the altitude is represented
    _alt += dist.Z();
}

double Gps::Lon() const
{
    return (_lon);
}

double Gps::Lat() const
{
    return (_lat);
}

double Gps::Alt() const
{
    return (_alt);
}

Gps &Gps::operator=(const Gps &b)
{
    _lat = b.Lat();
    _lon = b.Lon();
    _alt = b.Alt();
    return (*this);
}

string Gps::Serialize()
{
    stringstream stream;

    stream << _lat;
    stream << GEO_SEP_CHAR;
    stream << _lon;
    stream << GEO_SEP_CHAR;
    stream << _alt;

    return (stream.str());
}

void Gps::UnSerialize(istringstream *stream)
{
    double gps[3];

    (*stream) >> gps[0];
    (*stream).ignore(1, GEO_SEP_CHAR);
    (*stream) >> gps[1];
    (*stream).ignore(1, GEO_SEP_CHAR);
    (*stream) >> gps[2];

    _lat = gps[0];
    _lon = gps[1];
    _alt = gps[2];
}

ostream &operator<<(ostream& os, const Gps& x)
{
    os << "{" << x.Lat() << " N; " << x.Lon() << " E; " << x.Alt() << "}";
    return (os);
}
