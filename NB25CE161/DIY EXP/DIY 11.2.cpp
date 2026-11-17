#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue {
    T *buf;
    int capacity;
    int head;    // index of front element
    int count;   // number of elements

    void grow() {
        int newCap = capacity * 2;
        T *nb = new T[newCap];
        for (int i = 0; i < count; i++)
            nb[i] = buf[(head + i) % capacity];
        delete[] buf;
        buf = nb;
        capacity = newCap;
        head = 0;
    }

public:
    Queue(int cap = 4) : capacity(cap), head(0), count(0) {
        buf = new T[capacity];
    }

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    ~Queue() { delete[] buf; }

    void enqueue(const T &x) {
        if (count == capacity) grow();
        buf[(head + count) % capacity] = x;
        count++;
    }

    T dequeue() {
        if (count == 0) throw runtime_error("Queue is empty");
        T x = buf[head];
        head = (head + 1) % capacity;
        count--;
        return x;
    }

    const T& front() const {
        if (count == 0) throw runtime_error("Queue is empty");
        return buf[head];
    }

    bool empty() const { return count == 0; }
    int size() const   { return count; }
};

int main() {
    Queue<string> q;

    q.enqueue("Asha");
    q.enqueue("Ravi");
    q.enqueue("Meera");
    q.enqueue("Kiran");
    q.enqueue("Divya");     // triggers growth

    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.front() << endl;

    while (!q.empty())
        cout << "Dequeued: " << q.dequeue() << endl;

    try {
        q.dequeue();
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}