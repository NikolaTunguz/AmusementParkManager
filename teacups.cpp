#include "teacups.h"

//Default Constructor
Teacups::Teacups(){
    setRideName("Teacups");
    setHeightRestricted(false);
    setNumTicketsNecessary(3);
}

//Height Restriction Setter
void Teacups::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}