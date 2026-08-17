#include <algorithm>
#include <iostream>

using namespace std;


// count()
//
// Counts how many times a value appears in a range.
//
// Syntax:
//
// count(start, end, value);
//
// → start  → included
// → end    → excluded
// → value  → value we want to count
//
// Returns the number of occurrences.
//
// If the value doesn't exist → returns 0.


void explainCount() {

    int arr[10] = {
        1, 4, 25, 1, 5,
        1, 68, 1, 21, 12
    };


    cout << "Count of 1: "
         << count(arr, arr + 10, 1)
         << endl;
}


// find()
//
// Searches for the first occurrence of a value.
//
// Syntax:
//
// find(start, end, value);
//
// → Returns an iterator pointing to the first matching element.
// → If the element is not found, returns the end iterator.
//
// For an array:
// → iterator is basically a pointer.
//
// For a vector:
// → iterator is a vector iterator.
//
// IMPORTANT:
// Always check whether the element was found
// before dereferencing the iterator.


void explainFind() {

    int arr[10] = {
        1, 4, 25, 1, 5,
        1, 68, 1, 21, 12
    };


    auto it = find(arr, arr + 10, 5);


    if (it != arr + 10) {

        // *it → value at the iterator's location

        cout << "Found: " << *it << endl;

    } else {

        cout << "Not Found" << endl;
    }


    // Searching for a value that doesn't exist.

    auto it2 = find(arr, arr + 10, 109);


    if (it2 == arr + 10) {

        cout << "109: Not Found" << endl;
    }
}


int main() {

    explainCount();
    explainFind();

    return 0;
}