#include <iostream>
#include <iomanip>
using namespace std;

class Time {
    int hh, mm;

public:
    Time(int h = 0, int m = 0) : hh(h), mm(m) {}

    void show() const {
        cout << setfill('0') << setw(2) << hh << ":"
             << setw(2) << mm << setfill(' ');
    }

    // Friend: not a member, but can read private hh and mm
    friend Time laterOf(Time a, Time b);
};

Time laterOf(Time a, Time b) {
    int ta = a.hh * 60 + a.mm;
    int tb = b.hh * 60 + b.mm;
    return (ta >= tb) ? a : b;
}

int main() {
    Time t1(9, 45), t2(14, 30);
    Time t3(23, 15), t4(23, 5);

    cout << "Later of ";
    t1.show(); cout << " and "; t2.show(); cout << " is ";
    laterOf(t1, t2).show(); cout << endl;

    cout << "Later of ";
    t3.show(); cout << " and "; t4.show(); cout << " is ";
    laterOf(t3, t4).show(); cout << endl;

    return 0;
}