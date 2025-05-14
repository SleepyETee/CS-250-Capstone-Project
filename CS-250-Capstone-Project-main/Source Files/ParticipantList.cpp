/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "../Header Files/ParticipantList.h"

#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;

void ParticipantList::addParticipant(const Participant& participant)
{
    participantList[participant] = std::vector<Workshop>();
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
    auto iter = findByID(participantID);
    if (iter != participantList.end())
    {
        return iter->first.getFirstName();
    }
    // Option 1: Return a default value
    return "Unknown"; 
    // Option 2: Or throw an exception (you'd need to include <stdexcept>)
    // throw std::runtime_error("Participant ID not found: " + std::to_string(participantID));
}

std::string ParticipantList::getLastName(int participantID) const
{
    auto iter = findByID(participantID);
    if (iter != participantList.end())
    {
        return iter->first.getLastName();
    }
    return "Participant"; // Default value
    // Or throw std::runtime_error("Participant ID not found: " + std::to_string(participantID));
}

std::vector<Workshop> ParticipantList::getWorkshops(int participantID) const
{
    auto iter = findByID(participantID);
    if (iter != participantList.end())
    {
        return iter->second;
    }
    return {}; // Return an empty vector
    // Or throw std::runtime_error("Participant ID not found: " + std::to_string(participantID));
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
ParticipantList::findByID(int participantID) const
{
    auto iter = find_if(participantList.begin(), participantList.end(), 
        [participantID](const std::pair<Participant, std::vector<Workshop>>& aPair) 
        { 
            return aPair.first.getID() == participantID; 
        });
    
    // Check if participant was found
    if (iter == participantList.end()) {
        cerr << "Error: Participant with ID #" << participantID << " not found!" << endl;
    }
    
    return iter;
}
