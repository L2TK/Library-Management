#pragma once
#include "Person.h"
class Librarian: public Person{
public:
    Librarian():Person(){}
    ~Librarian();
    string getRole() const override {return "librarian"; }
    int menu() override;
    void printInfo() const override;
};

int Librarian::menu(){
    cout << "Hi, I'm " << getRole() << endl;
    return 1;
}

void Librarian::printInfo() const {
    cout << "Role: Librarian" << endl;
    cout << "Name: " <<  firstName << " " << middleName << " " << lastName << endl;
    cout << "ID: " << ID << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
}

Librarian::~Librarian(){
    cout << "Librarian delete." << endl;
}