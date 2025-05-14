#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    cout << "Test program starting..." << endl;
    cout.flush();
    
    const string DATA_FILE = "Resource Files/workshop_database.txt";
    cout << "Attempting to open file: " << DATA_FILE << endl;
    cout.flush();
    
    ifstream inFile(DATA_FILE);
    if (!inFile.is_open()) {
        cerr << "Error: Could not open file " << DATA_FILE << endl;
        return 1;
    }
    
    cout << "File opened successfully" << endl;
    cout.flush();
    
    string line;
    int lineCount = 0;
    
    while (getline(inFile, line)) {
        lineCount++;
        cout << "Line " << lineCount << ": " << line << endl;
        cout.flush();
    }
    
    cout << "Total lines read: " << lineCount << endl;
    cout << "Test program completed successfully" << endl;
    
    return 0;
}
