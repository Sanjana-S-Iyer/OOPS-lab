// fixed.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base()  { cout << "Base constructor\n"; }
    virtual ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base {
    int *buffer;

public:
    Derived() {
        buffer = new int[100];
        cout << "Derived constructor (allocated 400 bytes)\n";
    }
    ~Derived() override {
        delete[] buffer;
        cout << "Derived destructor (buffer freed)\n";
    }
};

int main() {
    Base *p = new Derived();
    delete p;          // now calls ~Derived, then ~Base
    return 0;
}