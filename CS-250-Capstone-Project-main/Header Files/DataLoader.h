/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef DATALOADER_H
#define DATALOADER_H
<<<<<<<< Updated upstream:CS-A250-Capstone-Project/DataLoader.h

#include "WorkshopList.h"

#include <string>

class DataLoader
{
public:
    static void loadWorkshops(WorkshopList& workshopList,
        const std::string& filename);
========
#include <string>
class WorkshopList;
class DataLoader
{
public:
    static void loadWorkshops(WorkshopList& workshopList, const std::string& filename);
>>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/DataLoader.h
};

#endif
