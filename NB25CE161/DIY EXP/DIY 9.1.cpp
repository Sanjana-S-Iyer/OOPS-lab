#include <iostream>
#include <iomanip>
#include <exception>
using namespace std;

class InsufficientFunds : public exception {
    double balance, requested;

public:
    InsufficientFunds(double bal, double req) : balance(bal), requested(req) {}

    const char* what() const noexcept override { return "Insufficient funds"; }

    double getBalance() const   { return balance; }
    double getRequested() const { return requested; }
    double shortfall() const    { return requested - balance; }
};

class BankAccount {
    double balance;

public:
    BankAccount(double b = 0) : balance(b) {}

    void deposit(double amt) { balance += amt; }

    // Before: returned false. Now: throws.
    void withdraw(double amt) {
        if (amt > balance)
            throw InsufficientFunds(balance, amt);
        balance -= amt;
    }

    double getBalance() const { return balance; }
};

int main() {
    cout << fixed << setprecision(2);

    BankAccount acc(5000);
    cout << "Initial balance: " << acc.getBalance() << endl;

    try {
        acc.withdraw(2000);
        cout << "Withdrew 2000.00, balance now " << acc.getBalance() << endl;

        acc.withdraw(4000);   // too much: throws
        cout << "This line is never reached\n";
    }
    catch (const InsufficientFunds &e) {
        cout << "Error: " << e.what() << endl;
        cout << "  Balance: " << e.getBalance()
             << ", requested: " << e.getRequested()
             << ", short by: " << e.shortfall() << endl;
    }

    cout << "Final balance: " << acc.getBalance() << endl;
    return 0;
}