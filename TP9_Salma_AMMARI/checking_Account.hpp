#pragma once
#include "Account.hpp"

class checking_Account : public Account {
protected:
    static constexpr double per_check_fee = 1.5;
public:
    checking_Account(std::string name = "Unnamed Checking Account",
                     double balance = 0.0);
    virtual bool withdraw(double amount) override;
    virtual ~checking_Account() = default;
    friend std::ostream& operator<<(std::ostream& os, const checking_Account& account);
};