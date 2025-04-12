#include "checking_Account.hpp"

checking_Account::checking_Account(std::string name, double balance)
        : Account(name, balance) {}

bool checking_Account::withdraw(double amount) {
    double total_amount = amount + per_check_fee;
    if (balance >= total_amount && amount > 0) {
        balance -= total_amount;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const checking_Account& account) {
    os << "[Checking Account: " << account.name
       << " | Balance: " << account.balance << " MAD]";
    return os;
}