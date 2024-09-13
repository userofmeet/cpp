// #include<iostream>
// using namespace std;
// class Dummy{
// private:
// int n;
// public:
// Dummy(){}
// Dummy(int m){
// n=m;
// }
// int divide(int a){
// if(a==0)
// throw a;
// cout<<”\n returning from divide”<<endl;
// return (n/a);
// }
// };
// int main( ){
// Dummy d1;
// int b,c;
// bool flag;
// d1=5;
// flag=true;
// while(flag){
// cout<<”\n enter b\n”;
// cin>>b;
// try{
// c=d1.divide(b);
// flag=false;
// }

// catch(int x){
// cout<<”attempt of division by zero\n”;
// cout<<”check your input again\n”;
// }

// }
// cout<<”\nans=”<<c<<endl;
// return 0;
// }
// MODIFICATION:
// 1. Understand the above program thoroughly and modify it in such a way that the user is given
// maximum three attempts of division to re execute the code after an attempt of division by
// zero. The program should exit otherwise.
// Hint: Use rethrowing of exception.

// EXERCISE:
// 1. Modify the above modified program further so as to display a suitable warning message
// before exiting the main due to an exception that is rethrown.
// Hint: Use your own terminate ( )


// MODIFICATION OR EXERCISE
#include <iostream>
#include <exception>
using namespace std;

// Custom terminate function to handle termination
void customTerminate() {
    cout << "Program terminated due to multiple failed attempts." << endl;
    abort(); // Call the standard abort function
}

class Dummy {
private:
    int n;

public:
    Dummy() : n(0) {}
    Dummy(int m) : n(m) {}

    // Division function with exception handling
    int divide(int a) {
        if (a == 0)
            throw a; // Throw the exception if division by zero is attempted
        cout << "\nReturning from divide" << endl;
        return (n / a);
    }
};

int main() {
    // Set the custom terminate function
    set_terminate(customTerminate);

    Dummy d1(5); // Initialize with value 5
    int b, c;
    bool flag;
    int attempts = 0;
    const int maxAttempts = 3; // Maximum number of attempts

    while (attempts < maxAttempts) {
        cout << "\nEnter b: ";
        cin >> b;

        try {
            c = d1.divide(b);
            flag = false; // Exit loop if division is successful
        } catch (int x) {
            cout << "Attempt of division by zero" << endl;
            cout << "Check your input again" << endl;
            attempts++;
            if (attempts >= maxAttempts) {
                cout << "Maximum number of attempts reached." << endl;
                throw; // Rethrow the current exception
            }
        }
    }

    cout << "\nAns = " << c << endl;
    return 0;
}

