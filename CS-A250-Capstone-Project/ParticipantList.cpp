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

#include <algorithm>

using namespace std;

void ParticipantList::addParticipant(const Participant& participant)
{
    participantList.insert(
        make_pair(participant, vector<Workshop>()));
}

void ParticipantList::addWorkshopToParticipant(
    const Participant& participant, const Workshop& workshop)
{
    participantList[participant].push_back(workshop);
}

int ParticipantList::getID(const Participant& participant) const
{
    return participant.getID();
}

string ParticipantList::getFirstName(int participantID) const
{
    return findByID(participantID)->first.getFirstName();
}

string ParticipantList::getLastName(int participantID) const
{
    return findByID(participantID)->first.getLastName();
}

vector<Workshop>
ParticipantList::getWorkshops(int participantID) const
{
    return findByID(participantID)->second;
}

const Participant&
ParticipantList::getParticipant(int participantID) const
{
    return findByID(participantID)->first;
}

void ParticipantList::cancelWorkshop(int participantID, int workshopNo)
{
    auto iterMap = find_if(participantList.begin(), participantList.end(),
        [participantID] (const pair<Participant,
            vector<Workshop>>& aPair)
        {
            return (aPair.first.getID() == participantID);
        });
    auto iterWorkshop = find(iterMap->second.begin(), iterMap->second.end(), workshopNo);

    iterMap->second.erase(iterWorkshop);
}

bool ParticipantList::isEmpty() const
{
    return participantList.empty();
}

void ParticipantList::clearList()
{
    participantList.clear();
}

map<Participant, vector<Workshop>>::const_iterator 
ParticipantList::findByID(int participantID) const
{
    return find_if(participantList.begin(), participantList.end(),
        [participantID] (const pair<Participant,
        vector<Workshop>>& aPair)
        { 
            return (aPair.first.getID() == participantID); 
        });
} 