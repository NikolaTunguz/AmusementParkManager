#include "ride.h"

//default constructor
Ride::Ride(){
    setRideName("NONE");
    setNumTicketsNecessary(0);
    heightRestricted = true;
}
//parameterized constructor
Ride::Ride(int num, string rideName, bool restricted){
    setRideName(rideName);
    setNumTicketsNecessary(num);
    heightRestricted = restricted;
}
//copy constructor
Ride::Ride(const Ride& oldRide){
    name = oldRide.name;
    numTicketsNecessary = oldRide.numTicketsNecessary;
    heightRestricted = oldRide.heightRestricted;
}

//basic setters and getters
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