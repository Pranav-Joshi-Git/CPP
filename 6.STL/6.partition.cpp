#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    vector<int> myInts = {
        1, 2, 3, 4, 5,
        6, 7, 8, 9, 10
    };


    cout << "Original values: ";

    for (int x : myInts) {
        cout << x << " ";
    }

    cout << endl;


    // partition() rearranges elements into two groups:
    //
    // Group 1 → elements for which the condition is true
    // Group 2 → elements for which the condition is false
    //
    // Here, even numbers satisfy the condition,
    // so even numbers will be moved before odd numbers.
    //
    // The third argument is a lambda function.
    //
    // The lambda receives each element and returns:
    // true  → put it in the first group
    // false → put it in the second group.

    partition(
        myInts.begin(),
        myInts.end(),
        [](auto x) {
            return x % 2 == 0;
        }
    );


    cout << "After partition: ";

    for (int x : myInts) {
        cout << x << " ";
    }

    cout << endl;


    return 0;
}