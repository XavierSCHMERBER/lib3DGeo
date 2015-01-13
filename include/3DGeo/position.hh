#ifndef POSITION_HH
#define POSITION_HH

/*!
 * \file position.hh
 * \brief contains Position type
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/gps.hh>
#include <3DGeo/ISerializable.hh>

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*!
 * \brief The Position class: Position container
 *  - Contain a GPS coordinate as a position referential
 *  - Implements a buffer system to reduce calculation cost and improve precision
 *  - Provides basic operations to manipulate positions
 */
class Position : public ISerializable
{
private: // defs
#define MAX_DIST        100000                  // Maximum distance without update in mm
#define UBUFF_MAX       1000                    // Maximum value of _uBuff without _buff update

private: // vars
    Gps     _ref;                               // Absolute position reference
    Vect    _buff;                              // Buffer for variations from ref (time and precision amelioration)
    Vect    _uBuff;                             // Micrometer buffer to take account very small moves

public: // interface
    /*!
     * \brief Position: Standard constructor
     */
    Position();                                 ////// Standard constructor
    /*!
     * \brief Position: Constructor with GPS position
     * \param pos = The GPS position
     */
    Position(Gps pos);                          // Constructor with GPS position
    /*!
     * \brief Position: Constructor with GPS position and variation vector
     * \param pos = The GPS position
     * \param var = The variation vector
     */
    Position(Gps pos, Vect var);                // Constructor with GPS position and variation vector

    /*!
     * \brief AddVect: Add a vector to current position
     * \param dist = The vector to add
     */
    void AddVect(Vect dist);                    // Add a vector to current position
    /*!
     * \brief AddUVect: Add a micrometer vector to current position
     * \param uDist = The vector to add in micrometer
     */
    void AddUVect(Vect uDist);                  // Add a micrometer vector to current position
    /*!
     * \brief GetDist: Get dist from other position
     * \param b = The other position
     * \return the distance vector between both position
     */
    Vect GetDist(Position b);                   // Get dist from other position
    /*!
     * \brief Update: Manually force GPS coorinates update
     *  - Used to empty the buffer and have an up to date GPS coordinate (stricly intern difference)
     */
    void Update();                              // Manually force GPS coorinates update
    /*!
     * \brief GetGps: Get GPS coordinate struct (always up to date)
     * \return the GPS coordinate
     */
    Gps GetGps() const;                         // Get GPS coordinate struct (always up to date)
    /*!
     * \brief operator=: Assign from position
     * \param b = The other Position
     * \return the updated Position
     */
    Position &operator=(const Position &b);     // Assign from position

    virtual string Serialize();                 // Give string representation of the object
    virtual void UnSerialize(istringstream *stream);                   // Load object from a stream
    virtual void UnSerialize(string val) { ISerializable::UnSerialize(val); } // Load object from string

private: // internals
    bool chooseUpdate();                        // Choose to update GPS coordinate or not (depend on MAX_DIST)
    void updateGps();                           // Update GPS coordinates with buffer
};

/*!
 * \brief operator<<: The out stream operator overload for Position
 * \param os = The out stream
 * \param x = The Position
 * \return the out stream
 */
ostream &operator<<(ostream& os, const Position& x);

#endif // POSITION_HH
