// Create a class called Number has one data member of type integer. There two member
// function Setvalue( ) which will set the value of data member and show( ) to display the
// value. Drive a class HexType, DecimalType and OctType from base class which redefined
// the show() will display the value of data member of base class in respective number base.
#include <iostream>
#include <iomanip> // For std::hex, std::oct, and std::dec
using namespace std;

// Base class Number
class Number {
protected:
    int value;

public:
    void SetValue(int v) {
        value = v;
    }

    virtual void Show() const {
        cout << "Value: " << value << endl;
    }
};

// Derived class HexType
class HexType : public Number {
public:
    void Show() const override {
        cout << "Hexadecimal: " << hex << value << endl;
    }
};

// Derived class DecimalType
class DecimalType : public Number {
public:
    void Show() const override {
        cout << "Decimal: " << dec << value << endl;
    }
};

// Derived class OctType
class OctType : public Number {
public:
    void Show() const override {
        cout << "Octal: " << oct << value << endl;
    }
};

int main() {
    Number num;
    HexType hexNum;
    DecimalType decNum;
    OctType octNum;

    int input;
    cout << "Enter an integer value: ";
    cin >> input;

    num.SetValue(input);
    hexNum.SetValue(input);
    decNum.SetValue(input);
    octNum.SetValue(input);

    cout << "\nBase class Number:" << endl;
    num.Show();

    cout << "\nDerived class HexType:" << endl;
    hexNum.Show();

    cout << "\nDerived class DecimalType:" << endl;
    decNum.Show();

    cout << "\nDerived class OctType:" << endl;
    octNum.Show();

    return 0;
}
