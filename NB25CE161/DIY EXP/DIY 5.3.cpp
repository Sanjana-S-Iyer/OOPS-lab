#include <iostream>
#include <string>
using namespace std;

class Order {
    int id;
    string item;
    static int nextId;   // shared by all Orders

public:
    Order(const string &itemName) : id(nextId++), item(itemName) {}

    void show() const {
        cout << "Order #" << id << ": " << item << endl;
    }

    int getId() const { return id; }
};

int Order::nextId = 1001;   // first ID handed out

int main() {
    Order o1("Laptop");
    Order o2("Phone");
    Order o3("Headphones");

    o1.show();
    o2.show();
    o3.show();

    {
        Order o4("Keyboard");
        o4.show();
    }

    Order o5("Monitor");
    o5.show();   // IDs are never reused
    return 0;
}