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
#include <chrono>
#include <ctime>
using namespace std;



class Library{
    private:
        Person* personArr[215];
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
        void librarianExecuteMenu();
        void userExecuteMenu();

        void addAdmin();
        void deleteAdmin();

        void addUser();
        void deleteUser();

        void addBook();
        void deleteBook();

        void viewAllLibrarians();
        void viewAllUsers();
        void viewAllBooks();
        void viewAllAvailableBooks();

        void borrowBook();
        void returnBook();

        void toMenu();

        string getCurrentTime();
        string getExpirationTime();

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
    for(int i = 0; i < 10; i++){
        bookArr[i] = nullptr;
    }
    for(int i = 0; i < 215; i++){
        personArr[i] = nullptr;
    }
}



void Library::toMenu(){
    cout << "Loading menu..." << endl;
    Sleep(1500);
    system("CLS");
    savePerson();
    saveBooks();
    if(userPtr->getRole() == "supervisor"){
        supervisorExecuteMenu();
    }
    else if(userPtr->getRole() == "librarian"){
        librarianExecuteMenu();
    }
    else if(userPtr->getRole() == "faculty" || userPtr->getRole() == "student" ){
        userExecuteMenu();
    }
}

void Library::supervisorExecuteMenu(){
    int choice =  userPtr->menu();
    if(choice == 1){
        addAdmin();
    }
    else if(choice == 2){
        deleteAdmin();
    }
    else if(choice == 3){
        addUser();
    }
    else if(choice == 4){
        deleteUser();
    }
    else if(choice == 5){
        addBook();
    }
    else if(choice == 6){
        deleteBook();
    }
    else if(choice == 7){
        viewAllLibrarians();
    }
    else if(choice == 8){
        viewAllUsers();
    }
    else if(choice == 9){
        viewAllBooks();
    }
    else if(choice == 10){
        logIn();
    }
    else{
        cout << "Invalid option. Please try again." << endl;
    }
    toMenu();
}

void Library::librarianExecuteMenu(){
    int choice =  userPtr->menu();
    if(choice == 1){
        addUser();
    }
    else if(choice == 2){
        deleteUser();
    }
    else if(choice == 3){
        addBook();
    }
    else if(choice == 4){
        deleteBook();
    }
    else if(choice == 5){
        viewAllUsers();
    }
    else if(choice == 6){
        viewAllBooks();
    }
    else if(choice == 7){
        logIn();
    }
    else{
        cout << "Invalid option. Please try again." << endl;
    }
    librarianExecuteMenu();
}

void Library::userExecuteMenu(){
    int choice =  userPtr->menu();
    if(choice == 1){
        addUser();
    }
    else if(choice == 2){
        deleteUser();
    }
    else if(choice == 3){
        addBook();
    }
    else if(choice == 4){
        deleteBook();
    }
    else if(choice == 5){
        viewAllUsers();
    }
    else if(choice == 6){
        viewAllBooks();
    }
    else if(choice == 7){
        logIn();
    }
    else{
        cout << "Invalid option. Please try again." << endl;
    }
    userExecuteMenu();
}

void Library::borrowBook(){
    string index;
    if(userPtr->getAvailableSlot() == 0){
        cout << "Your slot is full. You can\'t borrow more books. Return books if you want to borrow more." << endl;
        toMenu();
    }
    if(userPtr->getLateFee() != 0){
        cout << "You have late fee that must be paid. Please pay late fee before borrow another book." << endl;
        toMenu();
    }
    viewAllAvailableBooks();
    cout << "----------------Borrow Book----------------" << endl;
    cout << "Enter book's index you want to borrow (or \"quit\" to quit):" << endl;
    cin >> index;
    if(index == "quit"){
        toMenu();
    }
    for(int i = 0; i < bookArrSize; i++){
        if(bookArr[i]->available && bookArr[i]->index == index){
            bookArr[i]->borrowerName == userPtr->getFullName();
            bookArr[i]->startDate = getCurrentTime();
            bookArr[i]->expirationDate = getExpirationTime();
            bookArr[i]->overdueCharge = 0;
            userPtr->addBook(index);
            cout << "Proceed done!" << endl;
            toMenu();
        }
        
    }
    cout << "Invalid index. Please try again." << endl;
    borrowBook();
}

void Library::addBook(){
    cout << "-----Add a book------" << endl;
    Book* b = new Book();
    cout << "Create book index:" << endl;
    cin >> b->index;
    cout << "Enter book's title:" << endl;
    cin.ignore();
    getline(cin, b->title);
    cout << "Enter author's name:" << endl;
    getline(cin, b->authorName);
    cout << "Enter book's publisher:" << endl;
    getline(cin, b->publisher);
    cout << "Enter book's pushlishing year: " << endl;
    cin >> b->publishingYear;
    b->borrowerName = "none";
    b->startDate = "none";
    b->expirationDate = "none";
    b->overdueCharge = 0;
    b->available = true;
    bookArr[bookArrSize] = b;
    bookArrSize++;
    toMenu();
}

void Library::deleteBook(){
    bool found = false;
    string inputIndex;
    viewAllBooks();
    cout << "--------Delete a book---------" << endl;
    cout << "Enter book's index you to want delete (or \"quit\" to quit):" << endl;
    cin >> inputIndex;
    if(inputIndex == "quit"){
        toMenu();
    }

    for(int i = 0; i < bookArrSize; i++){
        if(bookArr[i]->index == inputIndex){
            found = true;
            delete bookArr[i];
            bookArr[i] = nullptr;
            for(int j = i; j < bookArrSize - 1; j++){
                bookArr[j] = bookArr[j+1];
            }
            bookArrSize--;
            toMenu();
        }
    }
    
    if(!found){
        cout << "You entered invalid index. Please try again." << endl;
        deleteBook();
    }
}

void Library::addUser(){
    int role, inputID;
    Person* p = nullptr;
    string input;
    cout << "-----Add an User-----" << endl;
    cout << "Enter a role: " << endl;
    cout << "1 - Faculty " << endl;
    cout << "2 - Student " << endl;
    cin >> role;

    if(role == 1){
        if(numFaculty == 100){
            cout << "Faculty slot is full." << endl;
            toMenu();
        }
        p = new Faculty();
        numFaculty++;
    }
    else if(role == 2){
        if(numStudent == 100){
            cout << "Student slot is full." << endl;
            toMenu();
        }
        p = new Student();
        numStudent++;
    }
    cout << "-------------------------" << endl;
    cout << "Enter first Name:" << endl;
    cin >> input;
    p->setFirstName(input);
    cout << "-------------------------" << endl;
    cout << "Enter middle Name:" << endl;
    cin >> input;
    p->setMiddleName(input);
    cout << "-------------------------" << endl;
    cout << "Enter last Name:" << endl;
    cin >> input;
    p->setLastName(input);
    cout << "-------------------------" << endl;
    cout << "Enter date of birth (mm-dd-yyy):" << endl;
    cin >> input;
    p->setDateOfBirth(input);
    cout << "-------------------------" << endl;
    cout << "Enter an username:" << endl;
    cin >> input;
    p->setUsername(input);
    cout << "-------------------------" << endl;
    cout << "Enter a password:" << endl;
    cin >> input;
    p->setPassword(input);
    cout  << "Enter ID:" << endl;
    cin >> inputID;
    p->setID(inputID);
    personArr[personArrSize] = p;
    personArrSize++;
    toMenu();
}

void Library::deleteUser(){
    viewAllUsers();
    cout << "-----Delete an User-----" << endl;
    string input;
    int inputID;
    bool found = false;
    cout << "-------------------------" << endl;
    cout << "Enter user's ID you want to remove (or \"quit\" to quit):" << endl;
    cin >> input;
    if(input == "quit"){
        cout << "Backing to menu..." << endl;
        toMenu();
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
            toMenu();
        }
    }
    if(!found){
        cout << "You entered invalid ID. Please try again." << endl;
        deleteUser();
    }
}

void Library::addAdmin(){
    int role , inputID;
    Person* p = nullptr;
    string input;
    cout << "-----Add an Admin-----" << endl;
    cout << "Enter a role: " << endl;
    cout << "1 - Supervisor " << endl;
    cout << "2 - Librarian " << endl;
    cin >> role;

    if(role == 1){
        if(numSupervisor == 5){
            cout << "Supervisor slot is full." << endl;
            toMenu();
        }
        p = new Supervisor();
        numSupervisor++;
    }
    else if(role == 2){
        if(numLibrarian == 10){
            cout << "Librarian slot is full." << endl;
            toMenu();
        }
        p = new Librarian();
        numLibrarian++;
    }
    cout << "-------------------------" << endl;
    cout << "Enter first Name:" << endl;
    cin >> input;
    p->setFirstName(input);
    cout << "-------------------------" << endl;
    cout << "Enter middle Name:" << endl;
    cin >> input;
    p->setMiddleName(input);
    cout << "-------------------------" << endl;
    cout << "Enter last Name:" << endl;
    cin >> input;
    p->setLastName(input);
    cout << "-------------------------" << endl;
    cout << "Enter date of birth (mm-dd-yyy):" << endl;
    cin >> input;
    p->setDateOfBirth(input);
    cout << "-------------------------" << endl;
    cout << "Enter an username:" << endl;
    cin >> input;
    p->setUsername(input);
    cout << "-------------------------" << endl;
    cout << "Enter a password:" << endl;
    cin >> input;
    p->setPassword(input);
    cout  << "Enter ID:" << endl;
    cin >> inputID;
    p->setID(inputID);
    personArr[personArrSize] = p;
    personArrSize++;
    toMenu();
}

void Library::deleteAdmin(){
    viewAllLibrarians();
    cout << "-----Delete an Admin-----" << endl;
    string input;
    int inputID;
    bool found = false;
    cout << "-------------------------" << endl;
    cout << "Enter librarian's ID you want to remove (or \"quit\" to quit):" << endl;
    cin >> input;
    if(input == "quit"){
        toMenu();
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
            for(int j = i; j < personArrSize - 1; j++){
                personArr[j] = personArr[j+1];
            }
            personArrSize--;
            numLibrarian--;
            toMenu();
        }
    }
    if(!found){
        cout << "You entered invalid ID. Please try again." << endl;
        deleteAdmin();
    }
}

void Library::viewAllLibrarians(){
    cout << "-------------View all librarians-------------- " << endl;
    for(int i = 0; i < personArrSize; i++){
        if(personArr[i]->getRole() == "librarian"){
            personArr[i]->printInfo();
            cout << endl;
        }
    }
    system("pause");
}

void Library::viewAllUsers(){
    cout << "-------------View all users-------------- " << endl;
    for(int i = 0; i < personArrSize; i++){
        if(personArr[i]->getRole() == "student" || personArr[i]->getRole() == "faculty"){
            personArr[i]->printInfo();
            cout << endl;
        }
    }
    system("pause");
}

void Library::viewAllAvailableBooks(){
    cout << "Available Book" << endl;
    for(int i = 0; i < bookArrSize; i++){
        if(bookArr[i]->available == true){
            cout << "Index           : " << bookArr[i]->index << endl;
            cout << "Title           : " << bookArr[i]->title << endl;
            cout << "Author          : " <<bookArr[i]->authorName << endl;
            cout << "Publisher       : " <<bookArr[i]->publisher << endl;
            cout << "Publishing Year : " <<bookArr[i]->publishingYear << endl;
            cout << endl;
        }
    }
    system("pause");
}

void Library::viewAllBooks(){
    cout << "All Books' Information" << endl;
    for(int i = 0; i < bookArrSize; i++){
        cout << "Index           : " << bookArr[i]->index << endl;
        cout << "Title           : " << bookArr[i]->title << endl;
        cout << "Author          : " << bookArr[i]->authorName << endl;
        cout << "Publisher       : " << bookArr[i]->publisher << endl;
        cout << "Publishing Year : " << bookArr[i]->publishingYear << endl;
        cout << "Borrower        : " << bookArr[i]->borrowerName << endl;
        cout << "Start Date      : " << bookArr[i]->startDate << endl;
        cout << "Expiration Date : " << bookArr[i]->expirationDate << endl;
        cout << "Overdue Charge  : " << bookArr[i]->overdueCharge << endl;        
        cout << endl;
    }
    system("pause");
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

        }
        else if(userPtr->getRole() == "librarian"){
            cout << "Signing in as Librarian..." << endl;

        }
        else if(userPtr->getRole() == "student"){
            cout << "Signing in as Student..." << endl;

        }
        else if(userPtr->getRole() == "faculty"){
            cout << "Signing in as Faculty..." << endl;

        }
        toMenu();
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
    cout << "||   5 - Quit                               ||" << endl;
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
    else if(inputNum == 5){
        cout << "Exiting program..." << endl;
        Sleep(2000);
        exit(0);
    }
    else{
        cout << "Invalid role. Please enter 1 - 5 only." << endl;
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
        getline(ifs, book1->startDate); 
        getline(ifs, book1->expirationDate);  
        ifs >> book1->overdueCharge;
        if(book1->borrowerName == "none"){
            book1->available = true;
        }
        else{
            book1->available = false;
        }
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
        ofs << bookArr[i]->startDate << endl;
        ofs << bookArr[i]->expirationDate << endl;
        ofs << bookArr[i]->overdueCharge << endl;        
        ofs << endl;
    }
    ofs.close();
}

string Library::getCurrentTime(){
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(today);
    struct tm* now = localtime(&t);
    int year = now->tm_year + 1900; // years since 1900
    int month = now->tm_mon + 1; // months since January [0-11]
    int day = now->tm_mday; // day of the month [1-31]
    return to_string(month) + '-' + to_string(day) + '-' + to_string(year);
}

string Library::getExpirationTime(){
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(today);
    struct tm* now = localtime(&t);
    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;
    return to_string(month + 1) + '-' + to_string(day) + '-' + to_string(year);
}