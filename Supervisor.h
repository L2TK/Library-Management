#pragma once
#include "Admin.h"
#include "Librarian.h"
class Supervisor: public Admin{
private:
    string role;
public:
    Supervisor():Admin(){
        role = "Supervisor";
    };
    string getRole() const override {return "supervisor"; }

    void executeMenu() override;
    void menu();
    void addLibrarian(Admin* adminArr[], int& adminArrsize);
    void deleteLibrarian(int id, Admin* adminArr[], int& adminArrsize);
};


void Supervisor::addLibrarian(Admin* adminArr[], int& adminArrsize){
    string role;
    if(adminArrsize == 10){
        cout << "Librarian slot is full." << endl;
        return;
    }
    string input;
    cout << "-----Add a librarian-----" << endl;
    cout << "Enter a role (Supervisor or Librarian):" << endl;
    cin >> role;
    if(role == "Supervisor"){
        adminArr[adminArrsize] = new Supervisor();
    }
    else if(role == "Librarian"){
        adminArr[adminArrsize] = new Librarian();
    }
    cout << "Enter first Name:" << endl;
    cin >> input;
    adminArr[adminArrsize]->setFirstName(input);

    cout << "Enter middle Name:" << endl;
    cin >> input;
    adminArr[adminArrsize]->setMiddleName(input);

    cout << "Enter last Name:" << endl;
    cin >> input;
    adminArr[adminArrsize]->setLastName(input);

    cout << "Enter date of birth (mm-dd-yyy):" << endl;
    cin >> input;
    adminArr[adminArrsize]->setDateOfBirth(input);

    cout << "Enter an username:" << endl;
    cin >> input;
    adminArr[adminArrsize]->setUsername(input);

    cout << "Enter a password:" << endl;
    cin >> input;
    adminArr[adminArrsize]->setPassword(input);
    
    adminArr[adminArrsize]->setRole(input);

    int id = rand()%30;
    adminArr[adminArrsize]->setID(id);
    adminArrsize++;
}

void Supervisor::executeMenu(){
    int choice;
    menu();
    cout << "Choose one option:" << endl;
    cin >> choice;
    if(choice == 1){
    }
}


void Supervisor::menu(){
    cout << "**********************************************" << endl;
    cout << "||   Supervisor Menu:                       ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Add a librarian                    ||" << endl;
    cout << "||   2 - Delete a librarian                 ||" << endl;
    cout << "||   3 - Views all librarians               ||" << endl;
    cout << "||   4 - Log out                            ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
}