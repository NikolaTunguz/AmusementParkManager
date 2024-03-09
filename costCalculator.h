/*!
 * This is the costCalculator class. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for calculating the cost, money given, and the change of a patron buying tickets
*/
#ifndef COSTCALCULATOR_H
#define COSTCALCULATOR_H

#include <iostream>
using namespace std;

#include "money.h"

template <class Type>
class CostCalculator{
    int amount = 0;
    double cost = 0;
    double change = 0;
    Type currency;

    public:
        CostCalculator();
        CostCalculator(double, double, int, Type);
        CostCalculator(const CostCalculator&);

        double getCost();
        void setCost(double);

        double getChange();
        void setChange(double);

        int getAmount();
        void setAmount(int);

        Type getCurrency();
        void setCurrency(Type);

        void calcCost();
        void calcChange(double);

        template <class T>
        friend ostream& operator << ( ostream& output, CostCalculator<T>& calculator);

};

#endif