#include <iostream>
#include <exception>
using namespace std;

class Overflow : public exception {
    int value;

public:
    Overflow(int v) : value(v) {}
    const char* what() const noexcept override { return "Stack overflow"; }
    int rejected() const { return value; }
};

class Underflow : public exception {
public:
    const char* what() const noexcept override { return "Stack underflow"; }
};

class Stack {
    int *buf;
    int capacity;
    int top;

public:
    Stack(int cap) : capacity(cap), top(0) { buf = new int[capacity]; }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    ~Stack() {
        delete[] buf;
        cout << "Stack destroyed" << endl;
    }

    void push(int x) {
        if (top == capacity) throw Overflow(x);
        buf[top++] = x;
    }

    int pop() {
        if (top == 0) throw Underflow();
        return buf[--top];
    }

    int cap() const { return capacity; }
};

int main() {
    Stack s(3);

    try {
        for (int v : {10, 20, 30, 40}) {
            s.push(v);
            cout << "Pushed " << v << endl;
        }
    }
    catch (const Overflow &e) {
        cout << e.what() << ": cannot push " << e.rejected()
             << ", stack is full (capacity " << s.cap() << ")" << endl;
    }

    try {
        for (int i = 0; i < 4; i++)
            cout << "Popped " << s.pop() << endl;
    }
    catch (const Underflow &e) {
        cout << e.what() << ": cannot pop, stack is empty" << endl;
    }

    return 0;
}