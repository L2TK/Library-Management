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

    void addBook(string);
public:
    User();
    void setLateFee(int _lateFee){ lateFee = _lateFee; }
    void setMaxNumBooks(int o){ maxNumBooks = o; }

    int getLateFee(){ return lateFee; }

    int getAvailableSlot(){ return availableSlot; }
    int getNumBookBorrowed(){ return numBooksBorrowed; }
    void setNumBooksBorrowed(int i) override{ numBooksBorrowed = i; }
    string* getBookBorrowed() override{ return booksBorrowed; }
    virtual string getRole() const = 0;
    void printInfo() const override;
};

User::User():Person(){
    numBooksBorrowed = 0;
    lateFee = 0;
}

void User::addBook(string bookIndex){
    booksBorrowed[numBooksBorrowed] = bookIndex;
    numBooksBorrowed++;
    availableSlot = maxNumBooks - numBooksBorrowed;
}

void User::printInfo() const {
    Person::printInfo();
    cout << "Book borrowing:" <<  numBooksBorrowed << endl;
    for(int i = 0; i < numBooksBorrowed; i++){
        cout << "   ID: " << booksBorrowed[i] << endl;
    }
    cout << "Late fee: " << lateFee << endl;
}
