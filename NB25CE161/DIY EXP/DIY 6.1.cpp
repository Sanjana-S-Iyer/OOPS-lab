#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long totalPaise;   // single source of truth: carry/borrow is automatic

public:
    Money(long long rupees = 0, long long paise = 0)
        : totalPaise(rupees * 100 + paise) {}

    Money operator+(const Money &o) const {
        Money r;
        r.totalPaise = totalPaise + o.totalPaise;
        return r;
    }

    Money operator-(const Money &o) const {
        Money r;
        r.totalPaise = totalPaise - o.totalPaise;
        return r;
    }

    void show() const {
        long long t = totalPaise;
        if (t < 0) { cout << "-"; t = -t; }
        cout << "Rs. " << t / 100 << "."
             << setfill('0') << setw(2) << t % 100 << setfill(' ');
    }
};

int main() {
    Money a(10, 75), b(5, 50);
    cout << "a = "; a.show(); cout << endl;
    cout << "b = "; b.show(); cout << endl;

    cout << "a + b = "; (a + b).show(); cout << "   (paise carry into rupees)" << endl;

    Money c(20, 10), d(5, 40);
    cout << "c = "; c.show(); cout << endl;
    cout << "d = "; d.show(); cout << endl;
    cout << "c - d = "; (c - d).show(); cout << "   (borrow from rupees)" << endl;

    cout << "d - c = "; (d - c).show(); cout << "   (negative result)" << endl;
    return 0;
}