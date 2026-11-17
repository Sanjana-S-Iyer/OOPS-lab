#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<pair<string, int>> v = {
        {"Asha", 78},
        {"Ravi", 91},
        {"Meera", 85},
        {"Kiran", 67},
        {"Divya", 85}
    };

    // Ascending by the integer field; stable_sort keeps the original
    // order of ties (Meera stays before Divya)
    stable_sort(v.begin(), v.end(),
                [](const pair<string, int> &a, const pair<string, int> &b) {
                    return a.second < b.second;
                });

    for (const auto &p : v)
        cout << p.first << " " << p.second << endl;
    return 0;
}