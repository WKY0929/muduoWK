#include"account.hpp"

Account::Account(double money):money_(money){}
double Account::getMoney(){
    return money_;
}
void Account::addMoney(double x){
    money_+=x;
}
void Account::subMoney(double x){
    money_-=x;
}