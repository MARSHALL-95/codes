#include <iostream>
#include <string>

using namespace std;

class TNEB {
public:
    int ebNumber;
    string consumerName;
    string consumerType; // Domestic or Commercial
    int units;
    double billAmount;

    // Function to input details
    void getDetails() {
        cout << "Enter EB Number: ";
        cin >> ebNumber;
        cin.ignore();
        cout << "Enter Consumer Name: ";
        getline(cin, consumerName);
        cout << "Enter Consumer Type (D for Domestic / C for Commercial): ";
        getline(cin, consumerType);
        cout << "Enter Units Consumed: ";
        cin >> units;
        
        calculateBill(); // Calculate bill immediately after getting units
    }

    // Function to calculate bill based on Tariff Rules
    void calculateBill() {
        if (consumerType == "D" || consumerType == "d") {
            // Domestic Tariff (Lower rates)
            if (units <= 100) billAmount = units * 1.50;
            else if (units <= 200) billAmount = (100 * 1.50) + (units - 100) * 3.00;
            else billAmount = (100 * 1.50) + (100 * 3.00) + (units - 200) * 5.00;
        } 
        else {
            // Commercial Tariff (Higher rates)
            if (units <= 100) billAmount = units * 4.50;
            else billAmount = (100 * 4.50) + (units - 100) * 8.00;
        }
    }

    // Function to display the result
    void displayBill() {
        cout << "EB No: " << ebNumber << " | Name: " << consumerName 
             << " | Type: " << consumerType << " | Units: " << units 
             << " | Total: Rs." << billAmount << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of consumers: ";
    cin >> n;

    // Array of Objects
    TNEB consumers[100]; 

    for (int i = 0; i < n; i++) {
        cout << "\n--- Details for Consumer " << (i + 1) << " ---" << endl;
        consumers[i].getDetails();
    }

    cout << "\n========== GENERATED BILLS ==========" << endl;
    for (int i = 0; i < n; i++) {
        consumers[i].displayBill();
    }

    return 0;
}
