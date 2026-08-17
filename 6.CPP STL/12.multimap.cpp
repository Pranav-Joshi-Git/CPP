#include <iostream>
#include <map>

using namespace std;


// MULTIMAP
//
// Similar to map, BUT:
//
// → Multiple values can have the SAME key.
// → Keys are stored in ASCENDING order.
// → Each key can have multiple key-value pairs.
//
// Example:
//
// map:
// 1 -> 'a'
// 2 -> 'b'
//
// multimap:
// 1 -> 'a'
// 1 -> 'b'
// 2 -> 'b'
// 2 -> 'd'
//
//
// Commonly used functions:
//
// insert()        → adds a key-value pair
// emplace()       → adds a key-value pair
// find()          → finds the first occurrence of a key
// count()         → number of pairs with a given key
// erase()         → removes pair(s)
// lower_bound()   → first pair with key >= given key
// upper_bound()   → first pair with key > given key
// equal_range()   → gives range containing all pairs of a key
// size()          → number of key-value pairs
// empty()         → checks whether empty
// clear()         → removes all elements
//
//
// IMPORTANT:
//
// map:
// → UNIQUE keys
// → SORTED
//
// multimap:
// → DUPLICATE keys allowed
// → SORTED by key
//
// multimap does NOT support:
// → mmap[key]
// because one key can have multiple values.
//
// Use insert() / emplace() instead.


void explainMultiMap() {

    multimap<int, char> mmap;


    // Multiple pairs can have the same key.

    mmap.insert({3, 'b'});

    mmap.insert({1, 'a'});
    mmap.insert({1, 'b'});
    mmap.insert({1, 'b'});

    mmap.insert({2, 'd'});
    mmap.insert({2, 'd'});
    mmap.insert({2, 'b'});


    cout << "Multimap:" << endl;

    for (auto i : mmap) {

        cout << i.first << " -> "
             << i.second << endl;
    }


    // count()
    //
    // Returns the number of key-value pairs
    // having the given key.

    cout << "\nNumber of pairs with key 2: "
         << mmap.count(2) << endl;


    // equal_range()
    //
    // Returns a pair of iterators:
    //
    // first → first occurrence of the key
    // second → position just after the last occurrence
    //
    // So [first, second) contains all pairs
    // having the given key.

    auto it = mmap.equal_range(2);


    cout << "\nAll pairs with key 2:" << endl;

    for (auto i = it.first; i != it.second; ++i) {

        cout << i->first << " -> "
             << i->second << endl;
    }
}


int main() {

    explainMultiMap();

    return 0;
}