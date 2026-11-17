#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int **data;

public:
    Matrix(int m, int n) : rows(m), cols(n) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols]();   // () zero-initializes
    }

    // Deep copy constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
    }

    // Copy assignment (rule of three), so "a = b" is also safe
    Matrix& operator=(const Matrix &other) {
        if (this == &other) return *this;
        for (int i = 0; i < rows; i++) delete[] data[i];
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
        cout << "Matrix (" << rows << "x" << cols << ") freed\n";
    }

    void set(int i, int j, int v) { data[i][j] = v; }
    int  get(int i, int j) const  { return data[i][j]; }

    void print(const string &name) const {
        cout << name << ":\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Matrix a(2, 3);
    int v = 1;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            a.set(i, j, v++);

    Matrix b(a);          // deep copy
    b.set(0, 0, 99);      // change the copy only

    a.print("a");
    b.print("b (copy, modified)");
    return 0;
}