#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    stringstream ss(s);
    string word;
    vector<string> words;

    while (ss >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); i++) {
        cout << words[i];
        if (i + 1 < words.size()) cout << " ";
    }
    cout << endl;
    return 0;
}