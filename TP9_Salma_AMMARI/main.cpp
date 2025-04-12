#include <iostream>
#include <vector>
#include "Account.hpp"
#include "Savings_Account.hpp"
#include "checking_Account.hpp"
#include "Trust_Account.hpp"
#include "Account_Util.hpp"

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;

    // Accounts
    std::vector<Account> accounts {
            Account{},
            Account{"Larry"},
            Account{"Moe", 2000},
            Account{"Curly", 5000}
    };

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings Accounts
    std::vector<Savings_Account> sav_accounts {
            Savings_Account{},
            Savings_Account{"Superman"},
            Savings_Account{"Batman", 2000},
            Savings_Account{"Wonderwoman", 5000, 5.0}
    };

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking Accounts
    std::vector<checking_Account> check_accounts {
            checking_Account{},
            checking_Account{"Kirk"},
            checking_Account{"Spock", 2000},
            checking_Account{"Bones", 5000}
    };

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);

    // Trust Accounts
    std::vector<Trust_Account> trust_accounts {
            Trust_Account{},
            Trust_Account{"Athos", 10000, 5.0},
            Trust_Account{"Porthos", 20000, 4.0},
            Trust_Account{"Aramis", 30000}
    };

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 3000);

    // Test Trust Account withdrawal limits
    for (int i = 1; i <= 5; i++)
        withdraw(trust_accounts, 1000);

    return 0;
}