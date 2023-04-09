#include <Windows.h>
#include "Supervisor.h"
#include "Librarian.h"
#include "Faculty.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


class Library{
    private:
        Admin* adminArr[10];
        User* userArr[100];
        Book* bookArr[100];

        int adminArrSize;
        int userArrSize;
        int bookArrSize;

        Admin* isValidAdmin(string, string);
        User* isValidUser(string, string);
    public:
        Library();
        void logIn();
        int logInMenu();

        void loadAdmins();
        void loadUsers();
        void loadBooks();
        void saveAdmins();
        void saveUsers();
        void saveBooks();
};

Library::Library(){
    adminArrSize = 0;
    userArrSize = 0;
    bookArrSize = 0;
    for(int i = 0; i < 100; i++){
        userArr[i] = nullptr;
        bookArr[i] = nullptr;
    }
    for(int i = 0; i < 10; i++){
        adminArr[i] = nullptr;
    }
}

void Library::logIn(){
    int role;
    string username, password;
    Admin* adminPtr = nullptr;
    User* userPtr = nullptr;
    role = logInMenu();
    cout << "----------------------------------------------" << endl;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your password: " << endl;
    cin >> password;

    adminPtr = isValidAdmin(username, password);
    userPtr = isValidUser(username, password);

    if(adminPtr){
        if(adminPtr->getRole() == "Supervisor"){
            cout << "Signing in as Supervisor..." << endl;
        }
        else if(adminPtr->getRole() == "Librarian"){
            cout << "Signing in as Librarian..." << endl;
        }
        Sleep(2000);
        cout << "Loading Menu..." << endl;
        Sleep(2000);
        system("CLS");
        adminPtr->executeMenu();
        
    }
    else if(userPtr){
        if(adminPtr->getRole() == "Student"){
            cout << "Signing in as Student..." << endl;
        }
        else if(adminPtr->getRole() == "Faculty"){
            cout << "Signing in as Faculty..." << endl;
        }
        Sleep(1000);
        cout << "Loading Menu..." << endl;
        Sleep(2000);
        system("CLS");
        userPtr->executeMenu();
    }
    cout << "Login failed. Please try again." << endl;
    Sleep(2000);
    system("CLS");
    logIn();
}


Admin* Library::isValidAdmin(string username, string password){
    for(int i = 0; i < adminArrSize; i++){
        if(adminArr[i]->getUsername() == username && adminArr[i]->getPassword() == password){
            cout << "Login Successfully." << endl;
            return adminArr[i];
        }
    }
    return nullptr;
}

User* Library::isValidUser(string username, string password){
    for(int i = 0; i < adminArrSize; i++){
        if(userArr[i]->getUsername() == username && userArr[i]->getPassword() == password){
            cout << "Login Successfully." << endl;
            return userArr[i];
        }
    }
    return nullptr;
}



int Library::logInMenu(){
    int inputNum;
    cout << "**********************************************" << endl;
    cout << "||   Enter the role you want to sign in:    ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Admin                              ||" << endl;
    cout << "||   2 - User                               ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
    cin >> inputNum;
    cout << endl;
    if(inputNum == 1){
        cout << "--------------Loging in as Admin--------------" << endl;
    }
    else if(inputNum == 2){
        cout << "--------------Loging in as User---------------" << endl;
    }
    else{
        cout << "Invalid role. Please enter 1 or 2 only." << endl;
        logInMenu();
    }
    return inputNum;
}

void Library::loadAdmins(){
    string line;
    int id;
    ifstream ifs ("AdminData.txt");
    if(!ifs.is_open()){
        cout << "Admins Data File Not Found!" << endl;
        return;
    }
    adminArrSize = 0;
    while(ifs >>line){
        if(line == "Supervisor"){
            adminArr[adminArrSize] = new Supervisor();
        }
        else if(line == "Librarian"){
            adminArr[adminArrSize] = new Librarian();
        }
        ifs >> line;
        adminArr[adminArrSize]->setUsername(line);
        ifs >> line;
        adminArr[adminArrSize]->setPassword(line);
        ifs >> id;
        adminArr[adminArrSize]->setID(id);
        ifs >> line;
        adminArr[adminArrSize]->setFirstName(line);
        ifs >> line;
        adminArr[adminArrSize]->setMiddleName(line);
        ifs >> line;
        adminArr[adminArrSize]->setLastName(line);
        ifs >> line;
        adminArr[adminArrSize]->setDateOfBirth(line);
        adminArrSize++;
        ifs.ignore();
    }
    ifs.close();
}

void Library::loadUsers(){
    ifstream ifs("UserData.txt");
    if(!ifs.is_open()){
        cout << "Users Data File Not Found!" << endl;
        return;
    }
    string line, bookIndex;
    int id, numBook;
    userArrSize = 0;
    while(ifs >>line){
        if(line == "Student"){
            userArr[userArrSize] = new Student();
        }
        else if(line == "Faculty"){
            userArr[userArrSize] = new Faculty();
        }
        ifs >> line;
        userArr[userArrSize]->setUsername(line);
        ifs >> line;
        userArr[userArrSize]->setPassword(line);
        ifs >> id;
        userArr[userArrSize]->setID(id);
        ifs >> line;
        userArr[userArrSize]->setFirstName(line);
        ifs >> line;
        userArr[userArrSize]->setMiddleName(line);
        ifs >> line;
        userArr[userArrSize]->setLastName(line);
        ifs >> line;
        userArr[userArrSize]->setDateOfBirth(line);
        ifs >> numBook;
        userArr[userArrSize]->setNumBooksBorrowed(numBook);
        for(int i = 0; i < numBook; i++){
            ifs >> bookIndex;
            userArr[userArrSize]->getBookBorrowed()[i] = bookIndex;
        }
        userArrSize++;
    }
    ifs.close();
}

void Library::loadBooks(){
    ifstream ifs("BookData.txt");
    if(!ifs.is_open()){
        cout << "Book Data File Not Found!" << endl;
        return;
    }
    string line;
    bookArrSize = 0;
    string index;
    while(ifs >> index){
        ifs.ignore();
        Book* book1 = new Book;
        book1->index = index;
        getline(ifs, book1->title);  
        getline(ifs, book1->authorName);  
        getline(ifs, book1->publisher);  
        ifs >> book1->publishingYear;
        ifs.ignore();  
        getline(ifs, book1->borrowerName);  
        getline(ifs, book1->expirationDate);  
        ifs >> book1->overdueCharge;
        bookArr[bookArrSize] = book1;
        bookArrSize++;
    }
}

void Library::saveAdmins(){
    ofstream ofs ("AdminData.txt");
    for(int i = 0; i < adminArrSize; i++){
        ofs << adminArr[i]->getRole() << endl;
        ofs << adminArr[i]->getUsername() << endl;
        ofs << adminArr[i]->getPassword() << endl;
        ofs << adminArr[i]->getID() << endl;
        ofs << adminArr[i]->getFirstName() << endl;
        ofs << adminArr[i]->getMiddleName() << endl;
        ofs << adminArr[i]->getLastName() << endl;
        ofs << adminArr[i]->getDateOfBirth() << endl;
        ofs << endl;
    }
    ofs.close();
}
void Library::saveUsers(){
    ofstream ofs ("UserData.txt");
    for(int i = 0; i < userArrSize; i++){
        ofs << userArr[i]->getRole() << endl;
        ofs << userArr[i]->getUsername() << endl;
        ofs << userArr[i]->getPassword() << endl;
        ofs << userArr[i]->getID() << endl;
        ofs << userArr[i]->getFirstName() << endl;
        ofs << userArr[i]->getMiddleName() << endl;
        ofs << userArr[i]->getLastName() << endl;
        ofs << userArr[i]->getDateOfBirth() << endl;
        ofs << userArr[i]->getNumBookBorrowed() << endl;
        for(int j = 0; j < userArr[i]->getNumBookBorrowed(); j++){
            ofs << userArr[i]->getBookBorrowed()[j] << endl;
        }
        ofs << endl;
    }
    ofs.close();
}

void Library::saveBooks(){
    ofstream ofs("BookData.txt");
    for(int i = 0; i < bookArrSize; i++){
        ofs << bookArr[i]->index << endl;
        ofs << bookArr[i]->title << endl;
        ofs << bookArr[i]->authorName << endl;
        ofs << bookArr[i]->publisher << endl;
        ofs << bookArr[i]->publishingYear << endl;
        ofs << bookArr[i]->borrowerName << endl;
        ofs << bookArr[i]->expirationDate << endl;
        ofs << bookArr[i]->overdueCharge << endl;        
        ofs << endl;
    }
    ofs.close();
}