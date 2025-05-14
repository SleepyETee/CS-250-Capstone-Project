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
<<<<<<<< Updated upstream:CS-A250-Capstone-Project/Workshop.h
#include <iostream>

class Workshop {
public:
    Workshop(int theNumber, const std::string& theTitle,
        int theHours, int theCapacity, double thePrice)
        : number(theNumber), title(theTitle), hours(theHours),
        capacity(theCapacity), price(thePrice) {}
========

class Workshop {
public:
    Workshop(int theNumber, const std::string& theTitle, int theHours,
                 int theCapacity, double thePrice)
                 : number(theNumber), title(theTitle), hours(theHours),
                   capacity(theCapacity), price(thePrice) {}
>>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/Workshop.h

    int getNumber() const { return number; };
    std::string getTitle() const { return title; };
    int getHours() const { return hours; };
    int getCapacity() const { return capacity; };
    double getPrice() const { return price; };

<<<<<<<< Updated upstream:CS-A250-Capstone-Project/Workshop.h
    bool operator<(const Workshop& workshop) const
        { return (number < workshop.number); };
<<<<<<< HEAD
    bool operator==(const Workshop& workshop) const
        { return (number == workshop.number); };
========
    bool operator<(const Workshop& workshop) const { return number < workshop.number; };
>>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/Workshop.h
=======
    // bool operator==(const Workshop& workshop) const
    //     { return (number == workshop.number); };
        
bool operator== (const Workshop &workshop) const { return number == workshop.getNumber(); }

>>>>>>> 546f417e5be54449e2bb60339b3ae6f8e43a3fd5

private:
    int number;
    std::string title;
    int hours;
    int capacity;
    double price;
};

<<<<<<<< Updated upstream:CS-A250-Capstone-Project/Workshop.h
#endif
========
#endif //WORKSHOP_H
>>>>>>>> Stashed changes:CS-250-Capstone-Project-main/Header Files/Workshop.h
