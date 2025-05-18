/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "ParticipantList.h"
#include "Participant.h"
#include "Workshop.h"
#include "WorkshopList.h"
#include "DataLoader.h"
#include "RegistrationManager.h"
#include "Formatter.h"
#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Create an object of the ParticipantList and load the data by calling the function
    //    DataLoader::loadParticipants.
    ParticipantList participantList;
    DataLoader::loadParticipants(participantList, "participant_database.txt");

    //Create an object of the WorkshopList and load the data by calling 
    //    the function DataLoader::loadWorkshops.
    WorkshopList workshopList;
    DataLoader::loadWorkshops(workshopList, "workshop_database.txt");


    //Create an object of the RegistrationManager and load the data by calling 
    //    the function DataLoader::loadRegistration.
    RegistrationManager registrationManager(workshopList, participantList);
    DataLoader::loadRegistration(registrationManager, "registration_database.txt");

    //Call the function processMenu.
    processMenu(workshopList, participantList, registrationManager);

    //IMPORTANT: To make the app work as a standalone executable file, 
    //make sure you include at the end of the main() function the following :

    cout << endl << endl;
    system("Pause");
    return 0;
}