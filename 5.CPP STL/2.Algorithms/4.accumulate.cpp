#include <iostream>
#include <numeric>

using namespace std;


// accumulate()
//
// Used to calculate the sum of elements in a range.
//
// Syntax:
//
// accumulate(start, end, initial_value);
//
// → start          → included
// → end            → excluded
// → initial_value  → value from which accumulation starts
//
// Think:
//
// result = initial_value + element1 + element2 + ...
//
// Example:
//
// accumulate(arr, arr + 5, 0)
// → 0 + 6 + 2 + 5 + 1 + 8
// → 22
//
// The range follows the same [start, end) convention
// used by most STL algorithms.


void explainAccumulate() {

    int arr[5] = {6, 2, 5, 1, 8};


    // Start from 0 and add all elements.

    cout << "Sum: "
         << accumulate(arr, arr + 5, 0)
         << endl;


    // The initial value can be something other than 0.

    cout << "Sum starting from 10: "
         << accumulate(arr, arr + 5, 10)
         << endl;
}


int main() {

    explainAccumulate();

    return 0;
}