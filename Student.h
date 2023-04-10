#pragma once
#include "User.h"

class Student: public User{
public:
    Student():User(){
        maxNumBooks = 5;
        booksBorrowed = new string [5];
    }
    ~Student();
    string getRole() const override{ return "student";}
    int menu() override;
    void printInfo() const override;
    
};

int Student::menu(){
    cout << "vccc" << endl;
    return 1;
}

void Student::printInfo() const{
    cout << "Role: Student" << endl;
    User::printInfo();
}

Student::~Student(){
    cout << "Student deleted." << endl;
}