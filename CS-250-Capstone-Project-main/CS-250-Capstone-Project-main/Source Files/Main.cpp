/*
    Team name
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/


#include <iostream>
#include "../Header Files/ParticipantList.h"  // can be changed back to just file names, but this way it works.
#include "../Header Files/Participant.h"
#include "../Header Files/Workshop.h"
#include "../Header Files/WorkshopList.h"

int main()
{
    ParticipantList list;
    Participant p1(1, "Jane", "Garden");

    list.addParticipant(p1);

    return 0;
}