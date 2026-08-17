#include <iostream>
#include <unordered_set>

using namespace std;


// UNORDERED SET
//
// Similar to set, BUT:
//
// → Stores only UNIQUE elements.
// → Elements are NOT stored in sorted order.
// → Does not maintain any particular order.
//
// Internally, unordered_set generally uses a HASH TABLE.
//
// Because it uses hashing:
// → Average search / insert / erase: O(1)
// → Worst case: O(N)
//
// Since elements are not ordered:
// → lower_bound() is NOT available.
// → upper_bound() is NOT available.
//
//
// Commonly used functions:
//
// insert() / emplace() → adds an element
// erase()              → removes an element
// find()               → searches for an element
// count()              → checks whether an element exists
// size()               → number of elements
// empty()              → checks whether empty
// clear()              → removes all elements
//
//
// IMPORTANT:
//
// set:
// → UNIQUE
// → SORTED
// → O(log N) search
//
// unordered_set:
// → UNIQUE
// → NOT SORTED
// → O(1) average search
//
// Use unordered_set when:
// → You only care whether an element exists.
// → You don't need sorted order.
// → You want average O(1) lookup.


void explainUnorderedSet() {

    unordered_set<int> us;


    // emplace() adds an element.
    //
    // Duplicate elements are automatically ignored.

    us.emplace(11);
    us.emplace(1);
    us.emplace(0);
    us.emplace(2);
    us.emplace(98);
    us.emplace(12);

    us.emplace(11);  // duplicate → ignored
    us.emplace(11);  // duplicate → ignored


    cout << "Unordered Set: ";

    // Order is NOT guaranteed.
    //
    // Don't expect the output to be:
    // 0 1 2 11 12 98
    //
    // The actual order depends on the hash table.

    for (auto i : us) {
        cout << i << " ";
    }

    cout << endl;


    // find()
    //
    // Returns iterator to the element.
    // Returns end() if element doesn't exist.

    auto it = us.find(98);

    if (it != us.end()) {
        cout << "98 found" << endl;
    }


    // count()
    //
    // For unordered_set:
    // 1 → element exists
    // 0 → element doesn't exist.

    cout << "Does 12 exist? " << us.count(12) << endl;


    // erase()
    //
    // Removes the given element.

    us.erase(12);


    cout << "After erasing 12: ";

    for (auto i : us) {
        cout << i << " ";
    }

    cout << endl;
}


int main() {

    explainUnorderedSet();

    return 0;
}