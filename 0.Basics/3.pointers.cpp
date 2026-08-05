#include <iostream>
using namespace std;

int main() {

    int age = 25;      // A normal variable
    int* ptr = &age;   // Pointer stores the address of age

    cout << "age = " << age << endl;
    cout << "Address of age = " << ptr << endl;

    // pointer dereferencing - reading value using address
    cout << "Value using pointer = " << *ptr << endl; 

    // Change age using the pointer
    *ptr = 30;

    cout << "Updated age = " << age << endl;

    return 0;
}


// &variable → reference of the variable
// pointer → Stores an address
// *pointer → Value stored at that address