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

    // Function to input car details
    void inputDetails(int id) {
        carID = id;
        cin.ignore(); // Clear buffer
        cout << "Enter Make (e.g., Toyota): ";
        getline(cin, make);
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Rental Price: ";
        cin >> rentalPrice;
        isAvailable = true; // Default to available
        cout << "Car added successfully!\n";
    }

    // Function to display car if available
    void displayIfAvailable() {
        if (isAvailable) {
            cout << "ID: " << carID << " | " << year << " " << make << " " << model 
                 << " | Price: " << rentalPrice << "/day" << endl;
        }
    }

    // Function to mark car as rented
    void rentCar() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Rental successful! Drive safe.\n";
        } else {
            cout << "Sorry, this car is already rented.\n";
        }
    }
};

int main() {
    int totalCars = 3;
    Car fleet[3]; // Array of objects
    int choice;

    // Initial Input
    for (int i = 0; i < totalCars; i++) {
        cout << "Setting up Car #" << (i + 1) << endl;
        fleet[i].inputDetails(101 + i); // Giving them IDs 101, 102, etc.
    }

    do {
        cout << "\n--- Car Rental Menu ---\n";
        cout << "1. View Available Cars\n";
        cout << "2. Rent a Car\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nAvailable Fleet:\n";
            for (int i = 0; i < totalCars; i++) {
                fleet[i].displayIfAvailable();
            }
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Car ID to rent: ";
            cin >> id;
            bool found = false;
            for (int i = 0; i < totalCars; i++) {
                if (fleet[i].carID == id) {
                    fleet[i].rentCar();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Car ID not found.\n";
        }
    } while (choice != 3);

    return 0;
}
