#pragma once
#include "Admin.h"
class Librarian: public Admin{
private:
    string role;
public:
    Librarian():Admin(){}
    Librarian(Library* libPtr):Admin(Library* libPtr){
        role = "Librarian";
    }
    string getRole() const override {return "librarian"; }
    void executeMenu() override;

};

void Librarian::executeMenu(){
    cout << "Hi, I'm " << getRole() << endl;
}