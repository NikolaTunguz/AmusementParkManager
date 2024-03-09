/*!
 * This is the Ride class
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting number of tickets, ride name, and height restrictions for teacups, worldTour, and magicCarpet
 * 
*/

#ifndef RIDE_H
#define RIDE_H
#include <iostream>
using namespace std;
class Ride{
    int numTicketsNecessary; /*!<number of tickets a ride requires for entry*/
    string name;/*!<the name of the ride (teacup, magic carpet, world tour)*/
    protected:
      bool heightRestricted; /*!<if true, ride is height restricted. Otherwise, it isn't.*/

    public:
      /*! Default constructor
       * name is NONE
       * numTicketsNecessary is 0
       * heightRestricted is true
      */
      Ride();
      /*! Parameterized Constructor; sets passed in variables
       \param numRideTickets integer argument to set numTickets
       \param name string argument to set rideName
       \param height bool argument to set heightRestricted
      */
      Ride(int, string, bool);
      /*! Copy Constructor; copies properties from one ride class object to another
       \param oldRide Ride address object (&)
      */
      Ride(const Ride&);
      /*! A getter method to return number of tickets required to ride the ride
       \return an integer number of tickets to ride the ride
      */
      int getNumTicketsNecessary();
      /*! A setter method to set the number of tickets in a ride object required to ride it
       \param numTicket; integer argument to set number of tickets in the ride object
      */ 
      void setNumTicketsNecessary(int);
      /*! A getter method to return ride name
       \param name; string argument to set ride name in the ride object
      */
      string getRideName();
      /*! A setter method to set the ride name in a ride object
       \return the string name of the ride
      */
      void setRideName(string);
      /*! a getter method to return if the ride is height restricted
       \return the height restriction bool; true if restricted, otherwise false
      */
      bool getHeightRestricted();

      
      /*! A setter method to set if a ride is height restricted or not
       \param heightRestriction; bool argument to set if the ride is height restricted
      */
      virtual void setHeightRestricted(bool) = 0;
       
};
#endif