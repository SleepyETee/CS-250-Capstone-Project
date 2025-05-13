/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "DataLoader.h"
#include "WorkshopList.h"

#include <fstream>
#include <sstream>

using namespace std;

namespace
{
    constexpr char PIPE_DELIM = '|';
}

void DataLoader::loadWorkshops(WorkshopList& workshopList,
    const string& fileName)
{
    ifstream inFile(fileName);

    string rawLine;
    while (getline(inFile, rawLine))
    {
        istringstream lineStream(rawLine);

        string numberTok;
        string titleTok;
        string hoursTok;
        string capacityTok;
        string priceTok;

        getline(lineStream, numberTok, PIPE_DELIM);
        getline(lineStream, titleTok, PIPE_DELIM);
        getline(lineStream, hoursTok, PIPE_DELIM);
        getline(lineStream, capacityTok, PIPE_DELIM);
        getline(lineStream, priceTok, PIPE_DELIM);

        int    workshopNumber = stoi(numberTok);
        int    workshopHours = stoi(hoursTok);
        int    maxCapacity = stoi(capacityTok);
        double workshopPrice = stod(priceTok);

        Workshop newWorkshop(workshopNumber, titleTok,
            workshopHours, maxCapacity, workshopPrice);

        workshopList.addWorkshop(newWorkshop);
    }
}

