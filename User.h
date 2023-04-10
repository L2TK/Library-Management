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
    void setLateFee(int _lateFee){ lateFee = _lateFee; }
    void setMaxNumBooks(int o){ maxNumBooks = o; }

    int getLateFee(){ return lateFee; }

    void addBook(string);
    void borrowBooks();
    void returnBook();

    int getNumBookBorrowed(){ return numBooksBorrowed; }
    void setNumBooksBorrowed(int i) override{ numBooksBorrowed = i; }
    string* getBookBorrowed() override{ return booksBorrowed; }
    void executeMenu() override;
    virtual string getRole() const = 0;

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