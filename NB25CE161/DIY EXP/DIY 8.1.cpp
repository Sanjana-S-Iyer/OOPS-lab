#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Account {
protected:
    string holder;
    double balance;

public:
    Account(const string &h, double b) : holder(h), balance(b) {}
    virtual ~Account() {}

    // Pure virtual: makes Account abstract
    virtual double calculateInterest() const = 0;
    virtual string type() const = 0;

    void show() const {
        cout << left << setw(9) << type()
             << setw(8) << holder
             << "Balance: " << setw(10) << balance
             << "Interest: " << calculateInterest() << endl;
    }
};

class Savings : public Account {
    static constexpr double RATE = 0.04;   // 4% per year

public:
    Savings(const string &h, double b) : Account(h, b) {}
    double calculateInterest() const override { return balance * RATE; }
    string type() const override { return "Savings"; }
};

class Current : public Account {
    static constexpr double RATE = 0.01;   // 1% per year

public:
    Current(const string &h, double b) : Account(h, b) {}
    double calculateInterest() const override { return balance * RATE; }
    string type() const override { return "Current"; }
};

int main() {
    cout << fixed << setprecision(2);

    Account *accounts[4] = {
        new Savings("Asha", 50000),
        new Current("Ravi", 80000),
        new Savings("Meera", 120000),
        new Current("Kiran", 25000)
    };

    double total = 0;
    for (int i = 0; i < 4; i++) {
        accounts[i]->show();
        total += accounts[i]->calculateInterest();
    }
    cout << "Total interest payable: " << total << endl;

    for (int i = 0; i < 4; i++) delete accounts[i];   // virtual destructor
    return 0;
}