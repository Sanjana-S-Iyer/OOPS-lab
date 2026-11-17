#include <iostream>
using namespace std;

template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(T arr[], int n) {
    T best = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > best) best = arr[i];
    return best;
}

int main() {
    // int
    int a = 5, b = 9;
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapVals(a, b);
    cout << "After swap:  a = " << a << ", b = " << b << endl;

    int ia[] = {12, 45, 7, 89, 23};
    cout << "Max of int array: " << findMax(ia, 5) << endl;

    // double
    double x = 1.5, y = 2.75;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapVals(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    double da[] = {3.14, 2.71, 9.81, 1.41};
    cout << "Max of double array: " << findMax(da, 4) << endl;

    return 0;
}