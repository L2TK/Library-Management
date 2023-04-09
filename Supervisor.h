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
    string getRole() const override {return "Supervisor"; }

    void executeMenu() override;

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
    cout << "Hi, I'm " << getRole() << endl;
}


