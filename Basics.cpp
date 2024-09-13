// Write a program to store student’s data; name, roll_no, and marks of three subjects
// at run time and display the whole data base according to their merits.
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll_no;
    int marks[3];
    int total_marks;
};

void calculateTotalMarks(Student &s) {
    s.total_marks = s.marks[0] + s.marks[1] + s.marks[2];
}

void sortByMerit(Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].total_marks < students[j+1].total_marks) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    Student students[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << i+1 << ": ";
        cin >> students[i].name;
        cout << "Enter roll number of student " << i+1 << ": ";
        cin >> students[i].roll_no;
        cout << "Enter marks of 3 subjects for student " << i+1 << ": ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].marks[j];
        }
        calculateTotalMarks(students[i]);
    }
    
    sortByMerit(students, n);
    
    cout << "\nSorted list according to merit:\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << students[i].name << ", Roll No: " << students[i].roll_no << ", Total Marks: " << students[i].total_marks << endl;
    }
    
    return 0;
}
