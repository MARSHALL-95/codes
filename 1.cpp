#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    int carID;
    string make;
    string model;
    int year;
    double rentalPrice;
    bool isAvailable;

    // Function to set car details
    void inputDetails() {
        cout << "Enter Car ID: ";
        cin >> carID;
        cin.ignore();
        cout << "Enter Make (e.g., Toyota): ";
        getline(cin, make);
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Rental Price Per Day: ";
        cin >> rentalPrice;
        isAvailable = true; // New cars are available by default
        cout << "Car added successfully!\n" << endl;
    }

    // Function to show car info if it's available
    void displayIfAvailable() {
        if (isAvailable) {
            cout << "ID: " << carID << " | " << year << " " << make << " " << model 
                 << " | Price: £" << rentalPrice << "/day" << endl;
        }
    }

    // Function to handle the rental process
    void rent() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Success! You have rented the " << make << " " << model << "." << endl;
        } else {
            cout << "Sorry, this car is already rented out." << endl;
        }
    }
};

int main() {
    Car fleet[3]; // An array of 3 Car objects
    int choice;

    // 1. Input data for all cars
    for (int i = 0; i < 3; i++) {
        cout << "--- Entering details for Car " << (i + 1) << " ---" << endl;
        fleet[i].inputDetails();
    }

    // 2. Simple Menu
    do {
        cout << "\n--- Car Rental System ---" << endl;
        cout << "1. Display Available Cars" << endl;
        cout << "2. Rent a Car by ID" << endl;
        cout << "3. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nAvailable Cars:" << endl;
            for (int i = 0; i < 3; i++) {
                fleet[i].displayIfAvailable();
            }
        } 
        else if (choice == 2) {
            int searchID;
            bool found = false;
            cout << "Enter the Car ID you want to rent: ";
            cin >> searchID;

            for (int i = 0; i < 3; i++) {
                if (fleet[i].carID == searchID) {
                    fleet[i].rent();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Car ID not found." << endl;
        }

    } while (choice != 3);

    return 0;
}
