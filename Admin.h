#pragma once   
#include "Person.h"

class Admin: public Person{
private:
    string role;
public:
    Admin():Person(){ }
    void setRole(string n){ role = n; }
    virtual string getRole() const = 0;
    virtual void executeMenu() = 0;
    void printInfo();
};

void Admin::printInfo(){
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "ID: " << ID << endl;
    cout << "Role: " << role << endl;
    cout << "First Name: " << firstName << endl;
    cout << "Middle Name: " << middleName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << endl;
}