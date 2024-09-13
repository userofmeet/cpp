// Create two classes Degree and Radian to store two angles in degree and in radian
// respectively. Assign object of one class with other. Do appropriate conversion for this
// assignment. Declare, perform operation and show the results in main. Show both possible
// way of conversion.
#include <iostream>
#include <cmath> // For M_PI constant
using namespace std;

class Radian; // Forward declaration

class Degree {
    float angle_in_degrees;

public:
    Degree(float angle = 0) : angle_in_degrees(angle) {}

    void display() const {
        cout << "Angle in degrees: " << angle_in_degrees << "°" << endl;
    }

    // Conversion constructor from Radian to Degree
    Degree(const Radian& rad);

    // Conversion operator to Radian
    operator Radian() const;
};

class Radian {
    float angle_in_radians;

public:
    Radian(float angle = 0) : angle_in_radians(angle) {}

    void display() const {
        cout << "Angle in radians: " << angle_in_radians << " rad" << endl;
    }

    // Conversion constructor from Degree to Radian
    Radian(const Degree& deg) : angle_in_radians(deg.angle_in_degrees * M_PI / 180) {}

    // Conversion operator to Degree
    operator Degree() const {
        return Degree(angle_in_radians * 180 / M_PI);
    }
};

// Definition of the conversion constructor for Degree
Degree::Degree(const Radian& rad) : angle_in_degrees(rad.angle_in_radians * 180 / M_PI) {}

// Definition of the conversion operator to Radian
Degree::operator Radian() const {
    return Radian(angle_in_degrees * M_PI / 180);
}

int main() {
    // Create Degree and Radian objects
    Degree deg1(45); // 45 degrees
    Radian rad1(M_PI / 4); // π/4 radians

    // Display initial values
    cout << "Initial values:" << endl;
    deg1.display();
    rad1.display();

    // Convert and assign
    Radian rad2 = deg1; // Conversion from Degree to Radian
    Degree deg2 = rad1; // Conversion from Radian to Degree

    // Display results after conversion
    cout << "\nAfter conversion:" << endl;
    rad2.display();
    deg2.display();

    // Perform operations
    Degree deg3 = rad2; // Convert back to Degree
    Radian rad3 = deg2; // Convert back to Radian

    // Display results of operations
    cout << "\nAfter conversion back:" << endl;
    deg3.display();
    rad3.display();

    return 0;
}
