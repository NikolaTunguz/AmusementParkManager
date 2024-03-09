/*!
 * This is the teacups ride class. It's only responsibility is setting the default constructor
 * Inherits from the Ride class
*/
#ifndef TEACUPS_H
#define TEACUPS_H
#include "ride.h"

class Teacups : public virtual Ride{
    public:
        //!  Default Constructor; requires 3 tickets, is not height restricted, and is named Teacups
        Teacups();

        void setHeightRestricted(bool);
};
#endif