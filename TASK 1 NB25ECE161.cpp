#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

    static int count;

public:

    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = m;
        count++;
    }

    void display()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }

    void display(string msg)
    {
        cout << "\n" << msg;
        display();
    }

    static void showCount()
    {
        cout << "\nTotal Number of Students: " << count << endl;
    }

    friend void showDetails(Student s);

    bool operator>(Student s)
    {    
        return marks > s.marks;
    }
};

int Student::count = 0;

void showDetails(Student s)
{
    cout << "\nFriend Function Accessing Private Data";
    cout << "\nStudent Name: " << s.name;
    cout << "\nStudent Marks: " << s.marks << endl;
}

int main()
{
    int r1, r2;
    string n1, n2;
    float m1, m2;

    cout << "Enter First Student Details\n";

    cout << "Roll Number: ";
    cin >> r1;

    cout << "Name: ";
    cin >> n1;

    cout << "Marks: ";
    cin >> m1;

    cout << "\nEnter Second Student Details\n";

    cout << "Roll Number: ";
    cin >> r2;

    cout << "Name: ";
    cin >> n2;

    cout << "Marks: ";
    cin >> m2;

    Student s1(r1, n1, m1);
    Student s2(r2, n2, m2);

    cout << "\n===== STUDENT DETAILS =====";

    s1.display();
    s2.display("Second Student Details:");

    showDetails(s1);

   Student::showCount();

    cout << "\n===== MARKS COMPARISON =====\n";

    if (s1 > s2)
        cout << n1 << " scored higher marks than " << n2;
    else if (s2 > s1)
        cout << n2 << " scored higher marks than " << n1;
    else
        cout << "Both students scored equal marks.";

    return 0;
}
