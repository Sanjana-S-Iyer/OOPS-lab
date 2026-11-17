#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
    string name;
    int marks;

public:
    Student() : name(""), marks(0) {}
    Student(const string &n, int m) : name(n), marks(m) {}

    string getName() const { return name; }
    int getMarks() const   { return marks; }

    void print() const {
        cout << name << " - " << marks << endl;
    }
};

int main() {
    // Step 1: store name, marks pairs (one per line)
    {
        ofstream out("students.txt");
        out << "Asha 78\n";
        out << "Ravi 91\n";
        out << "Meera 85\n";
        out << "Kiran 67\n";
    }

    // Step 2: read them back into an array of Student objects
    ifstream in("students.txt");
    if (!in) {
        cerr << "Error: cannot open students.txt" << endl;
        return 1;
    }

    const int MAX = 100;
    Student students[MAX];
    int n = 0;

    string name;
    int marks;
    while (n < MAX && in >> name >> marks) {
        students[n++] = Student(name, marks);
    }

    cout << "Records read: " << n << endl;
    for (int i = 0; i < n; i++)
        students[i].print();

    // Step 3: find the topper
    if (n > 0) {
        int best = 0;
        for (int i = 1; i < n; i++)
            if (students[i].getMarks() > students[best].getMarks())
                best = i;

        cout << "Topper: " << students[best].getName()
             << " with " << students[best].getMarks() << " marks" << endl;
    }
    return 0;
}