/*
Author: Nikola Tunguz
Purpose: This is the world tour ride class. It's only responsibility is setting the default constructor.
*/
#ifndef WORLDTOUR_H
#define WORLDTOUR_H
#include "ride.h"

//WorldTour inherits from Ride class.
class WorldTour : public virtual Ride{
    public:
        //Default Constructor: requires 1 tickets, is not height restricted, and is named WorldTour
        WorldTour();

        void setHeightRestricted(bool);
};
#endif