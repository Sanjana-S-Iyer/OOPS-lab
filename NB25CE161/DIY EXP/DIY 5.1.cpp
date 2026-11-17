#include <iostream>
using namespace std;

class Counter {
    int value;
    static int created;   // total ever constructed
    static int alive;     // currently existing

public:
    Counter() : value(0) { created++; alive++; }

    // Copies are objects too, so they must be counted
    Counter(const Counter &other) : value(other.value) { created++; alive++; }

    ~Counter() { alive--; }

    void increment() { value++; }
    int  get() const { return value; }

    static int totalCreated() { return created; }
    static int currentlyAlive() { return alive; }
};

// Definitions of the static members (exactly once, outside the class)
int Counter::created = 0;
int Counter::alive   = 0;

void report(const string &label) {
    cout << label << " -> created: " << Counter::totalCreated()
         << ", alive: " << Counter::currentlyAlive() << endl;
}

int main() {
    report("Start               ");

    Counter a;
    Counter b;
    report("After a, b          ");

    {
        Counter c;
        Counter d(c);   // copy
        report("Inside block (c, d) ");
    }
    report("After block         ");

    Counter *p = new Counter;
    report("After new           ");

    delete p;
    report("After delete        ");
    return 0;
}