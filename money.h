/*
Author: Nikola Tunguz
Purpose: This is the money class. 
It is responsible for storing a quantity of money and if it is US currency or not, and the rate it takes to purchase a single ticket.
*/

#ifndef MONEY_H
#define MONEY_H

class Money{
    //currency variables
    int dollars;
    int cents;
    double conversionRate;
    bool usCurrency;

    public:
        //Default constructor: sets dollars and cents to 0, conversion rate to 1, and usCurrency to true
        Money();
        //Parameterized constructor: sets variables to passed values
        Money(int,int, double, bool);
        //Copy constructor
        Money(const Money&);

        //gets and sets dollars and cents
        int getDollars();
        void setDollars(int);
        int getCents();
        void setCents(int);

        //gets and sets conversion rate to tickets
        double getConversionRate();
        void setConversionRate(double);

        //gets and sets boolean usCurrency
        bool getUsCurrency();
        void setUsCurrency(bool);
};

#endif