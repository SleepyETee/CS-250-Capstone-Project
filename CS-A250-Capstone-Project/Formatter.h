/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#ifndef FORMATTER_H
#define FORMATTER_H

#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"

class Formatter
{
public:
    static void displayMenu();

    static void printAllWorkshops(const WorkshopList& workshopList);
    static void printOpenWorkshops(const WorkshopList& workshopList,
        const RegistrationManager& registration);
    static void printWorkshopsByPrice(
        const WorkshopList& workshopList, double price);
    static void printParticipantWorkshops(
        const ParticipantList& participantList, int participantID);
    static void printWorkshop(const Workshop& workshop);

    static void pauseAndWait();

};
#endif