#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> v = {2, 3, 4, 5, 6, 7};

    // Product of all elements
    long long product = accumulate(v.begin(), v.end(), 1LL,
        [](long long acc, int x) { return acc * x; });

    // Sum of only the even elements
    int evenSum = accumulate(v.begin(), v.end(), 0,
        [](int acc, int x) { return (x % 2 == 0) ? acc + x : acc; });

    cout << "Elements: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    cout << "Product of all:  " << product << endl;
    cout << "Sum of evens:    " << evenSum << endl;
    return 0;
}