#include <iostream>
#include <cmath> // Required for sqrt and pow

using namespace std;

class Point {
public:
    double x, y;

    // 1. Default Constructor (Sets point to origin 0,0)
    Point() {
        x = 0;
        y = 0;
    }

    // 2. Parameterized Constructor (Sets point to specific coordinates)
    Point(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    // Function to let the user manually set coordinates
    void getCoordinates() {
        cout << "Enter X coordinate: ";
        cin >> x;
        cout << "Enter Y coordinate: ";
        cin >> y;
    }

    // Function to calculate distance between THIS point and ANOTHER point object
    double calculateDistance(Point otherPoint) {
        // Using the Distance Formula
        return sqrt(pow(otherPoint.x - x, 2) + pow(otherPoint.y - y, 2));
    }

    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    // Creating Point 1 using the Default Constructor (0,0)
    Point p1; 
    
    // Creating Point 2 using the Parameterized Constructor (e.g., 3,4)
    Point p2(3.0, 4.0);

    cout << "Point 1 is at the origin: ";
    p1.display();
    cout << "\nPoint 2 is initialized at: ";
    p2.display();

    // Let's create a third point and ask the user for input
    Point p3;
    cout << "\n\nLet's set a custom Point 3:" << endl;
    p3.getCoordinates();

    // Calculating distance between Point 1 (0,0) and Point 3 (User input)
    double distance = p1.calculateDistance(p3);

    cout << "\nThe distance between ";
    p1.display();
    cout << " and ";
    p3.display();
    cout << " is: " << distance << endl;

    return 0;
}
