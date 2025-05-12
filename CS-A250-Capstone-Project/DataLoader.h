/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef DATALOADER_H
#define DATALOADER_H

#include "WorkshopList.h"

#include <string>

class DataLoader
{
public:
    static void loadWorkshops(WorkshopList& workshopList,
        const std::string& filename);
};

#endif
