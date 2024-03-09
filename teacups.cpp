#include "teacups.h"

Teacups::Teacups(){
    setRideName("Teacups");
    setHeightRestricted(false);
    setNumTicketsNecessary(3);
}


void Teacups::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}