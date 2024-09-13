// Design a class Student with data members: Name, ID and Semester. Derive another class
// Sessional with an array of 5 integers to store sessional marks of 5 subjects. Derive a class
// External with an array of 5 integers to store the marks of 5 subjects. Write suitable member
// functions to initialize the data members of each class and produce the marksheet of the
// student containing the marks of sessional and external examination with total marks as well.
#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;
    int semester;

public:
    void initializeStudent(const string& studentName, int studentID, int studentSemester) {
        name = studentName;
        id = studentID;
        semester = studentSemester;
    }

    void displayStudentInfo() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Semester: " << semester << endl;
    }
};

class Sessional : public Student {
protected:
    int sessionalMarks[5];

public:
    void initializeSessionalMarks(const int marks[5]) {
        for (int i = 0; i < 5; ++i) {
            sessionalMarks[i] = marks[i];
        }
    }

    void displaySessionalMarks() const {
        cout << "Sessional Marks: ";
        for (int i = 0; i < 5; ++i) {
            cout << sessionalMarks[i] << " ";
        }
        cout << endl;
    }
};

class External : public Sessional {
    int externalMarks[5];

public:
    void initializeExternalMarks(const int marks[5]) {
        for (int i = 0; i < 5; ++i) {
            externalMarks[i] = marks[i];
        }
    }

    void displayMarksSheet() const {
        int totalMarks = 0;
        cout << "Marks Sheet:" << endl;
        displayStudentInfo();
        displaySessionalMarks();
        cout << "External Marks: ";
        for (int i = 0; i < 5; ++i) {
            cout << externalMarks[i] << " ";
            totalMarks += sessionalMarks[i] + externalMarks[i];
        }
        cout << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main() {
    External student;
    string name;
    int id, semester;
    int sessionalMarks[5], externalMarks[5];

    // Input student information
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter semester: ";
    cin >> semester;

    student.initializeStudent(name, id, semester);

    // Input sessional marks
    cout << "Enter sessional marks for 5 subjects: ";
    for (int i = 0; i < 5; ++i) {
        cin >> sessionalMarks[i];
    }
    student.initializeSessionalMarks(sessionalMarks);

    // Input external marks
    cout << "Enter external marks for 5 subjects: ";
    for (int i = 0; i < 5; ++i) {
        cin >> externalMarks[i];
    }
    student.initializeExternalMarks(externalMarks);

    // Display marks sheet
    student.displayMarksSheet();

    return 0;
}


// What should be the total memory requirement for the object of class Z and External? How
// can it be verified in the program?
int main() {
    cout << "Size of Student: " << sizeof(Student) << " bytes" << endl;
    cout << "Size of Sessional: " << sizeof(Sessional) << " bytes" << endl;
    cout << "Size of External: " << sizeof(External) << " bytes" << endl;
    return 0;
}
