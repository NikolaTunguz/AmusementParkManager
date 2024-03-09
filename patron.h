/*
Author: Nikola Tunguz
Purpose: This is the patron class. 
It is responsible for getting and setting a patron's first name, last name, and patron number,
the number of rides that a patron has tickets for, the number of remaining tickets for the patron
and an array of rides that a patron has signed up for
*/

#ifndef PATRON_H
#define PATRON_H

#include "magicCarpet.h"
#include "teacups.h"
#include "worldTour.h"

class Patron{
    //patron information variables
    string firstName, lastName; 
    int patronNumber = 0;
    int numTickets = 0;
    int numRides = 0;
    //array of rides (max size 100)
    Ride** patronRides; 

    public:
        //Default Constructor: sets default values seen in patron.cpp
        Patron();
        //Parameterized Constructor: sets variables to passed values
        Patron(string, string, int, int, int, Ride*);
        //Copy Constructor
        Patron(const Patron&);

        //gets and sets patron's name
        string getFirstName();
        void setFirstName(string);
        string getLastName();
        void setLastName(string);
        
        //gets and sets patron's ID number
        int getPatronNumber();
        void setPatronNumber(int);

        //gets and sets patron's ticket count
        int getNumTickets();
        void setNumTickets(int);
      
        //gets patron ride information
        Ride** getPatronRides();

        //adds rides to the patron
        void addPatronRide(Ride*);
        void addRideNames(string);

        //displays patron's full name and data
        void displayName();
        void displayPatronData();
      
};
#endif