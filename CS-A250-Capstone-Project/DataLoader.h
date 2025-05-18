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

#include "WorkshopList.h"
#include "RegistrationManager.h"
#include "ParticipantList.h"

#include <string>

class DataLoader
{
public:
    static void loadWorkshops(WorkshopList& workshopList,
        const std::string& filename);
    static void loadParticipants(ParticipantList& participantList,
        const std::string& filename);
    static void loadRegistration(RegistrationManager& registrationManager,
        const std::string& filename);
};

#endif
