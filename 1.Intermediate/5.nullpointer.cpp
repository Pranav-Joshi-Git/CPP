#include <iostream>

using namespace std;

void printValue(int a) {
    cout << "Integer value is: " << a << endl;
}

void printValue(double a) {
    cout << "Double value is: " << a << endl;
}

void printValue(int* a) {
    cout << "Pointer value is: " << a << endl;
}

int main() {

    printValue(5);       // Calls int version.
    printValue(5.5);     // Calls double version.

    // NULL is traditionally defined as 0.
    // Therefore, it can behave like an integer and cause
    // ambiguity when multiple overloaded functions exist.
    // printValue(NULL); // Ambiguous: could be int or pointer.

    // nullptr is specifically used to represent a null pointer.
    // nullptr is used to represent "this pointer points to nothing."
    // Therefore, the pointer version is selected.
    printValue(nullptr);

    return 0;
}