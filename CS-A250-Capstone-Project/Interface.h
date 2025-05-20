/*
Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

void processMenu(WorkshopList& workshopList,
                 ParticipantList& participantList,
                 RegistrationManager& registration);

void getIdentification(int& participantID,
                       std::string& firstName,
                       std::string& lastName);

bool verifyIdentification(const ParticipantList& participantList,
                          int participantID,
                          const std::string& firstName,
                          const std::string& lastName);

void viewAllWorkshops(const WorkshopList& workshopList);

void viewOpenWorkshops(const WorkshopList& workshopList,
                       const RegistrationManager& registration);

void viewWorkshopsByPrice(const WorkshopList& workshopList);

void viewParticipantWorkshops(
    const ParticipantList& participantList);

void registerForWorkshop(WorkshopList& workshopList,
                        ParticipantList& participantList,
                        RegistrationManager& registration);

void cancelRegistration(WorkshopList& workshopList,
                    ParticipantList& participantList,
                    RegistrationManager& registration);

#endif
