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

#include <fstream>
#include <sstream>

using namespace std;

namespace
{
    constexpr char PIPE_DELIM = '|';
}

void DataLoader::loadWorkshops(WorkshopList& workshopList,
    const string& filename)
{
    ifstream inFile(filename);
    string rawLine;

    while (getline(inFile, rawLine))
    {
        istringstream lineStream(rawLine);

        string numberToken;
        getline(lineStream, numberToken, PIPE_DELIM);
        int workshopNumber = stoi(numberToken);

        string titleToken;
        getline(lineStream, titleToken, PIPE_DELIM);

        string hoursToken;
        getline(lineStream, hoursToken, PIPE_DELIM);
        int workshopHours = stoi(hoursToken);

        string capacityToken;
        getline(lineStream, capacityToken, PIPE_DELIM);
        int maxCapacity = stoi(capacityToken);

        string priceToken;
        getline(lineStream, priceToken, PIPE_DELIM);
        double workshopPrice = stod(priceToken);

        workshopList.addWorkshop(Workshop(workshopNumber, titleToken,
            workshopHours, maxCapacity, workshopPrice));
    }
}

void DataLoader::loadParticipants(ParticipantList& participantList,
    const string& filename)
{
    ifstream inFile(filename);
    string rawLine;

    while (getline(inFile, rawLine))
    {
        istringstream lineStream(rawLine);

        string idToken;
        getline(lineStream, idToken, PIPE_DELIM);
        int participantID = stoi(idToken);

        string firstNameToken;
        getline(lineStream, firstNameToken, PIPE_DELIM);
        string firstName = firstNameToken;

        string lastNameToken;
        getline(lineStream, lastNameToken, PIPE_DELIM);
        string lastName = lastNameToken;

        participantList.addParticipant(Participant(participantID, firstName, lastName));
    }
}

void DataLoader::loadRegistration(RegistrationManager& registrationManager,
    const string& filename)
{
    ifstream inFile(filename);
    string rawLine;

    while (getline(inFile, rawLine))
    {
        istringstream lineStream(rawLine);

        string participantIDToken;
        getline(lineStream, participantIDToken, PIPE_DELIM);
        int participantID = stoi(participantIDToken);

        string workshopNumberToken;
        getline(lineStream, workshopNumberToken, PIPE_DELIM);
        int workshopNumber = stoi(workshopNumberToken);

        registrationManager.registerParticipant(participantID, workshopNumber);
    }
}