/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H

#include "Workshop.h"
#include "Participant.h"

#include <string>
#include <vector>
#include <map>

class ParticipantList
{
public:
    void addParticipant(const Participant& participant);
    void addWorkshopToParticipant(const Participant& participant,
        const Workshop& workshop);
    
    int getID(const Participant& participant) const;
    std::string getFirstName(int participantID) const;
    std::string getLastName(int participantID) const;
    std::vector<Workshop> getWorkshops(int participantID) const;
    
    bool isEmpty() const;
    void clearList();

private:
    std::map<Participant, std::vector<Workshop>> participantList;
    std::map<Participant, std::vector<Workshop>>::const_iterator
        findByID(int participantID) const; 
};

#endif