#pragma once   
#include <string>
#include <iostream>
using namespace std;

class Person{
protected:
    string lastName;
    string firstName;
    string middleName;
    int ID;
    string username;
    string password;
    string dateOfBirth;
public:
    Person();
    string getFirstName(){ return firstName; }
    string getMiddleName(){ return middleName; }
    string getLastName(){ return lastName; }
    string getDateOfBirth(){ return dateOfBirth; }
    string getUsername(){ return username; }
    string getPassword(){ return password; }
    int getID(){ return ID; }
    
    void setFirstName(string _firstName){ firstName = _firstName; }
    void setMiddleName(string _middleName){ middleName = _middleName; }
    void setLastName(string _lastname){ lastName = _lastname; }
    void setDateOfBirth(string _dateOfBirth){ dateOfBirth = _dateOfBirth; }
    void setUsername(string _username){ username = _username; }
    void setPassword(string _password){ password = _password; }
    void setID(int _ID){ ID = _ID; }

    
    virtual string getRole() const = 0;
};
Person::Person(){
    lastName = "";
    firstName = "";
    middleName = "";
    ID = 0;
    username = "";
    password = "";
    dateOfBirth = "";
}