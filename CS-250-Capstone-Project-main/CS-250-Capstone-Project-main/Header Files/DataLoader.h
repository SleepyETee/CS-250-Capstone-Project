/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anatasia 
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef DATALOADER_H
#define DATALOADER_H
#include "WorkshopList.h"

class DataLoader
{
public:
    DataLoader(const std::string& fileName);
    void loadWorkshops(WorkshopList& workshopList);
    void loadParticipants(ParticipantList& participantList);
    void loadWorkshopParticipants(ParticipantList& participantList, WorkshopList& workshopList);
    void loadWorkshopParticipants(ParticipantList& participantList, WorkshopList& workshopList, const std::string& fileName);
    void loadWorkshopParticipants(ParticipantList& participantList, WorkshopList& workshopList, const std::string& fileName, const std::string& workshopFileName);
};  

#endif
