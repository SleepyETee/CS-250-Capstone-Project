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
#include "Participant.h"
#include "Workshop.h"
#include "WorkshopList.h"
#include "DataLoader.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string DATA_FILE = "workshop_database.txt";

    WorkshopList workshopCatalog;
    DataLoader::loadWorkshops(workshopCatalog, DATA_FILE);

    bool workshopsLoaded = !workshopCatalog.isEmpty();
    cout << (workshopsLoaded
        ? "Workshop data loaded successfully from " + DATA_FILE
        : "No workshops were loaded from " + DATA_FILE)
        << '\n';

    // --------------------------------
    // 2.  Show a sample workshop title
    // --------------------------------
    if (workshopsLoaded)
    {
        const int DEMO_NUM = 11111;     // first record in starter file
        cout << "→ Title for workshop #" << DEMO_NUM << ": "
            << workshopCatalog.getTitle(DEMO_NUM) << '\n';
    }

    // --------------------------------
    // 3.  Create one participant
    // --------------------------------
    ParticipantList participantRoster;
    Participant     demoParticipant(1, "Jane", "Garden");
    participantRoster.addParticipant(demoParticipant);

    cout << (participantRoster.isEmpty()
        ? "Participant roster is empty.\n"
        : "Participant added: " +
        participantRoster.getFirstName(1) + ' ' +
        participantRoster.getLastName(1) + " (ID 1)\n");

    cout << "--- Demo run complete ---\n";
    return 0;
}