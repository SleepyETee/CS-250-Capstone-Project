/*
    Team name

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "WorkshopList.h"

#include <algorithm>

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
    return findByNumber(workshopNo)->getTitle();
}

int WorkshopList::getHours(int workshopNo) const
{
    return findByNumber(workshopNo)->getHours();
}

int WorkshopList::getCapacity(int workshopNo) const
{
    return findByNumber(workshopNo)->getCapacity();
}

double WorkshopList::getPrice(int workshopNo) const
{
    return findByNumber(workshopNo)->getPrice();
}

set<Workshop>::const_iterator WorkshopList::findByNumber(int workshopNo) const
{
    return find_if(workshopList.begin(), workshopList.end(),
                    [workshopNo](const Workshop& current)
                    {
                        return current.getNumber() == workshopNo;
                    });
}