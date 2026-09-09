#include <iostream>
using namespace std;
class Widget {
   int id;
   static int count; // shared by all objects
public:
   Widget() {
       id = ++count;
       cout << "Created W" << id << endl;
   }
   ~Widget() {
       --count;
       cout << "Destroyed W" << id << endl;
   }
   static int alive() { return count; } // no this
};
int Widget::count = 0; // definition
int main() {
   Widget a, b;
   cout << "Alive = " << Widget::alive() << endl;
   {
       Widget c;
   }
}