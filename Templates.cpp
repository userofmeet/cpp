// Define a template class Array that will have three member functions given below:
// a) sort( ) that will sort the elements in ascending order.
// b) reverse( ) that will reverse the content of an array and
// c) safe( ) that will check the size of array; if size is exceeded terminate the
// program otherwise perform the above two task.
#include <iostream>
#include <algorithm> // For std::sort and std::reverse
#include <stdexcept> // For std::out_of_range
using namespace std;

template <typename T, size_t MaxSize>
class Array {
private:
    T arr[MaxSize];
    size_t size;

public:
    Array() : size(0) {}

    void addElement(const T& element) {
        if (size >= MaxSize) {
            throw out_of_range("Array size exceeded");
        }
        arr[size++] = element;
    }

    void sort() {
        std::sort(arr, arr + size);
    }

    void reverse() {
        std::reverse(arr, arr + size);
    }

    void safe() {
        if (size > MaxSize) {
            cerr << "Error: Array size exceeded." << endl;
            terminate(); // Terminate the program if size is exceeded
        }
        sort();
        reverse();
    }

    void display() const {
        for (size_t i = 0; i < size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    try {
        // Create an array of integers with a maximum size of 5
        Array<int, 5> intArray;
        intArray.addElement(3);
        intArray.addElement(1);
        intArray.addElement(4);
        intArray.addElement(1);
        intArray.addElement(5);

        // Display original array
        cout << "Original array: ";
        intArray.display();

        // Perform safe operations
        intArray.safe();

        // Display sorted and reversed array
        cout << "Sorted and reversed array: ";
        intArray.display();

    } catch (const std::out_of_range& e) {
        cerr << e.what() << endl;
        return 1;
    }

    return 0;
}
