// tracer_ok.cpp
#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "Tracer " << id << " created\n"; }
    ~Tracer()             { cout << "Tracer " << id << " destroyed\n"; }
};

int main() {
    for (int i = 1; i <= 3; i++) {
        Tracer *t = new Tracer(i);
        delete t;                    // paired with new
    }
    cout << "Loop finished\n";
    return 0;
}