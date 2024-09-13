// Create a class Patient which has the following content: Name of Patient, Age, Sex, Ward
// Number, and Bed Number.Each ward has 2 beds, both of which should be filled before moving
// on to the next ward. Ward number and Bed number should be automatically initialized using the
// default constructor for each new patient. Use another constructor to initialize them using the
// explicit values passed as arguments.
// Write a member function to do following:
// a) To input details of patient
// b) To modify a patient’s detail
// c) To display patient’s detail
// Write a program which creates an array of 5 patients. Also creates the menu which asks the user
// to choose from following tasks:
// Enter the patient detail
// Change the patient detail
// Display the patient detail
// Sort the array of patients according to their ages.
#include <iostream>
#include <string>
using namespace std;

class Patient {
    string name;
    int age;
    char sex;
    int ward_no;
    int bed_no;
    static int next_ward;
    static int next_bed;

public:
    Patient() {
        ward_no = next_ward;
        bed_no = next_bed;
        next_bed++;
        if (next_bed > 2) {
            next_bed = 1;
            next_ward++;
        }
    }

    Patient(string n, int a, char s, int w, int b) : name(n), age(a), sex(s), ward_no(w), bed_no(b) {}

    void inputDetails() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter sex (M/F): ";
        cin >> sex;
    }

    void modifyDetails() {
        cout << "Modify name: ";
        cin >> name;
        cout << "Modify age: ";
        cin >> age;
        cout << "Modify sex (M/F): ";
        cin >> sex;
    }

    void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << ", Sex: " << sex 
             << ", Ward No: " << ward_no << ", Bed No: " << bed_no << endl;
    }

    int getAge() const {
        return age;
    }
    
    static void reset() {
        next_ward = 1;
        next_bed = 1;
    }
};

int Patient::next_ward = 1;
int Patient::next_bed = 1;

void sortByAge(Patient patients[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (patients[j].getAge() > patients[j+1].getAge()) {
                Patient temp = patients[j];
                patients[j] = patients[j+1];
                patients[j+1] = temp;
            }
        }
    }
}

int main() {
    Patient patients[5];
    int choice, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter patient details\n";
        cout << "2. Change patient details\n";
        cout << "3. Display patient details\n";
        cout << "4. Sort patients by age\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < 5; i++) {
                    cout << "Enter details for patient " << i + 1 << endl;
                    patients[i].inputDetails();
                }
                break;
            case 2:
                cout << "Enter patient number to modify (1-5): ";
                cin >> index;
                if (index >= 1 && index <= 5) {
                    patients[index - 1].modifyDetails();
                } else {
                    cout << "Invalid patient number." << endl;
                }
                break;
            case 3:
                for (int i = 0; i < 5; i++) {
                    cout << "Details of patient " << i + 1 << ":" << endl;
                    patients[i].displayDetails();
                }
                break;
            case 4:
                sortByAge(patients, 5);
                cout << "Patients sorted by age." << endl;
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
