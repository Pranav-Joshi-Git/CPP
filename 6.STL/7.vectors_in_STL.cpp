#include <iostream>
#include <vector>

using namespace std;


int main() {

    // Empty vector.
    // It can dynamically grow as elements are added.
    vector<int> numbers;


    // Another way of initializing a vector.
    vector<string> heros {
        "batman",
        "flash",
        "superman",
        "robin"
    };


    // push_back() adds an element to the end of the vector.
    numbers.push_back(5);
    numbers.push_back(6);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(9);


    // Adds 0, 1, 2, 3, 4 and 5 to the vector.
    for (int i = 0; i <= 5; i++) {
        numbers.push_back(i);
    }


    // size()     → number of elements currently stored.
    //
    // capacity() → amount of storage currently allocated.
    //               Capacity can be greater than size because
    //               vector keeps some extra space for future growth.
    //
    // max_size() → theoretical maximum number of elements
    //              the vector could hold.

    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    cout << "Max size: " << numbers.max_size() << endl;


    // empty() returns:
    // true  (1) → vector has no elements
    // false (0) → vector contains at least one element

    cout << "Is vector empty? " << numbers.empty() << endl;


    // begin() → iterator pointing to the first element.
    // end()   → iterator pointing just after the last element.

    // *numbers.begin()  // ✅ first value
    // *numbers.end()    // ❌ invalid

    // numbers.begin()   // iterator to first element
    // numbers.end()     // iterator one-past-last element
    // numbers.data()    // pointer/address of first element

    for (auto i = numbers.begin(); i != numbers.end(); ++i) {
        cout << *i << " ";
    }

    

    cout << endl;


    return 0;
}