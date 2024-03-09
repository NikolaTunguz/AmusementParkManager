/*!
 * This is the magic carpet ride class. It's only responsibility is setting the default constructor
 * Inherits from Ride class
*/
#ifndef MAGICCARPET_H
#define MAGICCARPET_H
#include "ride.h"

class MagicCarpet : public virtual Ride{
    public:
        //! Default Constructor; requires 2 tickets, is height restricted, and is named Magic Carpet
        MagicCarpet();

        void setHeightRestricted(bool);
};
#endif
