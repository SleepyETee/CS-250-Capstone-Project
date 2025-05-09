/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "ParticipantList.h"

#include <algorithm>

using namespace std;

void ParticipantList::addParticipant(const Participant& participant)
{
    participantList.insert(make_pair(participant, vector<Workshop>()));
}

void ParticipantList::addWorkshopToParticipant(const Participant& participant, const Workshop& workshop)
{
    participantList[participant].push_back(workshop);
}

int ParticipantList::getID(const Participant& participant) const
{
    return participant.getID();
}

std::string ParticipantList::getFirstName(int participantID) const
{
    auto iterToParticipant = findByID(participantID);
    return iterToParticipant->first.getLastName();
}

std::string ParticipantList::getLastName(int participantID) const
{
    auto iterToParticipant = findByID(participantID);
    return iterToParticipant->first.getLastName();
}

std::vector<Workshop> ParticipantList::getWorkshops(int participantID) const
{
    auto iterToParticipant = findByID(participantID);
    return iterToParticipant->second;
}

bool ParticipantList::isEmpty() const
{
    return participantList.empty();
}

void ParticipantList::clearList()
{
    participantList.clear();
}

std::map<Participant, std::vector<Workshop>>::const_iterator 
ParticipantList:: findByID(int participantID) const
{
    // todo
} 
