#include <iostream>
#include <stdexcept>
using namespace std;

class Fraction {
    int num, den;

    static int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b) { int t = a % b; a = b; b = t; }
        return a;
    }

    void simplify() {
        if (den == 0) throw invalid_argument("Denominator cannot be zero");
        if (den < 0) { num = -num; den = -den; }   // keep sign on numerator
        int g = gcd(num, den);
        if (g > 1) { num /= g; den /= g; }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) { simplify(); }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        if (f.den == 1) os << f.num;
        else            os << f.num << "/" << f.den;
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        int n, d;
        char slash;
        is >> n >> slash >> d;       // expects input like 12/18
        if (is && slash == '/') f = Fraction(n, d);   // constructor simplifies
        else is.setstate(ios::failbit);
        return is;
    }
};

int main() {
    Fraction f1(6, 8), f2(10, -4), f3(4, 2), f4(0, 5);
    cout << "Fraction(6, 8)   = " << f1 << endl;
    cout << "Fraction(10, -4) = " << f2 << endl;
    cout << "Fraction(4, 2)   = " << f3 << endl;
    cout << "Fraction(0, 5)   = " << f4 << endl;

    Fraction f;
    cout << "Enter a fraction (a/b): ";
    cin >> f;
    cout << "Simplified: " << f << endl;

    try {
        Fraction bad(3, 0);
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}