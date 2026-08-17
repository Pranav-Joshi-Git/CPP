#include <iostream>
#include <ostream>
#include <vector>

// Consider vector as something similar to ArrayList.
//
// In a normal array, we usually specify its size when creating it.
// A vector can dynamically grow or shrink as elements are added/removed.
//
// vector is part of the STL (Standard Template Library).

using namespace std;


// When a class mainly holds data and doesn't have much behavior/methods,
// using struct can be a simple and appropriate choice.
struct Corners {
    float a, b, c, d;
};


// Operator overloading:
// Defines what should happen when << is used with a Corners object.
//
// Without this, cout does not know how to directly print Corners.
ostream& operator<<(ostream& stream, const Corners& corner) {

    stream << corner.a << ", "
           << corner.b << ", "
           << corner.c << ", "
           << corner.d;

    return stream;
}


int main() {

    // vector can store any datatype, class, or struct.
    vector<int> inty;


    // push_back() adds an element to the end of the vector.
    inty.push_back(2);
    inty.push_back(3);
    inty.push_back(4);
    inty.push_back(5);


    // .begin() → iterator pointing to the first element.
    // .end()   → iterator pointing just AFTER the last element.
    //
    // i is an iterator, not an integer index.
    // Therefore, we use *i to get the value stored at that location.
    for (auto i = inty.begin(); i != inty.end(); i++) {

        // cout << inty[i] << endl;
        // Not possible because i is an iterator, not an index.

        cout << *i << endl; // Dereference iterator to get the value.
    }


    // Vector can also store our own structs/classes.
    vector<Corners> corners;


    // {} can be used to initialize the Corners object.
    corners.push_back({7, 8, 9, 10});
    corners.push_back({4, 5, 6, 8});


    // Vector supports index-based access using [].
    for (int i = 0; i < corners.size(); i++) {

        // Normally cout cannot directly print a Corners object.
        // Our overloaded << operator tells cout how to print it.
        cout << corners[i] << endl;
    }


    return 0;
}