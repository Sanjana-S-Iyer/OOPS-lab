#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    // min-heap: top() is the smallest of the kept values
    priority_queue<int, vector<int>, greater<int>> heap;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        heap.push(x);
        if (heap.size() > 3)
            heap.pop();          // drop the smallest, keeping the 3 largest
    }

    // The heap pops smallest first, so collect and print in reverse
    vector<int> top;
    while (!heap.empty()) {
        top.push_back(heap.top());
        heap.pop();
    }

    cout << "Three largest: ";
    for (int i = (int)top.size() - 1; i >= 0; i--)
        cout << top[i] << " ";
    cout << endl;
    return 0;
}