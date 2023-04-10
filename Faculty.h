#pragma once
#include "User.h"

class Faculty: public User{
public:    
    Faculty():User(){
        booksBorrowed = new string [15];
        maxNumBooks = 15;
    }
    string getRole() const override{ return "faculty"; }
};