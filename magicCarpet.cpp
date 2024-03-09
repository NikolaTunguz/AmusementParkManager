#include "magicCarpet.h"

//Default Constructor
MagicCarpet::MagicCarpet(){
    setNumTicketsNecessary(2);
    setRideName("Magic Carpet");
    setHeightRestricted(true);
}

//Height Restriction Setter
void MagicCarpet::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}