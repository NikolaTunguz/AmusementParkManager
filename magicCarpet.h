/*
Author: Nikola Tunguz
Purpose: This is the magic carpet ride class. It's only responsibility is setting the default constructor.
*/
#ifndef MAGICCARPET_H
#define MAGICCARPET_H
#include "ride.h"

//MagicCarpet inherits from Ride class.
class MagicCarpet : public virtual Ride{
    public:
        //Default Constructor: requires 2 tickets, is height restricted, and is named Magic Carpet
        MagicCarpet();

        void setHeightRestricted(bool);
};
#endif
