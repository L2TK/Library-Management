#include <string>
using namespace std;
struct Book{
    string index;
    string title;
    string authorName;
    string publisher;
    int publishingYear;
    string borrowerName = "none";
    int overdueCharge = 0;
    bool available = true;
 //default information when a book object is created and changed when someone borrows the books
    int startMonth = 0;
    int startDay = 0;
    int startYear = 0;
    int expirationMonth = 0;
    int expirationDay = 0;
    int expirationYear = 0;
};
