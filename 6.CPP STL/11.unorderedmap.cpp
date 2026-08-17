#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


// UNORDERED MAP
//
// Stores data as KEY -> VALUE pairs.
//
// → Keys are UNIQUE.
// → Elements are NOT stored in sorted order.
// → Uses hashing internally.
//
// Because of hashing:
// → Average insert / search / erase: O(1)
// → Worst case: O(N)
//
// Use unordered_map when:
// → You need fast lookup using a key.
// → You don't care about the order of keys.
//
//
// Commonly used functions:
//
// insert()    → adds a key-value pair
// emplace()   → adds a key-value pair
// operator[]  → access / insert / update using key
// find()      → searches for a key
// count()     → checks whether a key exists
// erase()     → removes a key-value pair
// size()      → number of key-value pairs
// empty()     → checks whether map is empty
// clear()     → removes everything
//
// NOTE:
// lower_bound() and upper_bound() are NOT available
// because unordered_map does not maintain sorted order.
//
//
// MAP vs UNORDERED_MAP
//
// map:
// → UNIQUE keys
// → SORTED by key
// → O(log N) average operations
//
// unordered_map:
// → UNIQUE keys
// → NOT SORTED
// → O(1) average operations


void explainUnorderedMap() {

    unordered_map<int, string> um;


    // insert() adds a key-value pair.

    um.insert({5, "bat"});


    // [] can also be used to insert key-value pairs.

    um[1] = "abc";
    um[2] = "bcd";
    um[3] = "cat";

    um.insert({4, "dog"});


    // Elements are NOT sorted by key.
    //
    // The order in which they appear is not guaranteed.

    cout << "Unordered Map:" << endl;

    for (auto i : um) {

        cout << i.first << " -> " << i.second << endl;
    }


    // find()
    //
    // Searches for a key.
    // Returns um.end() if the key doesn't exist.

    auto it = um.find(3);

    if (it != um.end()) {

        cout << "Found: "
             << it->first << " -> "
             << it->second << endl;
    }


    // count()
    //
    // 1 → key exists
    // 0 → key doesn't exist.

    cout << "Does key 2 exist? "
         << um.count(2) << endl;


    // erase()
    //
    // Removes the key-value pair using the key.

    um.erase(2);


    cout << "After erasing key 2:" << endl;

    for (auto i : um) {

        cout << i.first << " -> " << i.second << endl;
    }
}


int main() {

    explainUnorderedMap();

    return 0;
}