#include <iostream>
#include <string>

using namespace std;


// Base case:
// Called when only one argument is left.
// This stops the recursion.
template <typename T>
void versatilePrinter(T value) {
    cout << "Base case: " << value << endl;
}


// Variadic template:
// T = first argument
// Args... = remaining arguments
template <typename T, typename... Args>
void versatilePrinter(T value, Args... args) {

    cout << "Recursive call: " << value << endl;

    // Print the remaining arguments one by one.
    versatilePrinter(args...);
}


int getTwo() {
    return 2;
}


int main() {

    // Only one argument → directly uses the base case.
    string name = "John Doe";
    versatilePrinter(name);
    versatilePrinter(21);
    versatilePrinter(23.45);


    // Multiple arguments → recursive function keeps getting called
    // until only the last argument remains.
    versatilePrinter(
        1,
        3,
        6.4,
        8.7,
        "Pranav",
        "John Doe",
        getTwo()
    );

    return 0;
}