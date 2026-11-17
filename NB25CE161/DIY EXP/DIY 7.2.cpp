#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;

public:
    Shape(const string &n) : name(n) {
        cout << "Shape constructor: name = " << name << endl;
    }
    ~Shape() { cout << "Shape destructor" << endl; }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(const string &n, int s) : Shape(n), sides(s) {
        cout << "Polygon constructor: sides = " << sides << endl;
    }
    ~Polygon() { cout << "Polygon destructor" << endl; }
};

class Rectangle : public Polygon {
    double length, width;

public:
    Rectangle(double l, double w) : Polygon("Rectangle", 4), length(l), width(w) {
        cout << "Rectangle constructor: " << length << " x " << width << endl;
    }
    ~Rectangle() { cout << "Rectangle destructor" << endl; }

    double area() const { return length * width; }
};

int main() {
    cout << "Creating Rectangle...\n";
    {
        Rectangle r(5, 3);
        cout << "Area = " << r.area() << endl;
        cout << "Leaving scope...\n";
    }
    cout << "Done.\n";
    return 0;
}