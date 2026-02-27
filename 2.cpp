#include <iostream>
#include <string>

using namespace std;

// 1. Define the Class
class CarPark {
public:
    // Data Members (Attributes)
    string regNumber;
    double chargePerHour;
    int parkingDuration; // In hours

    // Member Function to set the data
    void setData() {
        cout << "Enter Car Registration Number: ";
        getline(cin, regNumber);
        cout << "Enter Charge Per Hour: ";
        cin >> chargePerHour;
        cout << "Enter Parking Duration (in hours): ";
        cin >> parkingDuration;
        
        // Clearing the buffer so the next input works fine
        cin.ignore();
    }

    // Member Function to calculate and display details
    void displayCharges() {
        // Simple calculation: Duration * Rate
        double totalCharge = parkingDuration * chargePerHour;

        cout << "\n--- Parking Receipt ---" << endl;
        cout << "Car Reg No:     " << regNumber << endl;
        cout << "Time Parked:    " << parkingDuration << " hours" << endl;
        cout << "Rate:           " << chargePerHour << " per hour" << endl;
        cout << "Total Bill:     " << totalCharge << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    // 2. Create the Object
    CarPark myCar;

    // 3. Use the functions
    myCar.setData();
    myCar.displayCharges();

    return 0;
}
