#include "patron.h"

Patron::Patron(){
    numRides = 0;
    setFirstName("NONE");
    setLastName("NONE");
    setPatronNumber(-1);
    setNumTickets(0);

    patronRides = new Ride*[100];
}
Patron::Patron(string first, string last, int patronNum, int numRides, int numT, Ride* rideArray){
    setFirstName(first);
    setLastName(last);
    setPatronNumber(patronNum);
    numRides = numRides;
    setNumTickets(numT);
    for(int i = 0; i < numRides; i++){
        patronRides[i] = &rideArray[i];
    }
}
Patron::Patron(const Patron& oldPatron){
    setFirstName(oldPatron.firstName);
    setLastName(oldPatron.lastName);
    setPatronNumber(oldPatron.patronNumber);
    setNumTickets(oldPatron.numTickets);
    numRides = oldPatron.numRides;

    for(int i = 0; i < numRides; i++){
        patronRides[i] = oldPatron.patronRides[i];
    }


}

//Patron::~Patron(){
//    delete [] patronRides;
//}

string Patron::getFirstName(){
    return firstName;
}
void Patron::setFirstName(string first){
    firstName = first;
}
string Patron::getLastName(){
    return lastName;
}
void Patron::setLastName(string last){
    lastName = last;
}
int Patron::getPatronNumber(){
    return patronNumber;
}
void Patron::setPatronNumber(int num){
    patronNumber = num;
}


Ride** Patron::getPatronRides(){
    return patronRides;
}

void Patron::addPatronRide(Ride* newRide){
    patronRides[numRides] = newRide;
    numRides++;
}

void Patron::displayName(){
    cout << getFirstName() <<  " " << getLastName() << endl;
}

void Patron::displayPatronData(){
    cout << getFirstName() <<  " " << getLastName() << " " << getPatronNumber() << " " << getNumTickets() << endl << "Has admittance to: ";
    for(int i = 0; i < numRides; i++){
        string name = patronRides[i] -> getRideName();
        cout << name << " ";
    }
    cout << endl;
}

void Patron::setNumTickets(int num){
    numTickets = num;
}

int Patron::getNumTickets(){
    return numTickets;
}
