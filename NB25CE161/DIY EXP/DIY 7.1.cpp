#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &n, int i) : name(n), id(i) {}

    void print() const {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class Manager : public Employee {
    int teamSize;

public:
    Manager(const string &n, int i, int t) : Employee(n, i), teamSize(t) {}

    void print() const {
        cout << "[Manager]  ";
        Employee::print();
        cout << "           Team size: " << teamSize << endl;
    }
};

class Engineer : public Employee {
    string skill;

public:
    Engineer(const string &n, int i, const string &s) : Employee(n, i), skill(s) {}

    void print() const {
        cout << "[Engineer] ";
        Employee::print();
        cout << "           Skill: " << skill << endl;
    }
};

int main() {
    Employee e("Asha", 101);
    Manager m("Ravi", 102, 8);
    Engineer g("Meera", 103, "C++");

    cout << "[Employee] "; e.print();
    m.print();
    g.print();
    return 0;
}