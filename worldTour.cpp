#include "worldTour.h"

WorldTour::WorldTour(){
    setRideName("World Tour");
    setHeightRestricted(false);
    setNumTicketsNecessary(1);
}


void WorldTour::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}