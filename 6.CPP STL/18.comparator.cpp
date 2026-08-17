#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;


// COMPARATOR
//
// A comparator tells STL:
//
// "Should element 1 come BEFORE element 2?"
//
// It should return:
// → true  → el1 should come before el2
// → false → el1 should NOT come before el2
//
// sort() normally sorts in ascending order.
//
// By providing our own comparator,
// we can define our own sorting rule.


bool internalComparator(int el1, int el2) {

    // Put larger element before smaller element.
    //
    // Example:
    // el1 = 6, el2 = 1
    // 6 should come before 1 → true

    if (el1 < el2)
        return false;

    return true;
}


void explainComparator() {

    int arr[] = {4, 2, 6, 1, 8};


    // Normal sorting → ascending order.

    sort(arr, arr + 5);

    cout << "Normal sort: ";

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;


    // Custom comparator → descending order.

    sort(arr, arr + 5, internalComparator);

    cout << "Custom sort: ";

    for (int i : arr) {
        cout << i << " ";
    }

    cout << endl;
}


// CUSTOM COMPARATOR WITH PAIRS
//
// Desired sorting:
//
// 1. Larger second element first.
// 2. If second elements are equal,
//    smaller first element comes first.
//
// Example:
//
// {2,9} before {3,9}
// because both have second = 9,
// but 2 < 3.
//
// Desired order:
//
// {2,9}
// {3,9}
// {1,6}
// {2,6}
// {1,5}


bool pairComparator(pair<int, int> p1, pair<int, int> p2) {

    // First priority:
// Larger second element comes first.

    if (p1.second > p2.second) {
        return true;
    }


    // If p1 has a smaller second element,
// it should come after p2.

    if (p1.second < p2.second) {
        return false;
    }


    // Second elements are equal.
//
// Now compare first elements.
//
// Smaller first element comes first.

    if (p1.first < p2.first) {
        return true;
    }

    return false;
}


void explainComparator2() {

    pair<int, int> arr[] = {
        {1, 6},
        {1, 5},
        {2, 6},
        {2, 9},
        {3, 9}
    };


    // Normal pair sorting:
    //
    // first element is compared first,
    // then second element if first is equal.

    sort(arr, arr + 5);

    cout << "Normal pair sort:" << endl;

    for (int i = 0; i < 5; i++) {

        cout << arr[i].first
             << ", "
             << arr[i].second
             << endl;
    }


    cout << endl;


    // Custom sorting rule.

    sort(arr, arr + 5, pairComparator);

    cout << "Custom pair sort:" << endl;

    for (int i = 0; i < 5; i++) {

        cout << arr[i].first
             << ", "
             << arr[i].second
             << endl;
    }

    cout << endl;
}


int main() {

    explainComparator();

    explainComparator2();

    return 0;
}