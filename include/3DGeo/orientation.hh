#ifndef ORIENTATION_HH
#define ORIENTATION_HH

#include <3DGeo/angle.hh>
#include <3DGeo/vect.hh>

using namespace std;

class Orientation
{
private: // defs
#define AXIS_ANGLE_DIFF             (M_PI / 2.0)
#define X_AXIS_TO_Y_BASE            (-AXIS_ANGLE_DIFF)
#define Y_AXIS_TO_X_BASE            (-AXIS_ANGLE_DIFF)

private: // vars
    Angle _x;
    Angle _y;
    Angle _z;

public: // interface
    Orientation();
    Orientation(Angle x, Angle y, Angle z);

    Vect GetVect() const;
    Vect GetInclination() const;
    Vect GetCompas() const;
    Angle GetCompasAngle() const;

    Angle X() const;
    Angle Y() const;
    Angle Z() const;

    /*!
     * \brief operator=: Assign from orientation
     * \param b = other orientation
     * \return modified orientation
     */
    Orientation &operator=(const Orientation &b);                           // Assign from orientation
    /*!
     * \brief operator+: Add two orientations
     * \param b = other orientation
     * \return new modified orientation
     */
    Orientation operator+(const Orientation &b) const;                      // Add two orientations
    /*!
     * \brief operator-: Substract two orientations
     * \param b = other orientation
     * \return new modified orientation
     */
    Orientation operator-(const Orientation &b) const;                      // Substract two orientations
    /*!
     * \brief operator-: Negate orientation
     * \return new modified orientiation
     */
    Orientation operator-() const;                                          // Negate orientation
    /*!
     * \brief operator*: Multiplie an orientation by a number
     * \param b = value
     * \return new modified orinetation
     */
    Orientation operator*(const int &b) const;                              // Multiplie a orientation by a number
    /*!
     * \brief operator/: Divide an orientaiton by a number
     * \param b = value
     * \return new modified orientation
     */
    Orientation operator/(const int &b) const;                              // Divide an orientation by a number
};
ostream &operator<<(ostream& os, const Orientation& x);

#endif // ORIENTATION_HH
