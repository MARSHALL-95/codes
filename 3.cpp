#include <iostream>
#include <string>

using namespace std;

class BankAccount {
public:
    string accountNumber;
    string accountHolderName;
    double balance;

    // 1. First Constructor (Starts with 0 balance)
    BankAccount(string accNum, string name) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = 0.0; 
        cout << "Account created for " << name << " with 0 balance." << endl;
    }

    // 2. Second Constructor (Starts with an initial balance)
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialBalance;
        cout << "Account created for " << name << " with initial balance: " << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds! You only have " << balance << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << " | Remaining Balance: " << balance << endl;
        }
    }

    // Function to show balance
    void displayBalance() {
        cout << "Account: " << accountNumber << " | Holder: " << accountHolderName 
             << " | Current Balance: " << balance << endl;
    }
};

int main() {
    // Creating object using the FIRST constructor (0 balance)
    BankAccount user1("ACC123", "Buddy");
    user1.deposit(500);
    user1.displayBalance();

    cout << "-----------------------------------" << endl;

    // Creating object using the SECOND constructor (Initial balance provided)
    BankAccount user2("ACC456", "Alex", 1000.0);
    user2.withdraw(200);
    user2.displayBalance();

    return 0;
}
