/*
    Tech Wizards

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

const Workshop& WorkshopList::getWorkshop(int workshopNo) const
{
    return *(findByNumber(workshopNo));
}

const set<Workshop>& WorkshopList::getAllWorkshops() const
{
    return workshopList;
}

bool WorkshopList::isEmpty() const
{
    return workshopList.empty();
}

void WorkshopList::clearList()
{
    workshopList.clear();
}

set<Workshop>::iterator WorkshopList::findByNumber(int workshopNo) const
{
    return find_if(workshopList.begin(), workshopList.end(),
                    [workshopNo](const Workshop& current)
                    {
                        return (current.getNumber() == workshopNo);
                    });
}