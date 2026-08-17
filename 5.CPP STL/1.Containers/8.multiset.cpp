#include <iostream>
#include <set>

using namespace std;


// MULTISET
//
// Same as set, BUT:
// → Allows duplicate elements.
// → Elements are automatically stored in ascending order.
//
// Example:
//
// set       → 1 2 3 4
// multiset  → 1 1 1 2 3 4 4
//
//
// Commonly used functions:
//
// insert() / emplace() → adds an element
// erase()              → removes element(s)
// find()               → finds an element
// count()              → counts occurrences
// size()               → returns number of elements
// empty()              → checks whether multiset is empty
// lower_bound()        → first element >= given value
// upper_bound()        → first element > given value
//
// Time complexity of insert/find/erase:
// O(log N) approximately
//
// NOTE:
// Unlike set, count(x) can return MORE than 1.


void explainMultiSet() {

    multiset<int> ms;


    ms.emplace(1);
    ms.emplace(1);
    ms.emplace(1);
    ms.emplace(1);
    ms.emplace(0);
    ms.emplace(21);
    ms.emplace(11);


    cout << "Multiset: ";

    for (auto i : ms) {
        cout << i << " ";
    }

    cout << endl;


    cout << "Size: " << ms.size() << endl;


    // find()
    //
    // Returns an iterator pointing to the FIRST occurrence
    // of the given element.

    auto it = ms.find(1);

    if (it != ms.end()) {
        cout << "First occurrence of 1: " << *it << endl;
    }


    // erase(iterator)
    //
    // Removes ONLY the element at that iterator.
    //
    // Since find(1) points to the first occurrence,
    // only ONE '1' will be removed.

    ms.erase(ms.find(1));


    cout << "After erasing one 1: ";

    for (auto i : ms) {
        cout << i << " ";
    }

    cout << endl;


    // erase(value)
    //
    // Removes ALL occurrences of that value.
    //
    // Example:
    //
    // ms.erase(1);
    // → removes every 1 from the multiset.


    // count()
    //
    // Returns the NUMBER OF occurrences.

    cout << "Number of 1s: " << ms.count(1) << endl;
}


int main() {

    explainMultiSet();

    return 0;
}