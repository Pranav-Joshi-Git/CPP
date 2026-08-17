#include <iostream>
#include <map>
#include <string>

using namespace std;


// MAP
//
// Stores data as KEY -> VALUE pairs.
//
// → Keys are UNIQUE.
// → Keys are automatically stored in ASCENDING order.
// → Each key is associated with one value.
//
// Example:
//
// 1 -> "abc"
// 2 -> "bcd"
// 3 -> "cat"
//
//
// Commonly used functions:
//
// insert()       → adds a key-value pair
// emplace()      → adds a key-value pair
// operator[]     → access / insert / update using key
// find()         → searches for a key
// count()        → checks whether a key exists
// erase()        → removes a key-value pair
// size()         → number of key-value pairs
// empty()        → checks whether map is empty
// lower_bound()  → first key >= given key
// upper_bound()  → first key > given key
// clear()        → removes everything
//
//
// IMPORTANT:
//
// map is sorted by KEY, not by VALUE.
//
// Keys must be unique.
// Values can be duplicate.
//
// Internally, std::map is generally implemented using
// a balanced binary search tree.
//
// Search / insert / erase → O(log N)


void explainMap() {

    // Key   → int
    // Value → string

    map<int, string> mpp;


    // insert() adds a key-value pair.

    mpp.insert({5, "bat"});


    // [] can also be used to insert key-value pairs.

    mpp[1] = "abc";
    mpp[2] = "bcd";
    mpp[3] = "cat";

    mpp.insert({4, "dog"});


    // Keys are UNIQUE.
    //
    // Since key 1 already exists,
    // this updates its value instead of creating
    // another element.

    mpp[1] = "vik";


    // Map automatically sorts elements by KEY.

    cout << "Map:" << endl;

    for (auto i : mpp) {

        cout << i.first << " -> " << i.second << endl;
    }


    // find()
    //
    // Searches for a key and returns an iterator.
    //
    // If key doesn't exist → returns mpp.end().

    auto it = mpp.find(4);

    if (it != mpp.end()) {

        cout << "Found: "
             << it->first << " -> "
             << it->second << endl;
    }


    // Key 6 doesn't exist.

    auto it2 = mpp.find(6);

    if (it2 == mpp.end()) {

        cout << "6 Not Found" << endl;
    }


    // count()
    //
    // For map:
    // 1 → key exists
    // 0 → key doesn't exist.

    cout << "Does key 3 exist? "
         << mpp.count(3) << endl;


    // erase()
    //
    // Removes the key-value pair using the key.

    mpp.erase(3);


    cout << "After erasing key 3:" << endl;

    for (auto i : mpp) {

        cout << i.first << " -> " << i.second << endl;
    }


    // lower_bound() and upper_bound()
    // work on KEYS because the map is sorted by key.

    auto lb = mpp.lower_bound(2);

    if (lb != mpp.end()) {
        cout << "Lower bound of 2: "
             << lb->first << endl;
    }


    auto ub = mpp.upper_bound(2);

    if (ub != mpp.end()) {
        cout << "Upper bound of 2: "
             << ub->first << endl;
    }
}


int main() {

    explainMap();

    return 0;
}