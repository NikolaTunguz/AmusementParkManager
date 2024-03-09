/*
Author: Nikola Tunguz
Purpose: This is the templated costCalculator class. 
It is responsible for calculating the cost, money given, and the change of a patron buying tickets
*/

#ifndef COSTCALCULATOR_H
#define COSTCALCULATOR_H

#include <iostream>
using namespace std;

#include "money.h"

template <class Type>
class CostCalculator{
    //currency variables
    int amount = 0;
    double cost = 0;
    double change = 0;
    Type currency;

    public:
        //Default Constructor: sets all variables to 0, and currency to the <Type>
        CostCalculator();
        //Parameterized Constructor: sets variables to passed values
        CostCalculator(double, double, int, Type);
        //Copy Constructor
        CostCalculator(const CostCalculator&);

        //gets and sets cost
        double getCost();
        void setCost(double);

        //gets and sets change 
        double getChange();
        void setChange(double);

        //gets and sets amount
        int getAmount();
        void setAmount(int);

        //gets and sets currency type
        Type getCurrency();
        void setCurrency(Type);

        //calculates the cost & change of tranactions
        void calcCost();
        void calcChange(double);

        template <class T>
        friend ostream& operator << ( ostream& output, CostCalculator<T>& calculator);

};

#endif