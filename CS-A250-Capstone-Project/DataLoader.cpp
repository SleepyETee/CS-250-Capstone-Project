/*
    Tech Wizards
    
    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub    
*/

#include "DataLoader.h"
#include "WorkshopList.h"
#include "ParticipantList.h"
#include "RegistrationManager.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

using namespace std;

namespace
{
    constexpr char PIPE_DELIM = '|';
}

void DataLoader::loadWorkshops(WorkshopList& workshopList,
    const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Could not open workshop file: " + filename);
    }

    string rawLine;
    int lineNumber = 0;

    try {
        while (getline(inFile, rawLine))
        {
            lineNumber++;
            istringstream lineStream(rawLine);

            string numberToken;
            if (!getline(lineStream, numberToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop number");
            }
            int workshopNumber = stoi(numberToken);

            string titleToken;
            if (!getline(lineStream, titleToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop title");
            }

            string hoursToken;
            if (!getline(lineStream, hoursToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop hours");
            }
            int workshopHours = stoi(hoursToken);

            string capacityToken;
            if (!getline(lineStream, capacityToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop capacity");
            }
            int maxCapacity = stoi(capacityToken);

            string priceToken;
            if (!getline(lineStream, priceToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop price");
            }
            double workshopPrice = stod(priceToken);

            workshopList.addWorkshop(Workshop(workshopNumber, titleToken,
                workshopHours, maxCapacity, workshopPrice));
        }
    }
    catch (const exception& e) {
        throw runtime_error("Error parsing workshop at line " + 
            to_string(lineNumber) + ": " + e.what());
    }
}

void DataLoader::loadParticipants(ParticipantList& participantList,
    const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Could not open participant file: " + filename);
    }

    string rawLine;
    int lineNumber = 0;

    try {
        while (getline(inFile, rawLine))
        {
            lineNumber++;
            istringstream lineStream(rawLine);

            string idToken;
            if (!getline(lineStream, idToken, PIPE_DELIM)) {
                throw runtime_error("Missing participant ID");
            }
            int participantId = stoi(idToken);

            string firstNameToken;
            if (!getline(lineStream, firstNameToken, PIPE_DELIM)) {
                throw runtime_error("Missing participant first name");
            }

            string lastNameToken;
            if (!getline(lineStream, lastNameToken, PIPE_DELIM)) {
                throw runtime_error("Missing participant last name");
            }

            participantList.addParticipant(Participant(participantId, firstNameToken,
                lastNameToken));
        }
    }
    catch (const exception& e) {
        throw runtime_error("Error parsing participant at line " + 
            to_string(lineNumber) + ": " + e.what());
    }
}

void DataLoader::loadRegistrations(RegistrationManager& registrationManager,
    const string& filename)
{
    ifstream inFile(filename);
    if (!inFile) {
        throw runtime_error("Could not open registration file: " + filename);
    }

    string rawLine;
    int lineNumber = 0;

    try {
        while (getline(inFile, rawLine))
        {
            lineNumber++;
            istringstream lineStream(rawLine);

            string participantIdToken;
            if (!getline(lineStream, participantIdToken, PIPE_DELIM)) {
                throw runtime_error("Missing participant ID");
            }
            int participantId = stoi(participantIdToken);

            string workshopIdToken;
            if (!getline(lineStream, workshopIdToken, PIPE_DELIM)) {
                throw runtime_error("Missing workshop ID");
            }
            int workshopId = stoi(workshopIdToken);

            registrationManager.registerParticipant(participantId, workshopId);
        }
    }
    catch (const exception& e) {
        throw runtime_error("Error parsing registration at line " + 
            to_string(lineNumber) + ": " + e.what());
    }
}

