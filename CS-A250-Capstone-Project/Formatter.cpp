/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "Formatter.h"
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include "Workshop.h"

#include <iostream>
#include <iomanip>

using namespace std;

void Formatter::displayMenu() {
	cout << "*********************************************\n"
	     << "*                WORKSHOP HUB               *\n"
	     << "*********************************************\n";
	cout << "\n";
	cout << "\t1. View all workshops\n";
	cout << "\t2. View open workshops\n";
	cout << "\t3. View workshops by price\n";
	cout << "\t4. Register for a workshop\n";
	cout << "\t5. List all your workshops\n";
	cout << "\t6. Cancel registration\n";
	cout << "\t7. Exit\n";
}

void Formatter::printAllWorkshops(const WorkshopList& workshopList) {
	cout << "\nALL WORKSHOPS\n";
	cout << "(Workshop #) Workshop Name\n";
	cout << "-----------------------------\n";
	for (const auto& workshop : workshopList.getAllWorkshops()) {
		cout << "(" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
	}
}

void Formatter::printOpenWorkshops(const WorkshopList& workshopList,
						   const RegistrationManager& registration) {
	cout << "\nOPEN WORKSHOPS\n";
	cout << "(Workshop #) Workshop Name\n";
	cout << "--------------------------\n";
	for (int workshopNo : registration.getOpenWorkshops()) {
		const Workshop& workshop = workshopList.getWorkshop(workshopNo);
		cout << "(" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
	}
}

void Formatter::printWorkshopsByPrice(const WorkshopList& workshopList, double price) {
	cout << "\nWORKSHOPS BY PRICE\n";
	cout << "(Workshop #) $Price Workshop Name\n";
	cout << "---------------------------------\n";
	for (const auto& workshop : workshopList.getAllWorkshops()) {
		if (workshop.getPrice() <= price) {
			cout << "$" << fixed << setprecision(2) << workshop.getPrice()
			     << " (" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
		}
	}
}

void Formatter::printParticipantWorkshops(const ParticipantList& participantList,
					       int participantID) {
	auto workshops = participantList.getWorkshops(participantID);
	cout << "\nYOUR WORKSHOPS\n";
	cout << "(Workshop #) Workshop Name\n";
	cout << "--------------------------\n";
	if (workshops.empty()) {
		cout << "You are not currently registered for any workshops.\n";
	} else {
		for (const auto& workshop : workshops) {
			cout << "(" << workshop.getNumber() << ") " << workshop.getTitle() << "\n";
		}
	}
}

void Formatter::printWorkshop(const Workshop& workshop) {
	cout << "\n" << workshop.getTitle() << "\n";
	cout << "Number: " << workshop.getNumber() << "\n";
	cout << "Hours: " << workshop.getHours() << "\n";
	cout << "Price: $" << fixed << setprecision(2) << workshop.getPrice() << "\n";
}

void Formatter::pauseAndWait() {
	cout << "\nPress 'Enter' to return to the menu...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
