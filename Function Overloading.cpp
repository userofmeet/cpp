// Create a class Telephone Directory which has following information: Telephone number,
// Name of subscriber and Address. Write a member function to perform the following tasks:
// 1. To input the details of subscriber
// 2. To print the details of subscriber according to inquiry generated from user. Inquiry is
// either based on telephone number or name of subscriber.
// 3. To modify the details of a particular subscriber, Modification is based on name of
// subscriber, if more than one match is found; it has to ask another field. Based on
// second field, it will modify the details.
// • Write a program for 10 subscribers, which will create the menu for following tasks:
// a) Enter the details of subscriber
// b) Inquiry for subscriber
// c) Modify the detail of subscriber
#include <iostream>
#include <string>
using namespace std;

class Subscriber {
    string name;
    string address;
    string telephone_number;

public:
    void inputDetails() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter telephone number: ";
        getline(cin, telephone_number);
    }

    void displayDetails() const {
        cout << "Name: " << name << ", Address: " << address 
             << ", Telephone Number: " << telephone_number << endl;
    }

    string getName() const {
        return name;
    }

    string getTelephoneNumber() const {
        return telephone_number;
    }

    void modifyDetails() {
        cout << "Modify address: ";
        getline(cin, address);
        cout << "Modify telephone number: ";
        getline(cin, telephone_number);
    }
};

class TelephoneDirectory {
    Subscriber subscribers[10];

public:
    void inputSubscribers() {
        for (int i = 0; i < 10; i++) {
            cout << "Enter details for subscriber " << i + 1 << endl;
            subscribers[i].inputDetails();
        }
    }

    void inquireSubscriber() {
        int choice;
        cout << "Search by:\n1. Telephone Number\n2. Name\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string telephone;
            cout << "Enter telephone number: ";
            getline(cin, telephone);

            for (int i = 0; i < 10; i++) {
                if (subscribers[i].getTelephoneNumber() == telephone) {
                    subscribers[i].displayDetails();
                    return;
                }
            }
            cout << "Subscriber not found." << endl;
        } else if (choice == 2) {
            string name;
            cout << "Enter name: ";
            getline(cin, name);

            for (int i = 0; i < 10; i++) {
                if (subscribers[i].getName() == name) {
                    subscribers[i].displayDetails();
                    return;
                }
            }
            cout << "Subscriber not found." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    void modifySubscriber() {
        string name;
        cout << "Enter the name of the subscriber to modify: ";
        cin.ignore();
        getline(cin, name);

        int count = 0;
        int foundIndex = -1;

        for (int i = 0; i < 10; i++) {
            if (subscribers[i].getName() == name) {
                count++;
                foundIndex = i;
            }
        }

        if (count == 1) {
            subscribers[foundIndex].modifyDetails();
        } else if (count > 1) {
            string telephone;
            cout << "Multiple matches found. Enter the telephone number: ";
            getline(cin, telephone);

            for (int i = 0; i < 10; i++) {
                if (subscribers[i].getName() == name && subscribers[i].getTelephoneNumber() == telephone) {
                    subscribers[i].modifyDetails();
                    return;
                }
            }
            cout << "No matching subscriber found with given name and telephone number." << endl;
        } else {
            cout << "No subscriber found with that name." << endl;
        }
    }
};

int main() {
    TelephoneDirectory directory;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter the details of subscribers\n";
        cout << "2. Inquiry for subscriber\n";
        cout << "3. Modify the detail of subscriber\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                directory.inputSubscribers();
                break;
            case 2:
                directory.inquireSubscriber();
                break;
            case 3:
                directory.modifySubscriber();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}
