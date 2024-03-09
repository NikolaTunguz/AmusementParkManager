/*!
 * This is the money class. 
 * It is responsible for storing a quantity of money and if it is US currency or not, and the rate it takes to purchase a single ticket.
*/
#ifndef MONEY_H
#define MONEY_H

class Money{
    int dollars;
    int cents;
    double conversionRate;
    bool usCurrency;

    public:
        Money();
        Money(int,int, double, bool);
        Money(const Money&);

        int getDollars();
        void setDollars(int);
        int getCents();
        void setCents(int);

        double getConversionRate();
        void setConversionRate(double);

        bool getUsCurrency();
        void setUsCurrency(bool);
};

#endif