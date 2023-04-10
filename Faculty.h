#pragma once
#include "User.h"

class Faculty: public User{
public:    
    Faculty():User(){
        booksBorrowed = new string [15];
        maxNumBooks = 15;
    }
    string getRole() const override{ return "faculty"; }
    int menu() override;
    void printInfo() const override;
    ~Faculty();
};

int Faculty::menu(){
    return 1;
}

void Faculty::printInfo() const{
    cout << "Role: faculty" << endl;
    User::printInfo();
}

Faculty::~Faculty(){
    cout << "Faculty deleted." << endl;
}