#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string &n = "Unknown") : name(n) {
        cout << "Person constructor: " << name << endl;
    }
    void show() const { cout << "Name: " << name << endl; }
};

class Student : virtual public Person {
protected:
    string course;

public:
    Student(const string &n, const string &c) : Person(n), course(c) {
        cout << "Student constructor: " << course << endl;
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(const string &n, int id) : Person(n), empId(id) {
        cout << "Employee constructor: ID " << empId << endl;
    }
};

class TA : public Student, public Employee {
public:
    // The most derived class initializes the virtual base directly
    TA(const string &n, const string &c, int id)
        : Person(n), Student(n, c), Employee(n, id) {
        cout << "TA constructor" << endl;
    }

    void details() const {
        cout << "TA -> " << name << ", course: " << course
             << ", empId: " << empId << endl;
    }
};

int main() {
    TA t("Kiran", "Data Structures", 501);
    t.details();
    t.show();   // unambiguous: only one Person subobject
    return 0;
}