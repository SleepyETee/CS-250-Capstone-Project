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
#include "Workshop.h"
#include "Participant.h"
#include "RegistrationManager.h"
#include "WorkshopList.h"
#include "ParticipantList.h"

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

using namespace std;

namespace
{
    constexpr char STAR_LINE[] = 
        "*********************************************\n";
    constexpr char MENU_INDENT[] = "\t";
    constexpr int  PRICE_WIDTH = 6;
}

void Formatter::displayMenu()
{
    cout << STAR_LINE;
    cout << MENU_INDENT << MENU_INDENT << "WORKSHOP HUB\n";
    cout << STAR_LINE;
    cout << MENU_INDENT << "1. View all workshops\n";
    cout << MENU_INDENT << "2. View open workshops\n";
    cout << MENU_INDENT << "3. View workshops by price\n";
    cout << MENU_INDENT << "4. Register for a workshop\n";
    cout << MENU_INDENT << "5. List all your workshops\n";
    cout << MENU_INDENT << "6. Cancel registration\n";
    cout << MENU_INDENT << "7. Exit\n";
}

void Formatter::printAllWorkshops(const WorkshopList& workshopList)
{    
    if (workshopList.isEmpty())
    {
        cout << "Workshop list is temporarily unavailable."
             << "Please try again later.\n\n";
    }
    else
    {
        cout << MENU_INDENT << "ALL WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "-----------------------------\n";

        for(const Workshop& workshop : 
            workshopList.getAllWorkshops())
        {
            cout << MENU_INDENT << "(" << workshop.getNumber() 
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
        cerr << "There are no open workshops.\n\n";
    }
    else
    {
        cout << MENU_INDENT << "OPEN WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "--------------------------\n";

        for(int workshopNo : openSet)
        {
            const Workshop& workshop =
                workshopList.getWorkshop(workshopNo);
            cout << MENU_INDENT << "(" << workshop.getNumber()
                << ") " << workshop.getTitle() << '\n';
        }
    }
}

void Formatter::printWorkshopsByPrice(
    const WorkshopList& workshopList, double price)
{
    if (workshopList.isEmpty())
    {
        cout << "Workshop list is temporarily unavailable."
             << "Please try again later.\n\n";
    }
    else
    {
        cout << "\n" << MENU_INDENT << "WORKSHOPS BY PRICE\n";
        cout << MENU_INDENT << "(Workshop #) $Price Workshop Name\n";
        cout << MENU_INDENT << "---------------------------------\n";

        for(const Workshop& workshop :
            workshopList.getAllWorkshops())
        {
            if (workshop.getPrice() <= price)
            {
                cout << MENU_INDENT << "$" << fixed 
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
        cerr << "You are not currently registered for "
             << "any workshops.\n";
    }
    else
    {
        cout << MENU_INDENT << "YOUR WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "--------------------------\n";

        for (const Workshop& workshop : workshops)
        {
            cout << MENU_INDENT << "(" << workshop.getNumber()
                << ") " << workshop.getTitle() << '\n';
        }
    }
}

void Formatter::printWorkshop(const Workshop& workshop)
{
    cout << MENU_INDENT << workshop.getTitle() << '\n'
        << MENU_INDENT << "Number: " << workshop.getNumber() << '\n'
        << MENU_INDENT << "Hours: " << workshop.getHours() << '\n'
        << MENU_INDENT << "Price: $" << fixed << setprecision(2)
        << workshop.getPrice() << '\n';
}

void Formatter::pauseAndWait()
{
    cout << "\nPress 'Enter' to return to the menu...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
