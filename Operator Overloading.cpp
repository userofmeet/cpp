// Imagine an experiment in which you have to observe the performance of charging of a
// capacitor. You have to give the charging voltage, the value of the capacitance and resistance
// as inputs. The output should be a table showing the voltage across the capacitor with respect
// to time. Remember that the capacitor will be completely charged at time equal to the 5 times
// of time constant τ. So time should be varied from 0 till 5τ in suitable steps. Design a suitable
// class Experiment having appropriate functions to input the data, calculate the voltage and
// display the output.
// Use the class definition described above for the Distance class. Overload -- operator to 
// perform following operation in which it subtracts 1 from meters member and check that
// distance should not be negative.
// dist1--;
// Function should allow to use the result in other operation like dist2 = dist1--; and also write
// modified function which differentiate postfix and prefix notation.
#include <iostream>
#include <cmath>
using namespace std;

// Class for the capacitor charging experiment
class Experiment {
    float voltage_source;
    float resistance;
    float capacitance;
    float time_constant;

public:
    // Function to input data
    void inputData() {
        cout << "Enter the source voltage (V): ";
        cin >> voltage_source;
        cout << "Enter the resistance (R) in ohms: ";
        cin >> resistance;
        cout << "Enter the capacitance (C) in farads: ";
        cin >> capacitance;
        time_constant = resistance * capacitance;
    }

    // Function to calculate the voltage across the capacitor at a given time
    float calculateVoltage(float time) {
        return voltage_source * (1 - exp(-time / time_constant));
    }

    // Function to display the results
    void displayResults() {
        cout << "\nTime (s)\tVoltage across capacitor (V)" << endl;
        for (float t = 0; t <= 5 * time_constant; t += time_constant / 10) {
            cout << t << "\t\t" << calculateVoltage(t) << endl;
        }
    }
};

// Class for handling Distance with overloading of -- operator
class Distance {
    int meters;

public:
    // Default and parameterized constructor
    Distance() : meters(0) {}
    Distance(int m) : meters(m) {}

    // Overloading the prefix -- operator
    Distance& operator--() {
        if (meters > 0) {
            --meters;
        } else {
            meters = 0;
        }
        return *this;
    }

    // Overloading the postfix -- operator
    Distance operator--(int) {
        Distance temp = *this;
        if (meters > 0) {
            meters--;
        } else {
            meters = 0;
        }
        return temp;
    }

    // Function to display the current value of meters
    void display() const {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

// Main function to demonstrate both classes
int main() {
    // Part 1: Capacitor charging experiment
    Experiment exp;
    exp.inputData();
    exp.displayResults();

    // Part 2: Distance class with overloaded -- operator
    Distance dist1(5), dist2;

    cout << "\nInitial distance of dist1: ";
    dist1.display();

    // Prefix operation
    --dist1;
    cout << "After prefix --dist1: ";
    dist1.display();

    // Postfix operation
    dist2 = dist1--;
    cout << "After postfix dist2 = dist1--: " << endl;
    cout << "dist1: ";
    dist1.display();
    cout << "dist2: ";
    dist2.display();

    return 0;
}
