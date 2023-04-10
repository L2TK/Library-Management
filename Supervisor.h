#pragma once
#include "Admin.h"
#include "Librarian.h"
class Supervisor: public Admin{
private:
    string role;
public:
    Supervisor():Admin(){};
    Supervisor(Library* libPtr):Admin(Library* libPtr){};
    string getRole() const override {return "supervisor"; }

    void executeMenu() override;
    void menu();
    void addLibrarian();
    void deleteLibrarian(int id, Admin* adminArr[], int& adminArrsize);
};

void Supervisor::executeMenu(){
    int choice;
    menu();
    cout << "Choose one option:" << endl;
    cin >> choice;
    if(choice == 1){

    }
    else if(choice ==2){

    }
    else if(choice == 3){

    }
    else if(choice == 4){

    }
    else{
        cout << "Invalid option. Please try again." << endl;
    }
    executeMenu();
}


void Supervisor::menu(){
    cout << "**********************************************" << endl;
    cout << "||   Supervisor Menu:                       ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Add a librarian                    ||" << endl;
    cout << "||   2 - Delete a librarian                 ||" << endl;
    cout << "||   3 - Views all librarians               ||" << endl;
    cout << "||   4 - Log out                            ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
}