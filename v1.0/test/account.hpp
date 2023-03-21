#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP
class Account
{
    private:
        double money_;

    public:
        Account(double money);
        ~Account()=default;
        double getMoney();
        void subMoney(double x);
        void addMoney(double x);
};

#endif