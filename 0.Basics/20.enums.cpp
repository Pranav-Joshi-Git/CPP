#include <iostream>
#include <cstdint>

using namespace std;

// Preprocessor macro:
// Replaces PI with 3.14 before the code is compiled.
// Modern C++ usually prefers const/constexpr instead of #define for constants.
#define PI 3.14

// Enum: gives meaningful names to a group of related integer values.
// By default, values start from 0 and increase by 1.
enum MsOffice : uint8_t { // Meaning - Store the enum's underlying values using uint8_t.

    BOLD = 5,     // Explicitly starts at 5.
    ITALICS,      // 6
    UNDERLINE,    // 7
    CROSSED       // 8
};

int main() {

    // Enum values can be used like their underlying integer values.
    int myAttributes = ITALICS;

    cout << "ITALICS value: " << myAttributes << endl;

    cout << "BOLD value: " << BOLD << endl;
    cout << "UNDERLINE value: " << UNDERLINE << endl;
    cout << "CROSSED value: " << CROSSED << endl;

    cout << "PI: " << PI << endl;

    return 0;
}