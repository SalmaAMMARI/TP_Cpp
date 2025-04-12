#pragma once
#include <string>
#include <iostream>

class Account {
protected:
    std::string name;
    double balance;
public:
    Account(std::string name = "Unnamed Account", double balance = 0.0);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual ~Account() = default;
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};