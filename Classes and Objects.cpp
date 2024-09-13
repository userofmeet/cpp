// Imagine an experiment in which you have to observe the performance of charging of a
// capacitor. You have to give the charging voltage, the value of the capacitance and resistance
// as inputs. The output should be a table showing the voltage across the capacitor with respect
// to time. Remember that the capacitor will be completely charged at time equal to the 5 times
// of time constant τ. So time should be varied from 0 till 5τ in suitable steps. Design a suitable
// class Experiment having appropriate functions to input the data, calculate the voltage and
// display the output.
#include <iostream>
#include <cmath>
using namespace std;

class Experiment {
    float voltage_source;
    float resistance;
    float capacitance;
    float time_constant;
    
public:
    void inputData() {
        cout << "Enter the source voltage (V): ";
        cin >> voltage_source;
        cout << "Enter the resistance (R) in ohms: ";
        cin >> resistance;
        cout << "Enter the capacitance (C) in farads: ";
        cin >> capacitance;
        time_constant = resistance * capacitance;
    }

    float calculateVoltage(float time) {
        return voltage_source * (1 - exp(-time / time_constant));
    }

    void displayResults() {
        cout << "\nTime (s)\tVoltage across capacitor (V)" << endl;
        for (float t = 0; t <= 5 * time_constant; t += time_constant / 10) {
            cout << t << "\t\t" << calculateVoltage(t) << endl;
        }
    }
};

int main() {
    Experiment exp;
    exp.inputData();
    exp.displayResults();
    return 0;
}
