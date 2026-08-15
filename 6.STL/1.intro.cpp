#include <iostream>

using namespace std;


// Standard Library and Standard Template Library (STL) are related,
// but they are not exactly the same thing.
//
// Standard Library:
// - The complete collection of facilities provided by C++.
// - Includes things like I/O, strings, smart pointers, file handling,
//   containers, algorithms, etc.
//
// STL:
// - A major part of the C++ Standard Library.
// - Mainly focuses on generic programming.
// - Provides reusable containers, iterators, and algorithms.
//
// Generic Programming:
// - Data types are not fixed while writing the general-purpose logic.
// - Templates allow the same logic to work with different data types.
//
// Example:
// Instead of writing separate functions for int, float, and char,
// we can write one generic function using a template.
//
// IMPORTANT:
// Generic programming with templates is primarily a form of
// compile-time polymorphism, NOT runtime polymorphism.


template <typename T>
T getBigger(T a, T b) {

    return (a > b) ? a : b;
}


int main() {

    // T becomes int
    cout << getBigger(3, 5) << endl;


    // T becomes double
    cout << getBigger(3.5, 5.3) << endl;


    // T becomes char
    // Characters are internally represented using numeric values,
    // so 'a' and 'b' can also be compared.
    cout << getBigger('a', 'b') << endl;


    return 0;
}

// C++ Standard Library
//         │
//         ├── I/O
//         ├── Strings
//         ├── Smart Pointers
//         ├── File Handling
//         │
//         └── STL
//              ├── Containers
//              │    ├── vector
//              │    ├── list
//              │    ├── map
//              │    └── ...
//              │
//              ├── Iterators
//              │
//              └── Algorithms
//                   ├── sort
//                   ├── search
//                   ├── partition
//                   └── ...