#include <iostream>
#include <string>
#include <exception>
using namespace std;

class MathError : public exception {
    string msg;
public:
    MathError(const string &m = "Math error") : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

class DivideByZero : public MathError {
public:
    DivideByZero() : MathError("Division by zero") {}
};

int divide(int a, int b) {
    if (b == 0) throw DivideByZero();
    return a / b;
}

void test(int a, int b, bool generic) {
    try {
        if (generic) throw MathError("Unspecified math problem");
        cout << a << " / " << b << " = " << divide(a, b) << endl;
    }
    catch (const DivideByZero &e) {       // most specific first
        cout << "DivideByZero handler: " << e.what() << endl;
    }
    catch (const MathError &e) {          // general fallback last
        cout << "MathError handler: " << e.what() << endl;
    }
}

int main() {
    test(10, 2, false);
    test(10, 0, false);
    test(0, 0, true);
    return 0;
}