#include <iostream>
#include <string>
#include <cstdint>

using namespace std;


// Macro:
// The preprocessor replaces the macro name with its definition
// before the code is compiled.

// Avoid redefining NULL.
// #define NULL 0


// Simple replacement macros
#define END return 0
#define ENDMESSAGE cout << "Program ends here" << endl


// Practical examples

// CUSTOMINT will be replaced with int32_t
#define CUSTOMINT int32_t

// CCPC will be replaced with: const char* const
#define CCPC const char* const


// Function-like macro
// console_log(score) becomes:
// cout << (score) << endl;
#define console_log(a) cout << (a) << endl


int main() {

    CUSTOMINT a = 4;
    CCPC b = nullptr;

    cout << a << endl;


    int score = 400;
    console_log(score);


    string name = "John Out";
    console_log(name);


    ENDMESSAGE;

    END;
}