// fixed.cpp
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;

void work() {
    for (int i = 0; i < 100000; i++) {
        lock_guard<mutex> lock(m);   // locked here, released at end of iteration
        counter++;
    }
}

int main() {
    thread t1(work), t2(work);
    t1.join();
    t2.join();
    cout << "Total = " << counter << " (expected 200000)" << endl;
    return 0;
}