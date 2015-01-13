#ifndef GPS_HH
#define GPS_HH

/*!
 * \file gps.hh
 * \brief contains the GPS coordinate type container
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <3DGeo/vect.hh>
#include <3DGeo/ISerializable.hh>

using namespace std;

/*!
 * \brief The Gps class: GPS coordinate type container
 *  - The class is designed to make GPS coordinates manipulation easier
 *  - Contains GPS coordinates and allows basic operations
 */
class Gps : public ISerializable
{
private: // defs
#define EARTH_RADIUS        (double)6371        // in km
#define KM_TO_MM            (double)(1000*1000) // output is in mm

private: // vars
    double _lon;                                // Longitude of the position
    double _lat;                                // Latitude of the position
    double _alt;                                // Altitude of the position

public: // interface
    /*!
     * \brief Gps: Standard constructor
     */
    Gps();                                      // Standatd constructor
    /*!
     * \brief Gps: Constructor with GPS coordinates
     * \param lat = Latitude
     * \param lon = Longitude
     * \param alt = Altitude
     */
    Gps(double lat, double lon, double alt);    // Constructor with GPS coordinates

    /*!
     * \brief DistCalc: Calculate the distances x, y and z between to GPS coordinates
     *  - Uses the Haversine method
     *  - WARNING: cannot manage over 1000km distancies
     * \param b = Other GPS coordinate
     * \return Vect containing the distance between both coordinates
     */
    Vect DistCalc(Gps b);                       // Calculate the distances x, y and z between to GPS coordinates

    /*!
     * \brief AddVect: Add a vector distance to the GPS position
     * \param dist = The vector distance
     */
    void AddVect(Vect dist);                    // Add a vector distance to the GPS position

    /*!
     * \brief Lon: Get longitude
     * \return the longitude
     */
    double Lon() const;                         // Get longitude
    /*!
     * \brief Lat: Get latitude
     * \return the latitude
     */
    double Lat() const;                         // Get latitude
    /*!
     * \brief Alt: Get altitude
     * \return the altitude
     */
    double Alt() const;                         // Get altitude
    /*!
     * \brief operator=: Assignement operator overload
     * \param b = Value tu be assigned
     * \return the modified GPS class
     */
    Gps &operator=(const Gps &b);               // Assignement operator overload

    virtual string Serialize();                 // Give string representation of the object
    virtual void UnSerialize(istringstream *stream);                   // Load object from a stream
    virtual void UnSerialize(string val) { ISerializable::UnSerialize(val); } // Load object from string
};

/*!
 * \brief operator<<: Out stream operator overload for Gps container
 * \param os = The out stream
 * \param x = The Gps container
 * \return the out stream
 */
ostream &operator<<(ostream& os, const Gps& x);

#endif // GPS_HH
