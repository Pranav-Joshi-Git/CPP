#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


// next_permutation()
//
// Rearranges the range into the NEXT lexicographically greater permutation.
//
// Think:
//
// abc → acb → bac → bca → cab → cba
//
// Returns:
// → true  → next permutation exists
// → false → no greater permutation exists
//
// IMPORTANT:
// If we start from the smallest/sorted arrangement,
// next_permutation() can be used to generate ALL permutations.
//
// If the range is already at the largest permutation,
// next_permutation() returns false and rearranges the range
// back to the smallest permutation.
//
// Example:
//
// abc → acb → bac → bca → cab → cba → abc
//
// The final abc happens because next_permutation()
// returns false after cba and resets the range.


void explainNextPermutation() {

    string str = "abc";

    cout << "Permutations of abc:" << endl;

    do {

        cout << str << endl;

    } while (next_permutation(str.begin(), str.end()));
}


// Starting from "bca"
//
// next_permutation() does NOT start from the beginning.
//
// It starts from the current arrangement and finds
// the next lexicographically greater arrangement.
//
// bca → cab → cba
//
// After cba, there is no greater permutation,
// so next_permutation() returns false
// and resets the string to abc.


void explainFromMiddle() {

    string str = "bca";

    cout << "\nStarting from bca:" << endl;

    do {

        cout << str << endl;

    } while (next_permutation(str.begin(), str.end()));
}


// next_permutation() can also work on PART of a range.
//
// Only the selected range is rearranged.
// Everything outside that range remains unchanged.
//
// Here:
//
// str.begin() + 1 → index 1 → included
// str.begin() + 4 → index 4 → excluded
//
// So only indices [1, 4) are permuted.


void explainPartialPermutation() {

    string str = "abcd";

    cout << "\nPartial permutation:" << endl;

    do {

        cout << str << endl;

    } while (next_permutation(str.begin() + 1,
                              str.begin() + 4));
}


// prev_permutation()
//
// Does the opposite of next_permutation().
//
// Finds the PREVIOUS lexicographically smaller permutation.
//
// Example:
//
// cba → cab → bca → bac → acb → abc
//
// Returns:
// → true  → previous permutation exists
// → false → no smaller permutation exists
//
// If we want to generate ALL permutations using
// prev_permutation(), start from the largest arrangement
// (usually descending order).


void explainPrevPermutation() {

    string str = "cba";

    cout << "\nPrevious permutations:" << endl;

    do {

        cout << str << endl;

    } while (prev_permutation(str.begin(), str.end()));
}


int main() {

    explainNextPermutation();

    explainFromMiddle();

    explainPartialPermutation();

    explainPrevPermutation();

    return 0;
}