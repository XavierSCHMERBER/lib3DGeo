/*!
 * \file position.cpp
 * \brief contains Position type
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/position.hh>

Position::Position()
{
    _ref = Gps(0, 0, 0);
    _buff = Vect(0, 0, 0);
    _uBuff = Vect(0, 0, 0);
}

Position::Position(Gps pos)
{
    _ref = pos;
    _buff = Vect(0, 0, 0);
    _uBuff = Vect(0, 0, 0);
}

Position::Position(Gps pos, Vect var)
{
    _ref = pos;
    _buff = var;
    _uBuff = Vect(0, 0, 0);
}

void Position::AddVect(Vect dist)
{
    _buff = _buff + dist;
    chooseUpdate();
}

void Position::AddUVect(Vect uDist)
{
    _uBuff = _uBuff + uDist;
    chooseUpdate();
}

Vect Position::GetDist(Position b)
{
    return (GetGps().DistCalc(b.GetGps()));
}

void Position::Update()
{
    updateGps();
}

Gps Position::GetGps() const
{
    if (Maths::AbsVal(_buff.X()) + Maths::AbsVal(_buff.Y()) + Maths::AbsVal(_buff.Z()) == 0)
        return (_ref);
    Gps tmp = _ref;
    tmp.AddVect(_buff);
    return (tmp);
}

Position &Position::operator=(const Position &b)
{
    _ref = b._ref;
    _buff = b._buff;
    _uBuff = b._uBuff;
    return (*this);
}

bool Position::chooseUpdate()
{
    Vect tmpBuff;

    if (Maths::AbsVal(_uBuff.X()) >= UBUFF_MAX || Maths::AbsVal(_uBuff.Y()) >= UBUFF_MAX || Maths::AbsVal(_uBuff.Z()) >= UBUFF_MAX)
    {
        tmpBuff = _uBuff / 1000;
        _buff = _buff + tmpBuff;
        _uBuff = _uBuff - (tmpBuff * 1000);
    }
    if (Maths::AbsVal(_buff.X()) + Maths::AbsVal(_buff.Y()) + Maths::AbsVal(_buff.Z()) > MAX_DIST)
    {
        updateGps();
        return (true);
    }
    return (false);
}

void Position::updateGps()
{
    _ref.AddVect(_buff);
    _buff = Vect(0, 0, 0);
}

ostream &operator<<(ostream& os, const Position& x)
{
    os << x.GetGps();
    return (os);
}
