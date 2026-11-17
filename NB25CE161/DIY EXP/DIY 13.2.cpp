#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual string name() const = 0;
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : r(r) {}
    double area() const override { return 3.14159265 * r * r; }
    string name() const override { return "Circle"; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double l, double w) : l(l), w(w) {}
    double area() const override { return l * w; }
    string name() const override { return "Rectangle"; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    string name() const override { return "Triangle"; }
};

unique_ptr<Shape> makeShape(string type) {
    transform(type.begin(), type.end(), type.begin(),
              [](unsigned char c) { return tolower(c); });

    if (type == "circle") {
        double r; cout << "  radius: "; cin >> r;
        return make_unique<Circle>(r);
    }
    if (type == "rectangle") {
        double l, w; cout << "  length and width: "; cin >> l >> w;
        return make_unique<Rectangle>(l, w);
    }
    if (type == "triangle") {
        double b, h; cout << "  base and height: "; cin >> b >> h;
        return make_unique<Triangle>(b, h);
    }
    return nullptr;   // unknown name
}

int main() {
    vector<unique_ptr<Shape>> shapes;
    string type;

    cout << "Enter shape name (circle/rectangle/triangle), or 'done': ";
    while (cin >> type && type != "done") {
        auto s = makeShape(type);
        if (s) shapes.push_back(move(s));
        else   cout << "  Unknown shape '" << type << "'\n";
        cout << "Enter shape name (circle/rectangle/triangle), or 'done': ";
    }

    cout << "\nShapes created: " << shapes.size() << endl;
    double total = 0;
    for (const auto &s : shapes) {
        cout << s->name() << " area = " << s->area() << endl;
        total += s->area();
    }
    cout << "Total area = " << total << endl;
    return 0;   // vector destroys every unique_ptr, freeing every shape
}