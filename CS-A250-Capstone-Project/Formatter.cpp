/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "Formatter.h"
#include <iostream>

using namespace std;

void Formatter::displayMenu()
{
    cout << "WORKSHOP HUB" << endl;
    cout << "1. View all workshops" << endl;
    cout << "2. View open workshops" << endl;
    cout << "3. View workshops by price" << endl;
    cout << "4. Register for a workshop" << endl;
    cout << "5. List all your workshops" << endl;
    cout << "6. Cancel registration" << endl;
    cout << "7. Exit" << endl;
}

void Formatter::printAllWorkshops(WorkshopList& workshopList)
{
    cout << "All Workshops" << endl;
}
