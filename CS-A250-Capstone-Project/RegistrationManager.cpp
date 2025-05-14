/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "RegistrationManager.h"

#include <algorithm>

using namespace std;

void RegistrationManager::addOpenWorkshop(int workshopNo)
{
    openWorkshops.insert(workshopNo);
    registration.insert(make_pair(workshopNo, set<int>()));
}

void RegistrationManager::registerParticipant(int workshopNo, int participantID)
{
    registration.find(workshopNo)->second.insert(participantID);

    Workshop workshop = workshopList.getWorkshop(workshopNo);
    participantList.addWorkshopToParticipant(
        participantList.getParticipant(participantID),
        workshop
    );

    if (workshop.getCapacity() == workshop.getNumber())
    {
        closeWorkshop(workshopNo);
    }
}

void RegistrationManager::unregisterParticipant(int workshopNo, int participantID)
{
    registration[workshopNo].erase(participantID);
    Workshop workshop = workshopList.getWorkshop(workshopNo);
    if (workshop.getCapacity() > workshop.getNumber())
    {
        reopenWorkshop(workshopNo);
    }
    participantList.cancelWorkshop(participantID, workshopNo);
}

void RegistrationManager::closeWorkshop(int workshopNo)
{
    openWorkshops.erase(workshopNo);
}

void RegistrationManager::reopenWorkshop(int workshopNo)
{
    openWorkshops.insert(workshopNo);
}

bool RegistrationManager::isOpen(int workshopNo) const
{
    return (openWorkshops.find(workshopNo) != openWorkshops.end());
}

const std::set<int>& RegistrationManager::getOpenWorkshops() const
{
    return openWorkshops;
}