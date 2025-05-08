/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anatasia 
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Workshop.h"

class Participant
{
public:

    void addParticipant(const Participant& participant);
    void addWorkshopToParticipant(const Participant& participant, const Workshop& workshop);
    
    
    int getID(const Participant& participant) const;
    std::string getFirstName(int participantID) const;
    std::string getLastName(int participantID) const;
    std::vector<Workshop> getWorkshops(int participantID) const;
    
    bool isEmpty() const;
    void clearList();

    std::map<Participant, std::vector<Workshop>>::const_iterator 
        findByID(int participantID) const; 

private:
    std::map<Participant, std::vector<Workshop>> participantList;
};

#endif