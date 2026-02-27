#include <iostream>
#include <string>

using namespace std;

class Product {
public:
    int productID;
    string name;
    double price;

    // 1. Non-parameterized Constructor
    Product() {
        productID = 0;
        name = "Unknown";
        price = 0.0;
        cout << "Object created with default values." << endl;
    }

    // 2. Destructor
    ~Product() {
        cout << "Object destroyed for Product: " << name << endl;
    }

    // Function to input details
    void inputDetails() {
        cout << "Enter Product ID: ";
        cin >> productID;
        cin.ignore(); // Clear buffer for string input
        cout << "Enter Product Name: ";
        getline(cin, name);
        cout << "Enter Price: ";
        cin >> price;
    }

    // Function to calculate total cost
    void calculateTotal(int quantity) {
        double total = price * quantity;
        cout << "Total cost for " << quantity << " units: " << total << endl;
    }

    // Function to display details
    void displayProduct() {
        cout << "\n--- Product Info ---" << endl;
        cout << "ID:    " << productID << endl;
        cout << "Name:  " << name << endl;
        cout << "Price: " << price << endl;
        cout << "--------------------" << endl;
    }
};

int main() {
    // Creating the object (Constructor runs here)
    Product myItem;

    myItem.inputDetails();
    myItem.displayProduct();

    int qty;
    cout << "Enter quantity to purchase: ";
    cin >> qty;
    myItem.calculateTotal(qty);

    return 0; 
    // Destructor runs here automatically as the program ends
}
