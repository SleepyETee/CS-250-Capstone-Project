/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/
#include "../Header Files/DataLoader.h"
#include "../Header Files/WorkshopList.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


namespace          // internal helper constant
{
    constexpr char PIPE_DELIM = '|';
}

void DataLoader::loadWorkshops(WorkshopList& workshopList,
                               const string& fileName)
{
    cout << "DataLoader::loadWorkshops - Starting to load workshops from " << fileName << endl;
    cout.flush();
    
    ifstream inFile(fileName);
    bool fileOpened = inFile.is_open();       // boolean flag instead of early‑return

    if (!fileOpened)
    {
        cerr << "Unable to open " << fileName << '\n';
        cerr.flush();
    }
    else
    {
        cout << "File opened successfully" << endl;
        cout.flush();
        
        string rawLine;
        int lineCount = 0;
        
        cout << "Starting to read lines from file" << endl;
        cout.flush();
        
        while (getline(inFile, rawLine))
        {
            lineCount++;
            cout << "Reading line " << lineCount << ": " << rawLine << endl;
            cout.flush();
            
            istringstream lineStream(rawLine);

            string numberTok;
            string titleTok;
            string hoursTok;
            string capacityTok;
            string priceTok;

            cout << "Parsing line " << lineCount << endl;
            cout.flush();
            
            bool wellFormed =
                getline(lineStream, numberTok,   PIPE_DELIM) &&
                getline(lineStream, titleTok,    PIPE_DELIM) &&
                getline(lineStream, hoursTok,    PIPE_DELIM) &&
                getline(lineStream, capacityTok, PIPE_DELIM) &&
                getline(lineStream, priceTok,    PIPE_DELIM);

            if (!wellFormed)
            {
                cerr << "Skipped malformed record: " << rawLine << '\n';
                cerr.flush();
            }
            else
            {
                cout << "Line " << lineCount << " is well-formed. Converting tokens to values..." << endl;
                cout.flush();
                
                try {
                    cout << "Converting numberTok: " << numberTok << endl;
                    cout.flush();
                    int workshopNumber = stoi(numberTok);
                    
                    cout << "Converting hoursTok: " << hoursTok << endl;
                    cout.flush();
                    int workshopHours = stoi(hoursTok);
                    
                    cout << "Converting capacityTok: " << capacityTok << endl;
                    cout.flush();
                    int maxCapacity = stoi(capacityTok);
                    
                    cout << "Converting priceTok: " << priceTok << endl;
                    cout.flush();
                    double workshopPrice = stod(priceTok);

                    cout << "Creating new workshop object" << endl;
                    cout.flush();
                    Workshop newWorkshop(workshopNumber, titleTok,
                                        workshopHours, maxCapacity, workshopPrice);

                    cout << "Adding workshop to list" << endl;
                    cout.flush();
                    workshopList.addWorkshop(newWorkshop);
                    
                    cout << "Workshop added successfully" << endl;
                    cout.flush();
                } catch (const exception& e) {
                    cerr << "Exception while processing line " << lineCount << ": " << e.what() << endl;
                    cerr.flush();
                }
            }
        }
        
        cout << "Finished reading file. Total lines processed: " << lineCount << endl;
        cout.flush();
    }
    
    cout << "DataLoader::loadWorkshops - Completed" << endl;
    cout.flush();
}
