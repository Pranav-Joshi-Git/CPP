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

// Easy way to remember pointers:
//
// &  → "WHERE?" → gets an address
// *  → "WHAT?"  → accesses the value at an address
//
// Example:
// int age = 25;
// int *pointer = &age;
//
// &age
// → "Give me age's address"
// → GETTER for age's address
//
// pointer
// → "Give me the address stored inside pointer"
// → STORAGE for age's address
//
// *pointer
// → "Give me the value at the address stored in pointer"
// → accesses/dereferences the value → 25
//
// Quick mental model:
// age       → 25
// &age      → address of age
// pointer   → stores that address
// *pointer  → accesses the value at that address → 25
//
// Note:
// int &ref = age;
// Here & means "reference", not address.
// age → [25]
//        ↑
//        │
// ref ───┘
//
// int &ref = age;
// & here means "create a reference to age".
// ref becomes another name (alias) for age.
// A reference is not a pointer; it doesn't separately store an address like ptr does.