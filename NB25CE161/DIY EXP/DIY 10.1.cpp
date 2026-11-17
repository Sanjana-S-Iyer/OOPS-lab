#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main() {
    ifstream in("nums.txt");
    if (!in) {
        cerr << "Error: cannot open nums.txt" << endl;
        return 1;
    }

    int x, count = 0;
    long long sum = 0;
    int mn = INT_MAX, mx = INT_MIN;

    while (in >> x) {            // stops at EOF or bad input
        count++;
        sum += x;
        if (x < mn) mn = x;
        if (x > mx) mx = x;
    }

    if (count == 0) {
        cout << "File has no integers." << endl;
        return 0;
    }

    cout << "Count: " << count << endl;
    cout << "Sum:   " << sum << endl;
    cout << "Min:   " << mn << endl;
    cout << "Max:   " << mx << endl;
    return 0;
}