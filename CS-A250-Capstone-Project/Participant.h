/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>

class Participant
{
public:
    Participant(int id, const std::string& theFirstName,
        const std::string& theLastName)
        : id(id), firstName(theFirstName), lastName(theLastName) {}

    int getID() const { return id; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }

    bool operator<(const Participant& participant) const
        { return (id < participant.id); }

private:
    int id;
    std::string firstName;
    std::string lastName;
};

#endif