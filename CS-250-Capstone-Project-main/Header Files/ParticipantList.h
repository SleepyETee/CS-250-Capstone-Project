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
#include <stdexcept>

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

    const Participant& getParticipant(int participantID) const;
    void cancelWorkshop(int participantID, int workshopNo);
    
    bool isEmpty() const;
    void clearList();

private:
    std::map<Participant, std::vector<Workshop>> participantList;
<<<<<<<< Updated upstream:CS-A250-Capstone-Project/ParticipantList.h
    std::map<Participant, std::vector<Workshop>>::const_iterator
========
    std::map<Participant, std::vector<Workshop>>::const_iterator 
<<<<<<< Updated upstream:CS-250-Capstone-Project-main/CS-250-Capstone-Project-main/Header Files/ParticipantList.h
>>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/ParticipantList.h
        findByID(int participantID) const; 
=======
        findByID(int participantID) const;
        
    // Helper method to check if iterator is valid and throw exception if not
    void checkIterator(std::map<Participant, std::vector<Workshop>>::const_iterator iter, int participantID) const {
        if (iter == participantList.end()) {
            throw std::runtime_error("Participant with ID #" + std::to_string(participantID) + " not found");
        }
    }
>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/ParticipantList.h
};

#endif
