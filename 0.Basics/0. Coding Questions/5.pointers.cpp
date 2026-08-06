#include <iostream>

using namespace std;

int main () {

    int age = 25;
    int *pointer = &age;

    cout << "Age = " << age << endl;
    cout << "Address = " << pointer << endl;
    cout << "Value using pointer = " << *pointer << endl;

    *pointer = 30;

    cout << "Updated Age = " << age << endl;

    return 0;
}


// 5. Pointer Practice
// Given:
// int age = 25;
// Create a pointer to age.
// Print:
// the value of age
// its address
// the value using the pointer
// Update the value to 30 using the pointer.
// Print the updated value.

// Expected Output (address will differ)

// Age = 25
// Address = 0x...
// Value using pointer = 25

// Updated Age = 30