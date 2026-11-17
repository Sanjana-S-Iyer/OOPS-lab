#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
    int *buf;
    int capacity;
    int top;   // number of elements

    void grow() {
        int newCap = capacity * 2;
        int *nb = new int[newCap];
        for (int i = 0; i < top; i++) nb[i] = buf[i];
        delete[] buf;
        buf = nb;
        capacity = newCap;
        cout << "  (grew to capacity " << capacity << ")\n";
    }

public:
    Stack(int cap = 2) : capacity(cap), top(0) {
        buf = new int[capacity];
    }

    // Disable copying to avoid double-free
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        delete[] buf;
        cout << "Stack destroyed, buffer released\n";
    }

    void push(int x) {
        if (top == capacity) grow();
        buf[top++] = x;
    }

    int pop() {
        if (top == 0) throw runtime_error("Stack underflow");
        return buf[--top];
    }

    bool empty() const { return top == 0; }
    int size() const   { return top; }
};

int main() {
    Stack s;
    for (int i = 1; i <= 5; i++) {
        cout << "push " << i * 10 << "\n";
        s.push(i * 10);
    }

    cout << "size = " << s.size() << "\n";
    while (!s.empty())
        cout << "pop  " << s.pop() << "\n";

    try {
        s.pop();
    } catch (const exception &e) {
        cout << "Error: " << e.what() << "\n";
    }
    return 0;
}