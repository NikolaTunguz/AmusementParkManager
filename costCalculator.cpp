#include "costCalculator.h"

//default constructor
template <class Type>
CostCalculator<Type>::CostCalculator(){
    cost = 0;
    change = 0;
    amount = 0;
    currency = Type();
}
//parameterized constructor
template <class Type>
CostCalculator<Type>::CostCalculator(double newCost, double newChange, int newAmount, Type newCurrency){
    cost = newCost;
    change = newChange;
    amount = newAmount;
    currency = newCurrency;
}
//copy constructor
template <class Type>
CostCalculator<Type>::CostCalculator(const CostCalculator& oldCalculator){
    cost = oldCalculator.cost;
    change = oldCalculator.change;
    amount = oldCalculator.amount;
    currency = oldCalculator.currency;
}

//basic getters and setters
template <class Type>
double CostCalculator<Type>::getCost(){
    return cost;
}
template <class Type>
void CostCalculator<Type>::setCost(double newCost){
    cost = newCost;
}

template <class Type>
double CostCalculator<Type>::getChange(){
    return change;
}

template <class Type>
void CostCalculator<Type>::setChange(double newChange){
    change = newChange;
}

template <class Type>
int CostCalculator<Type>::getAmount(){
    return amount;
}
template <class Type>
void CostCalculator<Type>::setAmount(int newAmount){
    amount = newAmount;
}

template <class Type>
Type CostCalculator<Type>::getCurrency(){
    return currency;
}

template <class Type>
void CostCalculator<Type>::setCurrency( Type newCurrency){
    currency = newCurrency;
}

//calculating transactions
template <class Type>
void CostCalculator<Type>::calcCost(){
    cost = amount * currency.getConversionRate() * 1.0175;
}
template <class Type>
void CostCalculator<Type>::calcChange(double userCurrency){
    change = userCurrency - cost;
}

template class CostCalculator<Money>;