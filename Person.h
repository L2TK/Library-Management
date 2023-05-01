#pragma once   
#include <string>
#include <iostream>
#include "Book.h"
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
    //getters and setters of person info
    string getFirstName(){ return firstName; }
    string getMiddleName(){ return middleName; }
    string getLastName(){ return lastName; }
    string getFullName(){ return firstName + " " + 
                        middleName + " " + lastName; }
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
    //virtual getter and sett of user late fee, books borrowing, and available slot (overriden by class User)
    virtual void setLateFee(int ){}
    virtual int getLateFee(){ return 0; }; //return late fee (used for user class)
    virtual void setNumBooksBorrowed(int ){}; //set num books b (used for user class)
    virtual int getAvailableSlot(){ return 0; };
    virtual Book** getBookBorrowed(){ return nullptr; };
    virtual int getNumBookBorrowed(){ return 0; };
    virtual void borrowBook(Book* ){}
    virtual bool returnBook(string ){return false;};
    virtual void viewBorrowingBooks(){};
    virtual void payLateFee(string ){};
    virtual void viewLateFee(){};

    virtual ~Person(){}
    //virtual functions that will be override by all derived class
    virtual string getRole() const = 0; //pure virtual function to return role of each person
    virtual int menu() = 0; //pure virtual function to return different menu for different role
    virtual void printInfo() const; //pure virtual function to return person info, user will have more info

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

void Person::printInfo() const {
    cout << "Name: " <<  firstName << " " << middleName << " " << lastName << endl;
    cout << "ID: " << ID << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
}
