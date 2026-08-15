#include <algorithm>
#include <iostream>

using namespace std;


int main() {

    // A normal array can also be used with STL algorithms.
    //
    // STL algorithms generally work with iterators.
    // For a raw array:
    //
    // numbers     → points to the first element
    // numbers + 7 → points just after the last element

    float numbers[7] = {
        3.1,
        2.5,
        6.4,
        4.9,
        7.3,
        1.2,
        9.6
    };


    cout << "Unsorted values: ";

    for (float num : numbers) {
        cout << num << " ";
    }


    // sort() is an STL algorithm.
    //
    // It sorts the elements between:
    //     numbers      → beginning
    //     numbers + 7  → one position after the end
    //
    // The algorithm is generic, so it can work with
    // different data types as long as they can be compared.
    //
    // The C++ standard does not require sort() to use
    // one specific sorting algorithm. Common implementations
    // use a hybrid approach such as introsort.

    sort(numbers, numbers + 7);


    cout << endl << "Sorted values: ";

    for (float num : numbers) {
        cout << num << " ";
    }

    cout << endl;


    return 0;
}