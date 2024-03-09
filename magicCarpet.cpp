#include "magicCarpet.h"

MagicCarpet::MagicCarpet(){
    setNumTicketsNecessary(2);
    setRideName("Magic Carpet");
    setHeightRestricted(true);
}


void MagicCarpet::setHeightRestricted(bool restricted){
    heightRestricted = restricted;
}