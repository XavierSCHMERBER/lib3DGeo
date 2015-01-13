#ifndef ANGLE_HH
#define ANGLE_HH

#include <3DGeo/maths.hh>
#include <3DGeo/ISerializable.hh>
#include <iostream>

using namespace std;

class Angle : public ISerializable
{
private: // defs
#define ANGLE_CONVERSION        1000000                             // The value used to store angle into integer
#define ANGLE_MAX_VALUE         ((int)(M_PI*ANGLE_CONVERSION))      // The maximum absolute value of an angle

private: // vars
    int _val;                                               // The angle container in (radians * ANGLE_CONVERSION)

public:
    Angle();                                                // Standard constructor
    Angle(double rad);                                      // Constructor with value

    double GetRad() const;                                  // Get angle in radians
    double GetDeg() const;                                  // Get angle in degrees
    double Cos() const;                                     // Get cosinus of angle
    double Sin() const;                                     // Get sinus of angle
    double Tan() const;                                     // Get tangente of angle

    /*!
     * \brief operator=: Assign from angle
     * \param b = other angle
     * \return modified angle
     */
    Angle &operator=(const Angle &b);                       // Assign from angle
    /*!
     * \brief operator=: Assign from value
     * \param b = value
     * \return modified angle
     */
    Angle &operator=(const double &b);                      // Assign from value
    /*!
     * \brief operator+: Add two angles
     * \param b = other angle
     * \return new modified angle
     */
    Angle operator+(const Angle &b) const;                  // Add two angles
    /*!
     * \brief operator-: Substract two angles
     * \param b = other angle
     * \return new modified angle
     */
    Angle operator-(const Angle &b) const;                  // Substract two angles
    /*!
     * \brief operator-: Negate angle
     * \return new modified angle
     */
    Angle operator-() const;                                // Negate angle
    /*!
     * \brief operator*: Multiplie a angle by a number
     * \param b = value
     * \return new modified angle
     */
    Angle operator*(const int &b) const;                    // Multiplie a angle by a number
    /*!
     * \brief operator/: Divide a angle by a number
     * \param b = value
     * \return new modified angle
     */
    Angle operator/(const int &b) const;                    // Divide a vector by a number

    static double DegToRad(double deg);                     // Convert degrees to radians
    static double RadToDeg(double rad);                     // Convert radians to degrees

    virtual string Serialize();                 // Give string representation of the object
    virtual void UnSerialize(istringstream *stream);                   // Load object from a stream
    virtual void UnSerialize(string val) { ISerializable::UnSerialize(val); } // Load object from string

private: // internals
    void simplify();                                        // Simplify value to be under ANGLE_MAX_VALUE limit
    int convert(double rad) const;                          // Convert angle to value with ANGLE_CONVERSION
    double unConvert(int val) const;                        // UnConvert angle from value with ANGLE_CONVERSION
};
ostream &operator<<(ostream& os, const Angle& x);

#endif // ANGLE_HH
