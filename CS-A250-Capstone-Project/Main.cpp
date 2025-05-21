/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "DataLoader.h"
#include "Interface.h"
#include "Formatter.h"

#include <iostream>

using namespace std;

int main()
{
    ParticipantList participantList;
    DataLoader::loadParticipants(participantList,
        "participant_database.txt");

    WorkshopList workshopList;
    DataLoader::loadWorkshops(workshopList,
        "workshop_database.txt");

    RegistrationManager registrationManager(workshopList, 
        participantList);
    DataLoader::loadRegistration(registrationManager,
        "registration_database.txt");

    processMenu(workshopList, participantList, registrationManager);

    cout << endl << endl;
    system("Pause");
    return 0;
}