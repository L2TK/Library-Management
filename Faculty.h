#pragma once
#include "User.h"

class Faculty: public User{
public:    
    Faculty():User(){
        booksBorrowed = new Book* [15];
        maxNumBooks = 15;
        availableSlot = 15;
    }
    string getRole() const override{ return "faculty"; }
    int menu() override;  //print menu for user, get and return choice
    void printInfo() const override;
    ~Faculty();
};

int Faculty::menu(){
    int choice;
    cout << "**********************************************" << endl;
    cout << "||   Faculty Menu:                          ||" << endl;
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

void Faculty::printInfo() const{
    cout << "Role: faculty" << endl;
    User::printInfo();
}

Faculty::~Faculty(){
    cout << "Faculty deleted!" << endl;
}