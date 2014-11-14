#ifndef MATHS_HH
#define MATHS_HH

#include <stdio.h>
#include <math.h>

using namespace std;

class Maths
{
private: // defs
#define SECOND_IN_U_SECOND      1000000

public: // interface
    /*!
     * \brief CalcMNewton: Calculate the force (N) corresponding to the parameters (m, d, t)
     * \param mass = mass - mass must be in grams (g)
     * \param dist = distance - dist must be in milimeters (mm)
     * \param timeunit = time - timeunit must be in miliseconds (ms)
     * \return the resulting force
     */
    static int CalcMNewton(int mass, int dist, int timeunit);

    /*!
     * \brief Max: return the biggest value between a and b
     * \param a = value a
     * \param b = value b
     * \return the biggest value
     */
    static int Max(const int a, const int b);

    /*!
     * \brief Min: return the smallest value between a and b
     * \param a = value a
     * \param b = value b
     * \return the smallest value
     */
    static int Min(const int a, const int b);

    /*!
     * \brief GetMinAbs: return the signed value of the minimum absolute value of wanted and limit
     * \param wanted = value
     * \param limit = value
     * \return the signed value of absolute minimum value
     */
    static int GetMinAbs(int wanted, unsigned int limit);

    /*!
     * \brief ToRad: convert an angle in degree to radian
     * \param angle = value
     * \return the converted value
     */
    static double ToRad(double angle);

    /*!
     * \brief ToDeg: convert an angle in radian to degree
     * \param angle = value
     * \return the converted value
     */
    static double ToDeg(double angle);

    /*!
     * \brief ArcToAngle: give the corresponding angle to a circle arc (in radians)
     * \param arcLenght = length of the arc
     * \param radiusLenght = lenght of the circle's radius
     * \return the corresponding angle in radians
     */
    static double ArcToAngle(double arcLenght, double radiusLenght);

    /*!
     * \brief AbsVal: get absolute value of int
     * \param value = value
     * \return the absolute value
     */
    static unsigned int AbsVal(const int value);

    /*!
     * \brief AbsValF: get absolute value of float
     * \param value = value
     * \return the absolute value
     */
    static double AbsValF(const double value);

    /*!
     * \brief Sign: get sign from value
     * \param val = value
     * \return -1 or 1 depending to the sign
     */
    static int Sign(int val);

    /*!
     * \brief DSign: get sign from double value
     * \param val = value
     * \return -1 or 1 depending to the sign
     */
    static int DSign(double val);

    /*!
     * \brief NSign: if val is null, return 0, else return its sign
     * \param val = value
     * \return -1, 1 or 0 depending to the sign
     */
    static int NSign(int val);

    /*!
     * \brief DNSign: if val is null, return 0, else return its sign
     * \param val = value
     * \return -1, 1 or 0 depending to the sign
     */
    static int DNSign(double val);
};

#endif // MATHS_HH
