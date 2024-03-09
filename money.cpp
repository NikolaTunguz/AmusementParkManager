#include "money.h"

//default constructor
Money::Money(){
    dollars = 0;
    cents = 0;
    conversionRate = 1;
    usCurrency = true;
}

//parameterized constructor
Money::Money(int dollars, int cents, double conversionRate, bool usCurrency){
    dollars = dollars;
    cents = cents;
    conversionRate = conversionRate;
    usCurrency = usCurrency;
}

//copy constructor
Money::Money(const Money& oldMoney){
    dollars = oldMoney.dollars;
    cents = oldMoney.cents;
    conversionRate = oldMoney.conversionRate;
    usCurrency = oldMoney.usCurrency;
}

//basic getters and setters
int Money::getDollars(){
    return dollars;
}
void Money::setDollars(int newDollars){
    dollars = newDollars;
}
int Money::getCents(){
    return cents;
}
void Money::setCents(int newCents){
    cents = newCents;
}


double Money::getConversionRate(){
    return conversionRate;
}
void Money::setConversionRate(double newConversionRate){
    conversionRate = newConversionRate;
}


bool Money::getUsCurrency(){
    return usCurrency;
}
void Money::setUsCurrency(bool newUsCurrency){
    usCurrency = newUsCurrency;
}