#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logger {
public:
    virtual ~Logger() {}
    virtual void write(const string &msg) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE] " << msg << endl;
    }
};

class FileLogger : public Logger {
    ofstream file;

public:
    FileLogger(const string &filename) : file(filename, ios::app) {}
    ~FileLogger() { file.close(); }

    void write(const string &msg) override {
        file << "[FILE] " << msg << endl;
    }
};

void runApp(Logger &log) {
    log.write("Application started");
    log.write("Processing data");
    log.write("Application finished");
}

int main() {
    ConsoleLogger console;
    FileLogger fileLog("app.log");

    Logger *current = &console;
    cout << "--- Using console logger ---\n";
    runApp(*current);

    current = &fileLog;                 // switch at run time
    cout << "--- Switched to file logger ---\n";
    runApp(*current);
    cout << "(messages written to app.log)\n";

    current = &console;                 // switch back
    current->write("Back on console");

    fileLog.write("Closing log");
    return 0;
}