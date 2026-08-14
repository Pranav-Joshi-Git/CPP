#include <iostream>

using namespace std;


// 1. Call by Value
// A copy of the argument is passed to the function.
// Changes made inside the function do NOT affect the original variable.
void increaseLifeByValue(int life) {
    ++life;
}


// 2. Passing a Pointer
// The address of the variable is passed.
// Dereferencing the pointer allows us to modify the original variable.
// Multiple calls will update the value each time.
void increaseLifeByPointer(int *life) {
    ++(*life);
}


// 3. Call by Reference
// The function receives a reference to the original variable.
// Changes directly affect the original variable.
// Multiple calls will update the value each time.
void increaseLifeByReference(int &life) {
    ++life;
}


// Function overloading:
// Same function name, but different parameter types.
int addNumbers(int a, int b) {
    return a + b;
}

float addNumbers(float a, float b) {
    return a + b;
}


// main() is also a function.
// Unlike our functions, we don't call main() ourselves.
// The program starts execution from main().

int main() {

    // -------------------------------
    // Call by Value
    // -------------------------------

    int life = 3;

    increaseLifeByValue(life);

    // Still 3 because the function received a copy.
    cout << "Life after call by value: " << life << endl;


    // -------------------------------
    // Passing a Pointer
    // -------------------------------

    increaseLifeByPointer(&life);
    increaseLifeByPointer(&life);

    // Each call modifies the original value through the pointer.
    cout << "Life after 2 calls using pointer: " << life << endl;


    // -------------------------------
    // Call by Reference
    // -------------------------------

    int newLife = 5;

    increaseLifeByReference(newLife);
    increaseLifeByReference(newLife);

    // Each call modifies the original value through the reference.
    cout << "Life after 2 calls using reference: " << newLife << endl;


    // -------------------------------
    // Function Overloading
    // -------------------------------

    int val1 = 5;
    int val2 = 10;

    float val3 = 4.5;
    float val4 = 7.4;

    // Calls the int version of addNumbers().
    cout << "Sum: " << addNumbers(val1, val2) << endl;

    // Calls the float version of addNumbers().
    cout << "Sum of Floats: " << addNumbers(val3, val4) << endl;


    return 0;
}