/*!
 * This is the world tour ride class. It's only responsibility is setting the default constructor
 * Inherits from the Ride class
*/
#ifndef WORLDTOUR_H
#define WORLDTOUR_H
#include "ride.h"

class WorldTour : public virtual Ride{
    public:
        //!  Default Constructor; requires 1 tickets, is not height restricted, and is named World Tour
        WorldTour();

        void setHeightRestricted(bool);
};
#endif