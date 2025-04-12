#pragma once
#include "Account.hpp"

class Savings_Account : public Account {
protected:
    double int_rate;
    static constexpr double def_int_rate = 0.0;
public:
    Savings_Account(std::string name = "Unnamed Savings Account",
                    double balance = 0.0,
                    double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual ~Savings_Account() = default;
    friend std::ostream& operator<<(std::ostream& os, const Savings_Account& account);
};