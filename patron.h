#ifndef PATRON_H
#define PATRON_H

#include "magicCarpet.h"
#include "teacups.h"
#include "worldTour.h"
/*!
 * This is the patron class. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting patron first name, last name, the patron number
 * the number of rides that a patron has tickets for, the number of REMAINING tickets for the patron
 * and an array of rides that a patron has signed up for (max size 100)
*/
class Patron{
    string firstName, lastName; /*< string value of first name and last name*/
    int patronNumber = 0;
    int numTickets = 0;
    int numRides = 0; /*<int values of patron number, number of rides currently assigned to patron, and number of tickets patron has remaining*/
    
    Ride** patronRides; /*< array of rides (max size 100)*/
    
    
    //int numTeacups, numWorldTour, numMagicCarpet;
    //MagicCarpet magicCarpetRides[100];
    //Teacups teacupsRides[100];
    //WorldTour worldTourRides[100];
   

    public:
        //! The default constructor. You can choose what to set values to.
        Patron();
        /*! The parameterized Constructor
         \param first; string first name to set patron first
         \param last; string last name to set patron last
         \param pNum; int patron number
         \param numR; int number of rides the user has tickets for
         \param numT; int number of tickets user has remaining
         \param patronR; pointer to array of rides
        */
        Patron(string, string, int, int, int, Ride*);
        /*! The copy constructor
         * Make sure you create a loop using the old patron's number of rides to set all the rides in the array
         * Set all appropriate properties
         */
        Patron(const Patron&);

        //~Patron();

        /*! getter for first name
         \return first name; a string
        */
        string getFirstName();
        /*! setter for first name
         \param first; string first name to set patron first
        */
        void setFirstName(string);
        /*! getter for last name
         \return last name; a string last name for a set patron
        */
        string getLastName();
        /*! setter for last name
         \param last name; a string last name
        */
        void setLastName(string);
        /*! getter for patron number
         \return patron number; an int
        */
        int getPatronNumber();
        /*! setter for patron number
         \param patron number; an int identifier number
        */
        void setPatronNumber(int);


        /*! getter for patron rides array
         \return a pointer to the patron's ride array
        */
        Ride** getPatronRides();


        /*! add a ride to the patron ride array
         \param newRide; a Ride to add to the existing rideArray
        */

        void addPatronRide(Ride*);
        //void addTeacupsRide(Teacups);
        //void addWorldTourRide(WorldTour);
        //void addMagicCarpetRide(MagicCarpet);

        /*! displays a patron's first and last name to the terminal*/
        void displayName();
        /*! getter for number of tickets a patron has remaining
         \return numTickets; an int 
        */
        int getNumTickets();
        /*! setter for number of tickets a patron has remaining
         \param num; an integer number of tickets that the patron has remaining
        */
        void setNumTickets(int);
        /*! displays all of a patron's information (first name, last name, patron number, number of rides, number tickets remaining, and name of rides in ride array)
        */
        void displayPatronData();

        void addRideNames(string);
};
#endif