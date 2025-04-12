#pragma once
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "checking_Account.hpp"
#include "Trust_Account.hpp"

// Utility helper functions for Account class
void display(const std::vector<Account>& accounts);
void deposit(std::vector<Account>& accounts, double amount);
void withdraw(std::vector<Account>& accounts, double amount);

// Utility helper functions for Savings Account class
void display(const std::vector<Savings_Account>& accounts);
void deposit(std::vector<Savings_Account>& accounts, double amount);
void withdraw(std::vector<Savings_Account>& accounts, double amount);

// Utility helper functions for Checking Account class
void display(const std::vector<checking_Account>& accounts);
void deposit(std::vector<checking_Account>& accounts, double amount);
void withdraw(std::vector<checking_Account>& accounts, double amount);

// Utility helper functions for Trust Account class
void display(const std::vector<Trust_Account>& accounts);
void deposit(std::vector<Trust_Account>& accounts, double amount);
void withdraw(std::vector<Trust_Account>& accounts, double amount);