/*
    Team name

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#ifndef WORKSHOPLIST_H
#define WORKSHOPLIST_H

#include "Workshop.h"

#include <set>

class WorkshopList {
public:
    void addWorkshop(const Workshop& workshop);

    int getNumber(const Workshop& workshop) const;
    std::string getTitle(int workshopNo) const;
    int getHours(int workshopNo) const;
    int getCapacity(int workshopNo) const;
    double getPrice(int workshopNo) const;

    bool isEmpty() const;
    void clearList();

private:
    std::set<Workshop> workshopList;
    std::set<Workshop>::const_iterator
        findByNumber(int workshopNo) const;
};

#endif
