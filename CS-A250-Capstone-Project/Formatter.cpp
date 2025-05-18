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
    constexpr char STAR_LINE[]   = "*********************************************\n";
    constexpr char MENU_INDENT[] = "\t\t";
    constexpr int  PRICE_WIDTH   = 7;
}

void Formatter::displayMenu()
{
    cout << STAR_LINE;
    cout << MENU_INDENT << "WORKSHOP HUB\n";
    cout << STAR_LINE;
    cout << MENU_INDENT << "1. View all workshops\n";
    cout << MENU_INDENT << "2. View open workshops\n";
    cout << MENU_INDENT << "3. View workshops by price\n";
    cout << MENU_INDENT << "4. Register for a workshop\n";
    cout << MENU_INDENT << "5. List all your workshops\n";
    cout << MENU_INDENT << "6. Cancel registration\n";
    cout << MENU_INDENT << "7. Exit\n\n";
}

void Formatter::printAllWorkshops(const WorkshopList& workshopList)
{
    bool hasWorkshops = !workshopList.isEmpty();
    
    if (!hasWorkshops)
    {
        cout << "Workshop list is temporarily unavailable. Please try again later.\n\n";
    }
    else
    {
        cout << "\n" << MENU_INDENT << "ALL WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "-----------------------------\n";

        for (const auto& workshop : workshopList.getAllWorkshops())
        {
            printWorkshop(workshop);
        }
        cout << "\n";
    }
}

void Formatter::printOpenWorkshops(const WorkshopList& workshopList,
                                 const RegistrationManager& registration)
{
    const auto& openSet = registration.getOpenWorkshops();
    bool hasOpenWorkshops = !openSet.empty();

    if (!hasOpenWorkshops)
    {
        cout << "There are no open workshops.\n\n";
    }
    else
    {
        cout << "\n" << MENU_INDENT << "OPEN WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "--------------------------\n";

        for (int wsNo : openSet)
        {
            const auto& workshop = workshopList.getWorkshop(wsNo);
            printWorkshop(workshop);
        }
        cout << "\n";
    }
}

void Formatter::printWorkshopsByPrice(const WorkshopList& workshopList,
                                    double maxPrice)
{
    bool hasWorkshops = !workshopList.isEmpty();

    if (!hasWorkshops)
    {
        cout << "Workshop list is temporarily unavailable. Please try again later.\n\n";
    }
    else
    {
        cout << "\n" << MENU_INDENT << "WORKSHOPS BY PRICE\n";
        cout << MENU_INDENT << "(Workshop #) $Price Workshop Name\n";
        cout << MENU_INDENT << "---------------------------------\n";

        for (const auto& workshop : workshopList.getAllWorkshops())
        {
            if (workshop.getPrice() <= maxPrice)
            {
                cout << MENU_INDENT << "$" << fixed << setprecision(2)
                     << setw(PRICE_WIDTH) << workshop.getPrice() << " ";
                printWorkshop(workshop);
            }
        }
        cout << "\n";
    }
}

void Formatter::printParticipantWorkshops(const ParticipantList& participantList,
                                        int participantId)
{
    const auto& workshops = participantList.getWorkshops(participantId);
    bool hasWorkshops = !workshops.empty();

    if (!hasWorkshops)
    {
        cout << "You are not currently registered for any workshops.\n\n";
    }
    else
    {
        cout << "\n" << MENU_INDENT << "YOUR WORKSHOPS\n";
        cout << MENU_INDENT << "(Workshop #) Workshop Name\n";
        cout << MENU_INDENT << "--------------------------\n";

        for (const auto& workshop : workshops)
        {
            printWorkshop(workshop);
        }
        cout << "\n";
    }
}

void Formatter::printWorkshop(const Workshop& workshop)
{
    cout << MENU_INDENT << "(" << workshop.getNumber() << ") "
         << workshop.getTitle() << '\n';
}

void Formatter::pauseAndWait()
{
    cout << "\nPress 'Enter' to return to the menu...\n\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
