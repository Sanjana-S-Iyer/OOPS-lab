#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "Tracer " << id << " created\n"; }
    ~Tracer()             { cout << "Tracer " << id << " destroyed\n"; }
};

class Matrix {
    int rows, cols;
    unique_ptr<int[]> data;   // replaces int** and manual delete[]

public:
    Matrix(int m, int n) : rows(m), cols(n), data(make_unique<int[]>(m * n)) {}

    // Deep copy
    Matrix(const Matrix &o)
        : rows(o.rows), cols(o.cols), data(make_unique<int[]>(o.rows * o.cols)) {
        for (int i = 0; i < rows * cols; i++) data[i] = o.data[i];
    }

    void set(int i, int j, int v) { data[i * cols + j] = v; }
    int  get(int i, int j) const  { return data[i * cols + j]; }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) cout << get(i, j) << " ";
            cout << "\n";
        }
    }
    // No destructor needed: unique_ptr frees the memory automatically
};

int main() {
    for (int i = 1; i <= 3; i++) {
        auto t = make_unique<Tracer>(i);   // no delete, and no leak
    }
    cout << "Loop finished\n";

    Matrix a(2, 3);
    int v = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) a.set(i, j, v++);

    Matrix b(a);
    b.set(0, 0, 99);

    cout << "a:\n"; a.print();
    cout << "b:\n"; b.print();
    return 0;
}