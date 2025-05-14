#include <iostream>
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "DataLoader.h"
using namespace std;

int main() {
    // Test Workshop and WorkshopList
    WorkshopList workshops;
    DataLoader::loadWorkshops(workshops, "workshop_database.txt");
    cout << "Workshops loaded: " << (workshops.isEmpty() ? 0 : 1) << endl;
    cout << "Workshop 11111 Title: " << workshops.getTitle(11111) << endl;
    cout << "Workshop 11111 Price: " << workshops.getPrice(11111) << endl;

    // Test Participant and ParticipantList
    ParticipantList participants;
    Participant p1(1, "John", "Doe");
    participants.addParticipant(p1);
    participants.addWorkshopToParticipant(p1, Workshop(11111, "Emoji Etiquette", 2, 30, 30.0));
    cout << "Participant 1 First Name: " << participants.getFirstName(1) << endl;
    cout << "Participant 1 Workshops: " << participants.getWorkshops(1).size() << endl;

    // Clear lists
    workshops.clearList();
    participants.clearList();
    cout << "Workshops empty: " << workshops.isEmpty() << endl;
    cout << "Participants empty: " << participants.isEmpty() << endl;

    return 0;
}