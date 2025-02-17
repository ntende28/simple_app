#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

int countLines(const string& filename) {
    ifstream file(filename);
    int lines = 0;
    string temp;
    
    while (getline(file, temp)) {
        lines++;
    }

    return lines;
}

void watchCSV(const string& filename) {
    int lastLineCount = countLines(filename);

    while (true) {
        this_thread::sleep_for(chrono::seconds(2));  // Check every 2 seconds

        int currentLineCount = countLines(filename);
        if (currentLineCount > lastLineCount) {
            ifstream file(filename);
            string line;
            int lineNumber = 0;

            while (getline(file, line)) {
                if (lineNumber >= lastLineCount) {  // Print only new lines
                    cout << "New Entry: " << line << endl;
                }
                lineNumber++;
            }

            lastLineCount = currentLineCount;
        }
    }
}

int main() {
    string filename = "data.csv";
    cout << "Watching " << filename << " for new entries..." << endl;

    thread watcher(watchCSV, filename);  
    watcher.join();  // Run the watcher function in a separate thread

    return 0;
}
