#pragma once
#include "Person.h"
using namespace std;

class Supervisor: public Person{
private:
    string role;
public:
    Supervisor():Person(){};
    string getRole() const override {return "supervisor"; }
    void printInfo() const override;
    int menu() override;
};

int Supervisor::menu(){
    int choice;
    cout << "**********************************************" << endl;
    cout << "||   Supervisor Menu:                       ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Add a librarian                    ||" << endl;
    cout << "||   2 - Delete a librarian                 ||" << endl;
    cout << "||   3 - Add a student                      ||" << endl;
    cout << "||   4 - Delete a student                   ||" << endl;
    cout << "||   5 - Add a book                         ||" << endl;
    cout << "||   6 - Delete a book                      ||" << endl;
    cout << "||   7 - Views all librarians               ||" << endl;
    cout << "||   8 - Views all students                 ||" << endl;
    cout << "||   9 - Views all books                    ||" << endl;
    cout << "||   10 - Log out                           ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << "Choose one option:" << endl;
    cin >> choice;
    return choice;
}

void Supervisor::printInfo() const {
    cout << "Role: Supervisor" << endl;
    cout << "Name: " <<  firstName << " " << middleName << " " << lastName << endl;
    cout << "ID: " << ID << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
}