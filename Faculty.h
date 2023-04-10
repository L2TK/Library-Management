#pragma once
#include "User.h"

class Faculty: public User{
public:    
    Faculty():User(){};
    Faculty(Library* libPtr):User(Library* libPtr){
        booksBorrowed = new string [15];
        maxNumBooks = 15;
    }
    string getRole() const override{ return "faculty"; }
};