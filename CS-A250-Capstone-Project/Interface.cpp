/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#include "Interface.h"
#include "Formatter.h"

#include <iostream>

using namespace std;

void processMenu(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    int selection = 0;

    do
    {
        Formatter::displayMenu();

        cout << "\nPlease make a selection: ";
        cin >> selection;
        cout << endl;

        switch (selection)
        {
            case 1:
                viewAllWorkshops(workshopList);
                break;
            case 2:
                viewOpenWorkshops(workshopList, registration);
                break;
            case 3:
                viewWorkshopsByPrice(workshopList);
                break;
            case 4:
                registerForWorkshop(workshopList, participantList,
                    registration);
                break;
            case 5:
                viewParticipantWorkshops(participantList);
                break;
            case 6:
                cancelRegistration(workshopList, participantList,
                    registration);
                break;
            case 7:
                cout << "Thank you for visiting!";
                break;
            default:
                break;
        }

        if (selection != 7)
        {
            Formatter::pauseAndWait();
        }
    } while (selection != 7);
}

void getIdentification(int &participantID, string& firstName,
    string& lastName)
{
    cout << "Enter your ID: ";
    cin >> participantID;
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << endl;
}

bool verifyIdentification(const ParticipantList& participantList,
    int participantID, const string& firstName, const string& lastName)
{
    return participantList.getFirstName(participantID) == firstName &&
        participantList.getLastName(participantID) == lastName;
}

void viewAllWorkshops(const WorkshopList& workshopList)
{
    Formatter::printAllWorkshops(workshopList);
}

void viewOpenWorkshops(const WorkshopList& workshopList,
                       const RegistrationManager& registration)
{
    Formatter::printOpenWorkshops(workshopList, registration);
}

void viewWorkshopsByPrice(const WorkshopList& workshopList)
{
    cout << "Enter max price: $";
    double maxPrice = 0.0;
    cin >> maxPrice;

    Formatter::printWorkshopsByPrice(workshopList, maxPrice);
}

void viewParticipantWorkshops(const ParticipantList& participantList)
{
    int id = 0;
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    if (verifyIdentification(participantList, id, firstName, lastName))
    {
        Formatter::printParticipantWorkshops(participantList, id);
    }
    else
    {
        cout << "The ID number does not match the name provided." << endl;
    }
}

void registerForWorkshop(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    cout << "\tLet's register you for a workshop!\n\n";

    viewOpenWorkshops(workshopList, registration);

    cout << "\nEnter the workshop number or '0' to cancel: ";

    int selection = 0;
    cin >> selection;

    if (selection != 0)
    {
        cout << endl;

        int id = 0;
        string firstName, lastName;
        getIdentification(id, firstName, lastName);

        if (verifyIdentification(
            participantList, id, firstName, lastName))
        {
            registration.registerParticipant(selection, id);

            cout << "You are registered for the following workshop:"
                << "\n\n";

            Formatter::printWorkshop(
                workshopList.getWorkshop(selection));

            cout << "\nA confirmation email with payment details has"
                " been sent to you." << endl;
        }
        else
        {
            cout << "The ID number does not match the name provided."
                 << endl;
        }
    }
}

void cancelRegistration(const WorkshopList& workshopList,
    ParticipantList& participantList, RegistrationManager& registration)
{
    int id = 0;
    string firstName, lastName;
    getIdentification(id, firstName, lastName);

    if (verifyIdentification(
        participantList, id, firstName, lastName))
    {
        Formatter::printParticipantWorkshops(participantList, id);
        cout << "\nWhich workshop number would you like to cancel? ";

        int selection = 0;
        cin >> selection;

        registration.unregisterParticipant(selection, id);

        cout << "\nYour registration for the following workshop "
             << "has been cancelled:\n\n";

        Formatter::printWorkshop(
            workshopList.getWorkshop(selection));

        cout << "\nA confirmation email with refund details "
             << "has been sent to you." << endl;
    }
    else
    {
        cout << "\nThe ID number does not match the name provided."
             << endl;
    }
}