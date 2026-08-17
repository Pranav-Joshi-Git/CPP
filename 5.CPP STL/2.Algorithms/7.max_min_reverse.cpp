#include <algorithm>
#include <iostream>

using namespace std;


// max_element()
//
// Returns an iterator pointing to the LARGEST element
// in the given range.
//
// Syntax:
//
// max_element(start, end);
//
// IMPORTANT:
// It returns an iterator, NOT the actual value.
//
// So:
// *it → gives the value.
//
// Range follows [start, end):
// → start included
// → end excluded


void explainMaxElement() {

    int arr[5] = {9, 46, 1, 5, 79};


    auto it = max_element(arr, arr + 5);

    cout << "Maximum: " << *it << endl;


    // min_element()
    //
    // Returns an iterator pointing to the SMALLEST element.

    auto it2 = min_element(arr, arr + 5);

    cout << "Minimum: " << *it2 << endl;
}


// Keeping this separately for practice/reference.

void explainMinElement() {

    int arr[5] = {9, 46, 1, 5, 79};

    auto it = min_element(arr, arr + 5);

    cout << "Minimum: " << *it << endl;
}


// reverse()
//
// Reverses the elements inside the given range.
//
// reverse(start, end);
//
// → start included
// → end excluded
//
// Example:
//
// arr = {9, 4, 1, 5, 7}
//
// reverse(arr + 1, arr + 4);
//
// Range = indices [1, 4)
//
// Elements:
// 4 1 5
//
// Become:
// 5 1 4
//
// Final array:
// 9 5 1 4 7


void explainReverse() {

    int arr[5] = {9, 4, 1, 5, 7};

    reverse(arr + 1, arr + 4);


    cout << "After reverse: ";

    for (int i : arr) {

        cout << i << " ";
    }

    cout << endl;
}


int main() {

    explainMaxElement();

    explainMinElement();

    explainReverse();

    return 0;
}