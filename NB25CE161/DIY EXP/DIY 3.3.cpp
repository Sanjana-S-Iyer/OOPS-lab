#include <iostream>
using namespace std;

// Smaller of two integers
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Smallest of three integers
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "minVal(8, 3)     = " << minVal(8, 3) << endl;
    cout << "minVal(9, 4, 6)  = " << minVal(9, 4, 6) << endl;
    cout << "minVal(7, 12, 5) = " << minVal(7, 12, 5) << endl;
    return 0;
}