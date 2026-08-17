#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


// sort()
//
// Syntax:
//
// sort(start, end);
//
// IMPORTANT:
// The range is [start, end)
//
// → start is INCLUDED
// → end is EXCLUDED
//
// Think:
// [start ........ end)
//  ↑                ↑
// include        don't include
//
// For an array:
// arr       → address of first element
// arr + 5   → address just after the 5th element
//
// So:
// sort(arr, arr + 5)
// → sorts all 5 elements.
//
//
// Time Complexity:
// O(N log N) for the standard sorting algorithm.


void explainSort() {

    // Sort the complete array.

    int arr[5] = {6, 2, 1, 8, 7};

    sort(arr, arr + 5);

    cout << "Sorted complete array: ";

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;


    // Sort only a portion of the array.
    //
    // arr2 + 1 → index 1 → INCLUDED
    // arr2 + 4 → index 4 → EXCLUDED
    //
    // Therefore indices 1, 2, 3 are sorted.
    //
    // [1, 4) → 1, 2, 3

    int arr2[5] = {6, 2, 1, 8, 7};

    sort(arr2 + 1, arr2 + 4);

    cout << "Partially sorted array: ";

    for (int i : arr2) {
        cout << i << " ";
    }

    cout << endl;


    // sort() also works with vectors.
    //
    // vec.begin()       → first element
    // vec.begin() + 1   → index 1
    // vec.begin() + 4   → index 4 (excluded)
    //
    // So indices 1, 2, 3 are sorted.

    vector<int> vec = {6, 4, 7, 2, 9, 1, 0};

    sort(vec.begin() + 1, vec.begin() + 4);

    cout << "Partially sorted vector: ";

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;
}


int main() {

    explainSort();

    return 0;
}