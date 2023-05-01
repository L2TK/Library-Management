#pragma once
#include "Person.h"
class Librarian: public Person{
public:
    Librarian():Person(){}
    ~Librarian();
    string getRole() const override {return "librarian"; }
    int menu() override; //print menu for librarian, get, and return user’s choice
    void printInfo() const override;
};

int Librarian::menu(){
    int choice;
    cout << "**********************************************" << endl;
    cout << "||   Librarian Menu:                        ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Add a user                         ||" << endl;
    cout << "||   2 - Delete a user                      ||" << endl;
    cout << "||   3 - Add a book                         ||" << endl;
    cout << "||   4 - Delete a book                      ||" << endl;
    cout << "||   5 - View all users                     ||" << endl;
    cout << "||   6 - View all books                     ||" << endl;
    cout << "||   7 - Log out                            ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << "Choose one option:" << endl;
    cin >> choice;
    return choice;
}

void Librarian::printInfo() const {
    cout << "Role: Librarian" << endl;
    Person::printInfo();
}

Librarian::~Librarian(){
    cout << "Librarian deleted!" << endl;
}