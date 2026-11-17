#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main() {
    unordered_map<string, int> freq;
    string word;

    cout << "Enter text (Ctrl+D on Linux/Mac, Ctrl+Z then Enter on Windows to finish):\n";
    while (cin >> word) {
        // normalize: lowercase, strip punctuation
        string clean;
        for (char c : word)
            if (isalnum(static_cast<unsigned char>(c)))
                clean += tolower(static_cast<unsigned char>(c));
        if (!clean.empty())
            freq[clean]++;
    }

    cout << "\nWord counts:\n";
    for (const auto &p : freq)
        cout << p.first << ": " << p.second << endl;

    string bestWord;
    int bestCount = 0;
    for (const auto &p : freq) {
        if (p.second > bestCount ||
            (p.second == bestCount && p.first < bestWord)) {   // tie-break alphabetically
            bestWord = p.first;
            bestCount = p.second;
        }
    }

    if (bestCount > 0)
        cout << "\nMost frequent word: \"" << bestWord
             << "\" (" << bestCount << " times)" << endl;
    return 0;
}