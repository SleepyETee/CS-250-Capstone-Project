/*
    Team name

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "../Header Files/WorkshopList.h"

#include <algorithm>
#include <iostream>

using namespace std;

void WorkshopList::addWorkshop(const Workshop& workshop)
{
    workshopList.insert(workshop);
}

void WorkshopList::clearList()
{
    workshopList.clear();
}

bool WorkshopList::isEmpty() const
{
    return workshopList.empty();
}

int WorkshopList::getNumber(const Workshop& workshop) const
{
    return workshop.getNumber();
}

string WorkshopList::getTitle(int workshopNo) const
{
    auto iter = findByNumber(workshopNo);
    if (iter != workshopList.end())
    {
        return iter->getTitle();
    }
    return "Unknown Title"; // Default value
    // Or throw std::runtime_error("Workshop number not found: " + std::to_string(workshopNo));
}

int WorkshopList::getHours(int workshopNo) const
{
    auto iter = findByNumber(workshopNo);
    if (iter != workshopList.end())
    {
        return iter->getHours();
    }
    return 0; // Default value
    // Or throw std::runtime_error("Workshop number not found: " + std::to_string(workshopNo));
}

int WorkshopList::getCapacity(int workshopNo) const
{
    auto iter = findByNumber(workshopNo);
    if (iter != workshopList.end())
    {
        return iter->getCapacity();
    }
    return 0; // Default value
    // Or throw std::runtime_error("Workshop number not found: " + std::to_string(workshopNo));
}

double WorkshopList::getPrice(int workshopNo) const
{
    auto iter = findByNumber(workshopNo);
    if (iter != workshopList.end())
    {
        return iter->getPrice();
    }
    return 0.0; // Default value
    // Or throw std::runtime_error("Workshop number not found: " + std::to_string(workshopNo));
}

set<Workshop>::const_iterator WorkshopList::findByNumber(int workshopNo) const
{
    auto iter = find_if(workshopList.begin(), workshopList.end(),
                    [workshopNo](const Workshop& current)
                    {
                        return current.getNumber() == workshopNo;
                    });
    
    // Check if workshop was found
    if (iter == workshopList.end()) {
        cerr << "Error: Workshop #" << workshopNo << " not found!" << endl;
    }
    
    return iter;
}
