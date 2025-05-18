/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#ifndef REGISTRATIONMANAGER_H
#define REGISTRATIONMANAGER_H

#include "Workshop.h"
#include "ParticipantList.h"
#include "WorkshopList.h"

#include <string>
#include <vector>
#include <map>
#include <set>

class RegistrationManager
{
public:
    RegistrationManager(const WorkshopList& workshopList,
        ParticipantList& participantList);

    void addOpenWorkshop(int workshopNo);
    void registerParticipant(int workshopNo, int participantID);
    void unregisterParticipant(int workshopNo, int participantID);
    void closeWorkshop(int workshopNo);
    void reopenWorkshop(int workshopNo);

    bool isOpen(int workshopNo) const;
    const std::set<int>& getOpenWorkshops() const;

private:
    std::map<int, std::set<int>> registration;
    std::set<int> openWorkshops;
    const WorkshopList& workshopList;
    ParticipantList& participantList;
};

#endif