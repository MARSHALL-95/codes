#include <iostream>
#include <string>

using namespace std;

// 1. Define the Class
class Book {
public:
    // Attributes (Data)
    string title;
    string author;
    string isbn;

    // Member Function to get details from the user
    void getDetails() {
        cout << "Enter Book Title: ";
        getline(cin, title); 
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter ISBN Number: ";
        getline(cin, isbn);
    }

    // Member Function to show the details
    void displayDetails() {
        cout << "\n--- Book Information ---" << endl;
        cout << "Title:  " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN:   " << isbn << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    // 2. Create an Object of the class
    Book myBook;

    // 3. Call the functions
    cout << "Please enter the book info below:" << endl;
    myBook.getDetails();
    myBook.displayDetails();

    return 0;
}
