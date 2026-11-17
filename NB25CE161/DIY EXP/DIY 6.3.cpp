#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class SafeArray {
    int *data;
    int size;

public:
    SafeArray(int n) : size(n) {
        if (n <= 0) throw invalid_argument("Size must be positive");
        data = new int[size]();
    }

    // Deep copy so two arrays never share memory
    SafeArray(const SafeArray &o) : size(o.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = o.data[i];
    }

    SafeArray& operator=(const SafeArray &o) {
        if (this == &o) return *this;
        delete[] data;
        size = o.size;
        data = new int[size];
        for (int i = 0; i < size; i++) data[i] = o.data[i];
        return *this;
    }

    ~SafeArray() { delete[] data; }

    int& operator[](int i) {
        check(i);
        return data[i];
    }

    const int& operator[](int i) const {
        check(i);
        return data[i];
    }

    int length() const { return size; }

private:
    void check(int i) const {
        if (i < 0 || i >= size)
            throw out_of_range("Index " + to_string(i) +
                               " out of range (valid: 0 to " +
                               to_string(size - 1) + ")");
    }
};

int main() {
    SafeArray arr(5);
    for (int i = 0; i < arr.length(); i++)
        arr[i] = (i + 1) * 10;

    cout << "Contents: ";
    for (int i = 0; i < arr.length(); i++)
        cout << arr[i] << " ";
    cout << endl;

    try {
        cout << "arr[7] = " << arr[7] << endl;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        arr[-1] = 99;
    } catch (const out_of_range &e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "Program continues safely, no memory corrupted." << endl;
    return 0;
}