#include <iostream>
#include <cstring> // Required for strlen and strcpy

using namespace std;

class MyString {
public:
    char str[100]; // Character array to store the string
    int length;    // Variable to store the length

    // 1. Default Constructor (Initializes as empty)
    MyString() {
        str[0] = '\0'; // The 'null terminator' marks the end of a string
        length = 0;
    }

    // 2. Parameterized Constructor (Initializes with user input)
    MyString(char inputStr[]) {
        strcpy(str, inputStr); // Copies the input into our class array
        length = strlen(str);  // Calculates the length automatically
    }

    // Member Function to compute/update length and display
    void display() {
        length = strlen(str); // Ensuring length is accurate
        cout << "String: " << str << endl;
        cout << "Length: " << length << " characters" << endl;
    }
};

int main() {
    // Using the Default Constructor
    MyString s1;
    cout << "S1 (Default):" << endl;
    s1.display();

    cout << "--------------------" << endl;

    // Using the Parameterized Constructor
    char myText[] = "Hello Buddy!";
    MyString s2(myText);
    cout << "S2 (Parameterized):" << endl;
    s2.display();

    return 0;
}
