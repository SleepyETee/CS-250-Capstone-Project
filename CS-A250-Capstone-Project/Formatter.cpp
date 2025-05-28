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
#include <string>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

void Formatter::displayMenu()
{
    cout << "*********************************************\n"
         << "\t\tWORKSHOP HUB\n"
         << "*********************************************\n"
         << "\t1. View all workshops\n"
         << "\t2. View open workshops\n"
         << "\t3. View workshops by price\n"
         << "\t4. Register for a workshop\n"
         << "\t5. List all your workshops\n"
         << "\t6. Cancel registration\n"
         << "\t7. Exit\n";
}

void Formatter::printAllWorkshops(const WorkshopList& workshopList)
{    
    const set<Workshop>& allWorkshops = workshopList.getAllWorkshops();

    if (allWorkshops.empty())
    {
        cerr << "Workshop list is temporarily unavailable. "
             << "Please try again later.\n";
    }
    else
    {
        cout << "\tALL WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t-----------------------------\n";

        for(const Workshop& workshop : allWorkshops)
        {
            cout << "\t(" << workshop.getNumber() 
                 << ") " << workshop.getTitle() << '\n';
        }
    }
}

void Formatter::printOpenWorkshops(const WorkshopList& workshopList,
    const RegistrationManager& registration)
{
    const set<int>& openSet = registration.getOpenWorkshops();

    if (openSet.empty())
    {
        cerr << "There are no open workshops.\n";
    }
    else
    {
        cout << "\tOPEN WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t--------------------------\n";

        for(int workshopNo : openSet)
        {
            const Workshop& workshop =
                workshopList.getWorkshop(workshopNo);
            cout << "\t(" << workshop.getNumber()
                << ") " << workshop.getTitle() << '\n';
        }
    }
}

void Formatter::printWorkshopsByPrice(
    const WorkshopList& workshopList, double price)
{
    const set<Workshop>& allWorkshops = workshopList.getAllWorkshops();

    if (allWorkshops.empty())
    {
        cerr << "Workshop list is temporarily unavailable. "
             << "Please try again later.\n";
    }
    else
    {
        cout << "\n\tWORKSHOPS BY PRICE\n"
             << "\t(Workshop #) $Price Workshop Name\n"
             << "\t---------------------------------\n";

        for(const Workshop& workshop : allWorkshops)
        {
            if (workshop.getPrice() <= price)
            {
                cout << "\t$" << fixed 
                    << setprecision(2) << workshop.getPrice()
                    << " (" << workshop.getNumber()
                    << ") " << workshop.getTitle() << '\n';
            }
        }
    }
}

void Formatter::printParticipantWorkshops(
    const ParticipantList& participantList, int participantID)
{
    const vector<Workshop>& workshops =
        participantList.getWorkshops(participantID);

    if (workshops.empty())
    {
        cout << "You are not currently registered for "
             << "any workshops.\n";
    }
    else
    {
        cout << "\tYOUR WORKSHOPS\n"
             << "\t(Workshop #) Workshop Name\n"
             << "\t--------------------------\n";

        for (const Workshop& workshop : workshops)
        {
            cout << "\t(" << workshop.getNumber()
                << ") " << workshop.getTitle() << '\n';
        }
    }
}

void Formatter::printWorkshop(const Workshop& workshop)
{
    cout << "\t" << workshop.getTitle() << '\n'
        << "\tNumber: " << workshop.getNumber() << '\n'
        << "\tHours: " << workshop.getHours() << '\n'
        << "\tPrice: $" << fixed << setprecision(2)
        << workshop.getPrice() << '\n';
}

void Formatter::pauseAndWait()
{
    cout << "\nPress 'Enter' to return to the menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    cout << endl;
}
