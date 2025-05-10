/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anatasia 
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef DATALOADER_H
#define DATALOADER_H
#include <string>
class WorkshopList;
class DataLoader
{
public:
    static void loadWorkshops(WorkshopList& workshopList, const std::string& filename);
};

#endif
