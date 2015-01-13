#ifndef VECT_HH
#define VECT_HH

/*!
 * \file vect.hh
 * \brief Contains class representation of a mathematical tri-dimensional vector (and related operations)
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/maths.hh>
#include <3DGeo/ISerializable.hh>
#include <iostream>

class Orientation;

#define VECT_X_AXIS             ((vect_t){1, 0, 0})
#define VECT_Y_AXIS             ((vect_t){0, 1, 0})
#define VECT_Z_AXIS             ((vect_t){0, 0, 1})

using namespace std;

/*!
 * \brief The Vect class: Representation of a mathematical tri-dimensional vector (and related operations)
 *  - Contains a mathematical vector
 *  - Implements vectorial operations
 *  - Generic class to use in different contexts
 */
class Vect : public ISerializable
{
private: // vars
    int _x;
    int _y;
    int _z;

public: // interface
    /*!
     * \brief Vect: Standard constructor
     */
    Vect();                                         // Standard constructor
    /*!
     * \brief Vect: Constructor with vector values
     * \param x = the x axis
     * \param y = the y axis
     * \param z = the z axis
     */
    Vect(int x, int y, int z);                      // Constructor with vector values

    /*!
     * \brief Norm: Give the norm of a vector
     * \return norm of the vector
     */
    double Norm() const;                            // Give the norm of a vector
    /*!
     * \brief Angle: Give the angle between two vectors (in degrees)
     * \param b = second vector definig the angle
     * \return value of the angle in degrees
     */
    double GetAngle(const Vect b);                  // Give the angle between two vectors (in degrees)
    /*!
     * \brief GetOrientation: Give the orientation corresponding to vector
     * TODO: make a clean angle conversion
     * \return orientation
     */
    Orientation GetOrientation();                   // Give the orientation corresponding to vector
    /*!
     * \brief RotX: Rotate the vector around x axis by given angle (in radians)
     * \param angle = angle to apply to the vector in radians
     * \return the modified vector
     */
    Vect RotX(double angle);                        // Rotate the vector around x axis by given angle (in radians)
    /*!
     * \brief RotY: Rotate the vector around y axis by given angle (in radians)
     * \param angle = angle to apply to the vector in radians
     * \return the modified vector
     */
    Vect RotY(double angle);                        // Rotate the vector around y axis by given angle (in radians)
    /*!
     * \brief RotZ: Rotate the vector around z axis by given angle (in radians)
     * \param angle = angle to apply to the vector in radians
     * \return the modified vector
     */
    Vect RotZ(double angle);                        // Rotate the vector around z axis by given angle (in radians)

    /*!
     * \brief operator=: Assign from vector
     * \param b = other vector
     * \return modified vector
     */
    Vect &operator=(const Vect &b);                 // Assign from vector
    /*!
     * \brief operator+: Add two vectors
     * \param b = other vector
     * \return new modified vector
     */
    Vect operator+(const Vect &b);                  // Add two vectors
    /*!
     * \brief operator-: Substract two vectors
     * \param b = other vector
     * \return new modified vector
     */
    Vect operator-(const Vect &b);                  // Substract two vectors
    /*!
     * \brief operator-: Negate vector
     * \return new modified vector
     */
    Vect operator-();                               // Negate vector
    /*!
     * \brief operator*: Multiplie a vector by a number
     * \param b = other vector
     * \return new modified vector
     */
    Vect operator*(const int &b);                   // Multiplie a vector by a number
    /*!
     * \brief operator/: Divide a vector by a number
     * \param b = other vector
     * \return new modified vector
     */
    Vect operator/(const int &b);                   // Divide a vector by a number
    /*!
     * \brief operator*: Scalar product of two vectors
     * \param b = other vector
     * \return the scalar product of the two vectors
     */
    int operator*(const Vect &b);                   // Scalar product of two vectors

    /*!
     * \brief X: Get x axis value
     * \return x axis value
     */
    int X() const;                                  // Get x axis value
    /*!
     * \brief Y: Get y axis value
     * \return y axis value
     */
    int Y() const;                                  // Get y axis value
    /*!
     * \brief Z: Get z axis value
     * \return z axis value
     */
    int Z() const;                                  // Get z axis value

    virtual string Serialize();                 // Give string representation of the object
    virtual void UnSerialize(istringstream *stream);                   // Load object from a stream
    virtual void UnSerialize(string val) { ISerializable::UnSerialize(val); } // Load object from string
};

/*!
 * \brief operator<<: give the character representation of vector
 * \param os = out stream
 * \param x = vector
 * \return out stream
 */
ostream &operator<<(ostream& os, const Vect& x);

#endif // VECT_HH
