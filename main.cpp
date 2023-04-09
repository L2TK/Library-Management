#include <string>
#include <iostream>
#include "Library.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    Library l1;
    l1.loadAdmins();
    l1.loadUsers();
    l1.loadBooks();

    l1.saveAdmins();
    l1.saveUsers();
    l1.saveBooks();
    l1.logIn();
    return 0;
}