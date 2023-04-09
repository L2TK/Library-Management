#pragma once
#include "Person.h"
#include "Book.h"

class User: public Person{
protected:
    string* booksBorrowed;
    int numBooksBorrowed;
    int lateFee;
    int availableSlot;
    int maxNumBooks;

public:
    User();
    void setNumBooksBorrowed(int i){ numBooksBorrowed = i; }
    void setLateFee(int _lateFee){ lateFee = _lateFee; }
    void setMaxNumBooks(int o){ maxNumBooks = o; }

    int getNumBookBorrowed(){ return numBooksBorrowed; }
    int getLateFee(){ return lateFee; }
    string* getBookBorrowed(){ return booksBorrowed; }

    virtual string getRole() const = 0;
    void executeMenu();
    void addBook(string);
    void borrowBooks();
    void returnBook();

};

User::User():Person(){
    numBooksBorrowed = 0;
    lateFee = 0;
    availableSlot = 0;
}

void User::borrowBooks(){

}

void User::returnBook(){

}

void User::addBook(string bookIndex){
    booksBorrowed[numBooksBorrowed] = bookIndex;
}

void User::executeMenu(){
    cout << "Hi, I'm " << getRole() << endl;
}