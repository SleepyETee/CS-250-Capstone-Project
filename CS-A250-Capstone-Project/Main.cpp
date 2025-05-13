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
#include "Participant.h"
#include "Workshop.h"
#include "WorkshopList.h"
#include "DataLoader.h"

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// Helper function
static void displayWorkshop(const Workshop& workshop)
{
    cout << workshop.getNumber() << " | "
        << workshop.getTitle() << " | "
        << workshop.getHours() << "h | "
        << workshop.getCapacity() << " seats | $"
        << workshop.getPrice() << '\n';
}

int main()
{
    WorkshopList workshopCatalog;
    assert(workshopCatalog.isEmpty());

    const string dataFilePath = "workshop_database.txt";
    DataLoader::loadWorkshops(workshopCatalog, dataFilePath);
    assert(!workshopCatalog.isEmpty());

    const int    expectedId = 11111;
    const string expectedTitle = "Emoji Etiquette";
    const int    expectedHours = 2;
    const int    expectedCapacity = 30;
    const double expectedPrice = 30.0;

    assert(workshopCatalog.getTitle(expectedId) ==
        expectedTitle);
    assert(workshopCatalog.getHours(expectedId) ==
        expectedHours);
    assert(workshopCatalog.getCapacity(expectedId) ==
        expectedCapacity);

    double actualPrica = workshopCatalog.getPrice(expectedId);
    assert(abs(actualPrica - expectedPrice) < 1e-6);

    Workshop manualWorkshop(55555, "Manual QA", 3, 10, 20.0);
    workshopCatalog.addWorkshop(manualWorkshop);
    assert(workshopCatalog.getNumber(manualWorkshop) == 55555);

    // Show the manually added workshop
    cout << "\nManual workshop just added:\n";
    displayWorkshop(manualWorkshop);

    cout << "Y WorkshopList & DataLoader OK\n";

    ParticipantList participantRoster;
    assert(participantRoster.isEmpty());

    Participant alice(101, "Alice", "Smith");
    Participant bob(102, "Bob", "Jones");
    participantRoster.addParticipant(alice);
    participantRoster.addParticipant(bob);
    assert(!participantRoster.isEmpty());

    // Test ID and name getters
    assert(participantRoster.getID(alice) == 101);
    assert(participantRoster.getID(bob) == 102);
    assert(participantRoster.getFirstName(101) == "Alice");
    assert(participantRoster.getLastName(101) == "Smith");
    assert(participantRoster.getFirstName(102) == "Bob");
    assert(participantRoster.getLastName(102) == "Jones");

    // Attach workshops to participants
    participantRoster.addWorkshopToParticipant(
        alice, manualWorkshop);
    participantRoster.addWorkshopToParticipant(
        bob, manualWorkshop);

    vector<Workshop> aliceWorkshops =
        participantRoster.getWorkshops(101);
    vector<Workshop> bobWorkshops =
        participantRoster.getWorkshops(102);

    assert(aliceWorkshops.size() == 1 &&
        aliceWorkshops[0].getNumber() == 55555);
    assert(bobWorkshops.size() == 1 &&
        bobWorkshops[0].getNumber() == 55555);

    cout << "Y ParticipantList OK\n";

    workshopCatalog.clearList();
    participantRoster.clearList();
    assert(workshopCatalog.isEmpty());
    assert(participantRoster.isEmpty());

    cout << "Y clearList & isEmpty OK (after clearing)\n";

    cout << "\nAll public functions tested successfully!" << endl;
    return 0;
}