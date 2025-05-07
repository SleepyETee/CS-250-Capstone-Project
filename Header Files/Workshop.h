/*
Team name

    Cherevko, Iuliana (Team Leader)
    Sviridova, Anatasia
    Nguyen, Long

    Spring 2025
    CS A250 - C++ 2

    Workshop Hub
*/

#ifndef WORKSHOP_H
#define WORKSHOP_H

#include <iostream>

class Workshop {
public:
    Workshop(int theNumber, std::string theTitle, int theHours,
                 int theCapacity, double thePrice);

    int getNumber() const { return number; };
    std::string getTitle() const { return title; };
    int getHours() const { return hours; };
    int getCapacity() const { return capacity; };
    double getPrice() const { return price; };
    bool operator<(const Workshop& workshop) { return (number > workshop.number); };

private:
    int number;
    std::string title;
    int hours;
    int capacity;
    double price;
};

#endif //WORKSHOP_H
