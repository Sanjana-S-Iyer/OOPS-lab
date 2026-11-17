#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");

    if (!in || !out) {
        cerr << "Error: cannot open files" << endl;
        return 1;
    }

    string line;
    int n = 1;
    while (getline(in, line)) {
        out << n << ": " << line << '\n';
        n++;
    }

    cout << "Copied " << (n - 1) << " lines to out.txt" << endl;
    return 0;
}