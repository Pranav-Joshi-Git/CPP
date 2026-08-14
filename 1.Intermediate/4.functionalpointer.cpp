#include <iostream>

using namespace std;

int getTwo() {
    return 2;
}

void interesting() {
    cout << "I am interesting" << endl;
}

int main() {

    int whatIgot = getTwo();

    // Function pointer:
    // Stores the address of a function.
    // This pointer can point to any function with the same signature:
    // void functionName()
    void (*functionPtr)() = interesting;

    cout << whatIgot << endl;

    // Call the function through the pointer.
    functionPtr();

    // This is another way to call the same function through the pointer.
    (*functionPtr)();

    return 0;
}