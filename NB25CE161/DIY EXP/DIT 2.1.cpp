#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979;

// Cube: 1 argument (side)
double volume(double side) {
    return side * side * side;
}

// Cuboid: 3 arguments (length, width, height)
double volume(double l, double w, double h) {
    return l * w * h;
}

// Cylinder: 2 arguments (radius, height)
double volume(double r, double h) {
    return PI * r * r * h;
}

int main() {
    cout << fixed << setprecision(2);
    cout << "Cube (side = 3): " << volume(3.0) << endl;
    cout << "Cuboid (2 x 3 x 4): " << volume(2.0, 3.0, 4.0) << endl;
    cout << "Cylinder (r = 3, h = 5): " << volume(3.0, 5.0) << endl;
    return 0;
}