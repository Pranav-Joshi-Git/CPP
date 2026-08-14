#include <iostream>

// Template function:
// T is a placeholder for the data type.
// The compiler determines T based on the arguments passed.
template <typename T>
T addMe(T a, T b) {
    return a + b;
}

int main() {

    using namespace std;

    // T becomes int
    cout << addMe(3, 4) << endl;

    // T becomes double
    cout << addMe(3.1, 4.2) << endl;

    return 0;
}