#pragma once
#include "Admin.h"
class Librarian: public Admin{
private:
    string role;
public:
    Librarian():Admin(){
        role = "Librarian";
    };
    string getRole() const override {return "Librarian"; }
    void executeMenu() override;

};

void Librarian::executeMenu(){
    cout << "Hi, I'm " << getRole() << endl;
}