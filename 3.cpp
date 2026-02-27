#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    int rollNumber;
    string name;
    float marks[5];
    float average;
    char grade;

    // Function to input details and validate marks
    void inputDetails() {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);

        float sum = 0;
        for (int i = 0; i < 5; i++) {
            float m;
            do {
                cout << "Enter marks for Subject " << (i + 1) << " (0-100): ";
                cin >> m;
                if (m < 0 || m > 100) {
                    cout << "Invalid marks! Please enter between 0 and 100." << endl;
                }
            } while (m < 0 || m > 100);
            
            marks[i] = m;
            sum += m;
        }
        average = sum / 5.0;
        calculateGrade();
    }

    // Function to determine grade based on average
    void calculateGrade() {
        if (average >= 90) grade = 'A';
        else if (average >= 75) grade = 'B';
        else if (average >= 50) grade = 'C';
        else grade = 'F';
    }

    // Function to display student report
    void displayDetails() {
        cout << "\nRoll No: " << rollNumber << " | Name: " << name;
        cout << " | Avg: " << average << "% | Grade: " << grade << endl;
    }
};

int main() {
    int n;
    cout << "How many students do you want to enter? ";
    cin >> n;

    // Create an array of Student objects
    Student classroom[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Entering data for Student " << (i + 1) << " ---" << endl;
        classroom[i].inputDetails();
    }

    cout << "\n======= STUDENT REPORT CARD =======";
    for (int i = 0; i < n; i++) {
        classroom[i].displayDetails();
    }

    return 0;
}
