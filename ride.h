/*
Author: Nikola Tunguz
Purpose: This is the Ride class. 
It is responsible for getting and setting number of tickets, ride name, and height restrictions for child classes.
*/

#ifndef RIDE_H
#define RIDE_H
#include <iostream>
using namespace std;

class Ride{
    //ride name and tickes needed to ride
    string name;
    int numTicketsNecessary; 

    protected:
      //true if the ride has a height restriction
      bool heightRestricted; 

    public:
      // Default constructor: name is NONE, numTicketsNecessary is 0, heightRestricted is true
      Ride();
      
      //Parameterized Constructor: sets number of tickets needed, ride name, height restriction
      Ride(int, string, bool);

      //Copy Constructor
      Ride(const Ride&);

      //get and set ride's amount of tickets
      int getNumTicketsNecessary();
      void setNumTicketsNecessary(int);

      //gets and sets ride name
      string getRideName();
      void setRideName(string);

      //gets and sets if there is a height restriction
      bool getHeightRestricted();

      // A virtual setter method to set if a ride is height restricted or not
      virtual void setHeightRestricted(bool) = 0;
       
};
#endif