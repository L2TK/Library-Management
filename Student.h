#pragma once
#include "User.h"

class Student: public User{
public:
    Student():User(){
        maxNumBooks = 5;
        availableSlot = 5;
        booksBorrowed = new Book* [5];
    }
    ~Student();
    string getRole() const override{ return "student";}
    int menu() override; //print menu for user, get, and return choice
    void printInfo() const override;
    
};

int Student::menu(){
    int choice;
    cout << "**********************************************" << endl;
    cout << "||   Student Menu:                          ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Borrow book                        ||" << endl;
    cout << "||   2 - Return book                        ||" << endl;
    cout << "||   3 - View all available books           ||" << endl;
    cout << "||   4 - View all borrowing books           ||" << endl;
    cout << "||   5 - View current late fee              ||" << endl;
    cout << "||   6 - Pay late fee                       ||" << endl;
    cout << "||   7 - Log out                            ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << "Choose one option:" << endl;
    cin >> choice;
    return choice;
}

void Student::printInfo() const{
    cout << "Role: Student" << endl;
    User::printInfo();
}

Student::~Student(){
    cout << "Student deleted!" << endl;
}