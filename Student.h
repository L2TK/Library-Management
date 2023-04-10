#pragma once
#include "User.h"

class Student: public User{
public:
    Student():User(){};
    Student(Library* libPtr):User(Library* libPtr){
        maxNumBooks = 5;
        booksBorrowed = new string [5];
    }
    string getRole() const override{ return "student";}

};

