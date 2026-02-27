#include <iostream>

using namespace std;

class Distance {
public:
    int feet;
    int inches;

    // Parameterized Constructor
    Distance(int f, int i) {
        feet = f;
        inches = i;
    }

    // Function to add another distance to THIS one
    void addDistance(Distance d2) {
        int totalFeet = feet + d2.feet;
        int totalInches = inches + d2.inches;

        // Logic: Convert inches to feet if >= 12
        if (totalInches >= 12) {
            totalFeet += totalInches / 12; // Add the number of full feet
            totalInches = totalInches % 12; // Keep the remaining inches
        }

        cout << "\nTotal Distance: " << totalFeet << " feet, " << totalInches << " inches" << endl;
    }

    void display() {
        cout << feet << " feet, " << inches << " inches";
    }
};

int main() {
    // Initializing two distance objects
    Distance dist1(5, 8);  // 5' 8"
    Distance dist2(3, 6);  // 3' 6"

    cout << "Distance 1: ";
    dist1.display();
    cout << "\nDistance 2: ";
    dist2.display();

    // Add dist2 to dist1
    dist1.addDistance(dist2);

    return 0;
}
