#pragma once
#include "Person.h"
using namespace std;

class Supervisor: public Person{
private:
    string role;
public:
    Supervisor():Person(){};
    ~Supervisor();
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
    cout << "||   3 - Add a user                         ||" << endl;
    cout << "||   4 - Delete a user                      ||" << endl;
    cout << "||   5 - Add a book                         ||" << endl;
    cout << "||   6 - Delete a book                      ||" << endl;
    cout << "||   7 - View all librarians                ||" << endl;
    cout << "||   8 - View all users                     ||" << endl;
    cout << "||   9 - View all books                     ||" << endl;
    cout << "||   10 - Log out                           ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << "Choose one option:" << endl;
    cin >> choice;
    return choice;
}

void Supervisor::printInfo() const {
    cout << "Role: Supervisor" << endl;
    Person::printInfo();
}

Supervisor::~Supervisor(){
    cout << "Supervisor deleted!" << endl;
}