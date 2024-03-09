#include "worldTour.h"

//Default Constructor 
WorldTour::WorldTour(){
    setRideName("World Tour");
    setHeightRestricted(false);
    setNumTicketsNecessary(1);
}

//Height Restriction Setter
void WorldTour::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}