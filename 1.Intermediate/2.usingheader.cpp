#include <iostream>
#include "2.adder.h"

using namespace std;

int main() {

    int val1 = 5;
    int val2 = 10;

    float val3 = 4.5;
    float val4 = 7.4;

    // Functions are defined in the header file.
    cout << "Sum: " << addNumbers(val1, val2) << endl;
    cout << "Sum of Floats: " << addNumbers(val3, val4) << endl;

    return 0;
}