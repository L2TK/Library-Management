#pragma once
#include "Person.h"

class User: public Person{
protected:
    Book** booksBorrowed; ; //array of borrowed books
    int numBooksBorrowed;
    int lateFee;
    int availableSlot;
    int maxNumBooks;


public:
    User();
    void setLateFee(int _lateFee) override{ lateFee = _lateFee; } //set late fee
    void setMaxNumBooks(int o){ maxNumBooks = o; }

    int getLateFee() override { return lateFee; } 

    int getAvailableSlot()override{ return availableSlot; } //return number of available slots
    int getNumBookBorrowed()override{ return numBooksBorrowed; }
    void setNumBooksBorrowed(int ) override;
    Book** getBookBorrowed() override{ return booksBorrowed; }
    virtual string getRole() const = 0; //pure virtual function that is overridden in Faculty and Student
    void printInfo() const override; //print info of user such as name, number of books

    void viewBorrowingBooks() override;
    void borrowBook(Book*) override;
    bool returnBook(string ) override;
    
    void payLateFee(string )override;
    void viewLateFee() override;
};

User::User():Person(){
    numBooksBorrowed = 0;
    lateFee = 0;
}

void User::borrowBook(Book* book){
    booksBorrowed[numBooksBorrowed] = book;
    numBooksBorrowed++;
    availableSlot--;
}

bool User::returnBook(string index){
    for(int i = 0; i < numBooksBorrowed; i++){
        if(booksBorrowed[i]->index == index){
            for(int j = i; j < numBooksBorrowed; j++){
                booksBorrowed[j] = booksBorrowed[j+1];
            }
            if(lateFee > 0){
                cout << "You have late fee. Please pay for it before borrowing more books." << endl;
            }
            numBooksBorrowed--;
            availableSlot++;
            cout << "Book returned." << endl;
            return true;
        }
    }
    return false;
}

void User::printInfo() const {
    Person::printInfo();
    cout << "Book borrowing: " <<  numBooksBorrowed << endl;
    for(int i = 0; i < numBooksBorrowed; i++){
        cout << "   Book's index: " << booksBorrowed[i]->index << endl;
    }
    cout << "Late fee: " << lateFee << endl;
}


void User::viewBorrowingBooks(){
    cout << "----------------------------------------------" << endl;
    cout << "Numbers of books borrowing: " << numBooksBorrowed << endl;
    cout << "Available Slot: " << availableSlot << endl;
    for(int i = 0; i < numBooksBorrowed; i++){
        cout << "Index           : " << booksBorrowed[i]->index << endl;
        cout << "Title           : " << booksBorrowed[i]->title << endl;
        cout << "Author          : " << booksBorrowed[i]->authorName << endl;
        cout << "Publisher       : " << booksBorrowed[i]->publisher << endl;
        cout << "Publishing Year : " << booksBorrowed[i]->publishingYear << endl;
        cout << "Borrower        : " << booksBorrowed[i]->borrowerName << endl;
        cout << "Start Date      : " << to_string(booksBorrowed[i]->startMonth) 
                                        + "-" + to_string(booksBorrowed[i]->startDay)  
                                        + "-" + to_string(booksBorrowed[i]->startYear) << endl;
        cout << "Expiration Date : " << to_string(booksBorrowed[i]->expirationMonth) 
                                        + "-" + to_string(booksBorrowed[i]->expirationDay) 
                                        + "-" + to_string(booksBorrowed[i]->expirationYear) << endl;
        cout << "Overdue Charge  : " << booksBorrowed[i]->overdueCharge << endl;        
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}

void User::setNumBooksBorrowed(int n){
    numBooksBorrowed = n;
    availableSlot = maxNumBooks - n;
}

void User::payLateFee(string index){
    for(int i = 0; i < numBooksBorrowed; i++){
        if(booksBorrowed[i]->index == index){
            lateFee = lateFee - booksBorrowed[i]->overdueCharge;
        }
    }
    cout << "Late fee paid." << endl;
    cout << "Your current late fee is $" << lateFee << endl;
}

void User::viewLateFee(){
    cout << "---Viewing late fee---" << endl;
    for(int i = 0; i < numBooksBorrowed; i++){
        if(booksBorrowed[i]->overdueCharge > 0){
            cout << i+1 << ". " << booksBorrowed[i]->index << " - " << booksBorrowed[i]->title
                    << " - $" << booksBorrowed[i]->overdueCharge <<endl;
        }
    }
    cout << "Your current late fee is $" << lateFee << endl;
    system("Pause");
}