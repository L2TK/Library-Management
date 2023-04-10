#pragma once
#include <Windows.h>
#include "Supervisor.h"
#include "Librarian.h"
#include "Faculty.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

class Library{
    private:
        Person* personArr[100];
        Book* bookArr[100];
        Person* userPtr;
        int numSupervisor;
        int numLibrarian;
        int numStudent;
        int numFaculty;
        int personArrSize;
        int bookArrSize;

        Person* isValidMem(string, string, string);
        void supervisorExecuteMenu();
        void librarianExecuteMenu(){};
        void studentExecuteMenu(){};
        void facultyExecuteMenu(){};
        void addLibrarian();
        void deleteLibrarian();
        void printAdmin();
        void printBook(){};
    public:
        Library();
        void logIn();
        string logInMenu();

        void loadPerson();
        void loadBooks();

        void savePerson();
        void saveBooks();

        Person** getPersonArr(){ return personArr;}
        Book** getBookArr(){ return bookArr;}

        int getUserArrSize(){ return personArrSize; }
        int getBookArrSize(){ return bookArrSize; }
};

Library::Library(){
    personArrSize = 0;
    bookArrSize = 0;
    numFaculty = 0;
    numLibrarian = 0;
    numSupervisor = 0;
    numStudent = 0;
    userPtr = nullptr;
    for(int i = 0; i < 100; i++){
        bookArr[i] = nullptr;
    }
    for(int i = 0; i < 10; i++){
        personArr[i] = nullptr;
    }
}

void Library::supervisorExecuteMenu(){
    int choice =  userPtr->menu();
    if(choice == 1){
        addLibrarian();
    }
    else if(choice ==2){
        deleteLibrarian();
    }
    else if(choice == 3){

    }
    else if(choice == 4){

    }
    else{
        cout << "Invalid option. Please try again." << endl;
    }
    supervisorExecuteMenu();
}

void Library::addLibrarian(){
    int role;
    if(numLibrarian == 10){
        cout << "Librarian slot is full." << endl;
        return;
    }
    string input;
    cout << "-----Add a librarian-----" << endl;
    cout << "Enter a role: " << endl;
    cout << "1 - Supervisor " << endl;
    cout << "2 - Librarian " << endl;
    cin >> role;
    if(role == 1){
        personArr[personArrSize] = new Supervisor();
        numSupervisor++;
    }
    else if(role == 2){
        personArr[personArrSize] = new Librarian();
        numLibrarian++;
    }
    cout << "-------------------------" << endl;
    cout << "Enter first Name:" << endl;
    cin >> input;
    personArr[personArrSize]->setFirstName(input);
    cout << "-------------------------" << endl;
    cout << "Enter middle Name:" << endl;
    cin >> input;
    personArr[personArrSize]->setMiddleName(input);
    cout << "-------------------------" << endl;
    cout << "Enter last Name:" << endl;
    cin >> input;
    personArr[personArrSize]->setLastName(input);
    cout << "-------------------------" << endl;
    cout << "Enter date of birth (mm-dd-yyy):" << endl;
    cin >> input;
    personArr[personArrSize]->setDateOfBirth(input);
    cout << "-------------------------" << endl;
    cout << "Enter an username:" << endl;
    cin >> input;
    personArr[personArrSize]->setUsername(input);
    cout << "-------------------------" << endl;
    cout << "Enter a password:" << endl;
    cin >> input;
    personArr[personArrSize]->setPassword(input);
    
    int id = rand()%30;
    personArr[personArrSize]->setID(id);
    personArrSize++;
    numLibrarian++;
    savePerson();
}

void Library::deleteLibrarian(){
    string input;
    int inputID;
    bool found = false;
    printAdmin();
    cout << "-------------------------" << endl;
    cout << "Enter librarian's ID you want to remove(or \"quit\" to quit):" << endl;
    cin >> input;
    if(input == "quit"){
        cout << "Backing to menu..." << endl;
        Sleep(1500);
        supervisorExecuteMenu();
    }
    else{
        istringstream iss(input);
        iss >> inputID;
    }
    cout << "You entered: " << inputID << endl;
    for(int i = 0; i < personArrSize; i++){
        if(personArr[i]->getID() == inputID){
            found = true;
            delete personArr[i];
            personArr[i] = nullptr;
            for(int j = i; j < personArrSize; j++){
                personArr[j] = personArr[j+1];
            }
            personArrSize--;
            numLibrarian--;
            savePerson();
            break;
        }
    }
    if(!found){
        cout << "You entered invalid ID. Please try again." << endl;
        deleteLibrarian();
    }
}

void Library::printAdmin(){
    cout << "-------------View all librarian-------------- " << endl;
    for(int i = 0; i < personArrSize; i++){
        if(personArr[i]->getRole() == "librarian"){
            personArr[i]->printInfo();
        }
    }
}

void Library::logIn(){
    string role;
    string username, password;
    role = logInMenu();
    cout << "----------------------------------------------" << endl;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "----------------------------------------------" << endl;
    cout << "Enter your password: " << endl;
    cin >> password;

    userPtr = isValidMem(role, username, password);
    cout << 1 << endl;
    if(userPtr){
        if(userPtr->getRole() == "supervisor"){
            cout << "Signing in as Supervisor..." << endl;
            Sleep(2000);
            system("CLS");
            supervisorExecuteMenu();
        }
        else if(userPtr->getRole() == "librarian"){
            cout << "Signing in as Librarian..." << endl;
            Sleep(2000);
            system("CLS");
            librarianExecuteMenu();
        }
        else if(userPtr->getRole() == "student"){
            cout << "Signing in as Student..." << endl;
            Sleep(2000);
            system("CLS");
            studentExecuteMenu();
        }
        else if(userPtr->getRole() == "faculty"){
            cout << "Signing in as Faculty..." << endl;
            Sleep(2000);
            system("CLS");
            facultyExecuteMenu();
        }
    }
    else{
        cout << "Login failed. Please try again." << endl;
        Sleep(2000);
        system("CLS");
        logIn();
    }
}

Person* Library::isValidMem(string role, string username, string password){
    for(int i = 0; i < personArrSize; i++){
        if(personArr[i]->getUsername() == username && personArr[i]->getPassword() == password
            && personArr[i]->getRole() == role){
            cout << "Login Successfully." << endl;
            return personArr[i];
        }
    }
    return nullptr;
}

string Library::logInMenu(){
    int inputNum;
    string role;
    cout << "**********************************************" << endl;
    cout << "||   Enter the role you want to sign in:    ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "||   1 - Supervisor                         ||" << endl;
    cout << "||   2 - Librarian                          ||" << endl;
    cout << "||   3 - Faculty                            ||" << endl;
    cout << "||   4 - Student                            ||" << endl;
    cout << "||                                          ||" << endl;
    cout << "**********************************************" << endl;
    cout << endl;
    cin >> inputNum;
    cout << endl;
    if(inputNum == 1){
        role = "supervisor";
        cout << "--------------Loging in as Supervisor--------------" << endl;
    }
    else if(inputNum == 2){
        role = "librarian";
        cout << "--------------Loging in as Librarian---------------" << endl;
    }
    else if(inputNum == 3){
        role = "faculty";
        cout << "--------------Loging in as Faculty---------------" << endl;
    }
    else if(inputNum == 4){
        role = "student";
        cout << "--------------Loging in as Student---------------" << endl;
    }
    else{
        cout << "Invalid role. Please enter 1 or 2 only." << endl;
        logInMenu();
    }
    return role;
}

void Library::loadPerson(){
    Person* p = nullptr;
    string line, bookIndex;
    int id, numBook;
    ifstream ifs ("PersonData.txt");
    if(!ifs.is_open()){
        cout << "Person Data File Not Found!" << endl;
        return;
    }
    personArrSize = 0;
    while(ifs >>line){
        if(line == "supervisor"){
            p = new Supervisor();
            numSupervisor++;
        }
        else if(line == "librarian"){
            p = new Librarian();
            numLibrarian++;
        }
        else if(line == "faculty"){
            p = new Faculty();
            numFaculty++;
        }
        else if(line == "student"){
            p = new Student();
            numStudent++;
        }
        ifs >> line;
        p->setUsername(line);
        ifs >> line;
        p->setPassword(line);
        ifs >> id;
        p->setID(id);
        ifs >> line;
        p->setFirstName(line);
        ifs >> line;
        p->setMiddleName(line);
        ifs >> line;
        p->setLastName(line);
        ifs >> line;
        p->setDateOfBirth(line);
        if(p->getRole() == "faculty" || p->getRole() == "student"){
            ifs >> numBook;
            p->setNumBooksBorrowed(numBook);
            for(int i = 0; i < numBook; i++){
                ifs >> bookIndex;
                p->getBookBorrowed()[i] = bookIndex;
            }
        }
        personArr[personArrSize] = p;
        personArrSize++;
        ifs.ignore();
    }
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
    ifs.close();
}

void Library::savePerson(){
    ofstream ofs ("PersonData.txt");
    for(int i = 0; i < personArrSize; i++){
        ofs << personArr[i]->getRole() << endl;
        ofs << personArr[i]->getUsername() << endl;
        ofs << personArr[i]->getPassword() << endl;
        ofs << personArr[i]->getID() << endl;
        ofs << personArr[i]->getFirstName() << endl;
        ofs << personArr[i]->getMiddleName() << endl;
        ofs << personArr[i]->getLastName() << endl;
        ofs << personArr[i]->getDateOfBirth() << endl;
        if(personArr[i]->getRole() == "student"|| personArr[i]->getRole() == "faculty"){
            ofs << personArr[i]->getNumBookBorrowed() << endl;
            for(int j = 0; j < personArr[i]->getNumBookBorrowed(); j++){
                ofs << personArr[i]->getBookBorrowed()[j] << endl;
            }
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