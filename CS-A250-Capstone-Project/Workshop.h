/*
    Tech Wizards

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anastasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <string>

class Workshop {
public:
    Workshop(int theNumber, const std::string& theTitle,
        int theHours, int theCapacity, double thePrice)
        : number(theNumber), title(theTitle), hours(theHours),
        capacity(theCapacity), price(thePrice) {}

    int getNumber() const { return number; }
    std::string getTitle() const { return title; }
    int getHours() const { return hours; }
    int getCapacity() const { return capacity; }
    double getPrice() const { return price; }

    bool operator<(const Workshop& workshop) const
        { return (number < workshop.number); }
    bool operator== (const Workshop& workshop) const
        { return (number == workshop.number); }

private:
    int number;
    std::string title;
    int hours;
    int capacity;
    double price;
};

#endif