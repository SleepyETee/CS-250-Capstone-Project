/*
Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

void processMenu(WorkshopList& workshopList,
                 ParticipantList& participantList,
                 RegistrationManager& registration)
{

}

void getIdentification(int& participantID,
                       std::string& firstName,
                       std::string& lastName)
{
    cout << "Enter your ID: ";
    cin >> participantID;
    cout << "\nEnter your first Name: ";
    cin >> firstName;
    cout << "\nEnter your last Name: ";
    cin >> lastName;
}

bool verifyIdentification(const ParticipantList& participantList,
                          int participantID,
                          const std::string& firstName,
                          const std::string& lastName)
{
    return false;
}

void viewAllWorkshops(const WorkshopList& workshopList)
{

}

void viewOpenWorkshops(const WorkshopList& workshopList,
                       const RegistrationManager& registration)
{

}

void viewWorkshopsByPrice(const WorkshopList& workshopList)
{

}

void viewParticipantWorkshops(const ParticipantList& participantList)
{

}

void registerForWorkshop(WorkshopList& workshopList,
                        ParticipantList& participantList,
                        RegistrationManager& registration)
{

}

void cancelWorkshop(WorkshopList& workshopList,
                    ParticipantList& participantList,
                    RegistrationManager& registration)
{

}