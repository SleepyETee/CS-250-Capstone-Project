/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anatasia 
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/
#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

DataLoader::loadWorkshops(WorkshopList& workshopList, const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    std::string line;   
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name, date, time, duration;
        if (!(iss >> name >> date >> time >> duration)) { break; } // error
        Workshop workshop(name, date, time, duration);
        workshopList.addWorkshop(workshop);
    }
    file.close();   
    std::cout << "Workshops loaded successfully from " << filename << std::endl;
    std::cout << "Total workshops loaded: " << workshopList.getWorkshopCount() << std::endl;
    std::cout << "Workshop list:" << std::endl;
    workshopList.displayWorkshops();
}
