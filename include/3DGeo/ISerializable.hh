#ifndef I_SERIALIZABLE_HH
#define I_SERIALIZABLE_HH

/*!
 * \file ISerializable.hh
 * \brief define the interface for serializable objects
 * \author Xavier SCHMERBER
 * \version 1
 */

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#define GEO_SEP_CHAR    ';'

/*!
 * \brief The ISerializable class: Define the interface for serializable objects
 *  - Used to send objects via network protocols
 *  - Objects are exported to and imported from standard strings
 */
class ISerializable
{
public: // interface
    virtual string Serialize() = 0;                                        // Give string representation of the object

    virtual void UnSerialize(istringstream *stream) = 0;                   // Load object from a stream

    virtual void UnSerialize(string val)                                   // Load object from it's string representation
    {
        istringstream stream(val);
        UnSerialize(&stream);
    }
};

#endif // I_SERIALIZABLE_HH
