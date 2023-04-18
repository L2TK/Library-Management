#include <string>
#include <iostream>
#include "Library.h"
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    Library l1;
    l1.loadBooks();
    l1.loadPerson();

    l1.logIn();
    return 0;
}