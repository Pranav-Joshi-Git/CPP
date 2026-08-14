#include <iostream>

using namespace std;


// Function declaration (prototype).
// This allows us to define the function after main().
int factorial(int n);


int main() {

    // Recursion: a function calls itself until a base condition
    // stops further calls.

    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Factorial: " << factorial(num) << endl;

    return 0;
}


// Recursive function
int factorial(int n) {

    // Base condition: stops the recursion.
    if (n > 1) {
        return n * factorial(n - 1);
    }

    return 1;
}