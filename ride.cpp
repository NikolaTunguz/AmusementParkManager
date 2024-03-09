#include "ride.h"

Ride::Ride(){
    setRideName("NONE");
    setNumTicketsNecessary(0);
    //setHeightRestricted(true);
    heightRestricted = true;
}
Ride::Ride(int num, string rideName, bool restricted){
    setRideName(rideName);
    setNumTicketsNecessary(num);
    //setHeightRestricted(restricted);
    heightRestricted = restricted;
}
Ride::Ride(const Ride& oldRide){
    name = oldRide.name;
    numTicketsNecessary = oldRide.numTicketsNecessary;
    heightRestricted = oldRide.heightRestricted;
}
int Ride::getNumTicketsNecessary(){
    return numTicketsNecessary;
}
void Ride::setNumTicketsNecessary(int num){
    numTicketsNecessary = num;
}
string Ride::getRideName(){
    return name;
}
void Ride::setRideName(string newName){
    name = newName;
}
bool Ride::getHeightRestricted(){
    return heightRestricted;
}

/*
void Ride::setHeightRestricted(bool restricted){
    heightRestricted= restricted;
}
*/
