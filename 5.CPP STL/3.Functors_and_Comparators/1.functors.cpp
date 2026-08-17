#include <iostream>

using namespace std;


// Functors - Functional Operators
//
// A functor is an object that behaves like a function.
//
// We can make an object callable by overloading operator().
//
// Example:
//     floaty(1);
//
// Although floaty is an object, C++ treats the above as:
//     floaty.operator()(1);
//
// One advantage of a functor over a normal function is that
// the object can maintain its own state between calls.


class MyFloat {

    float ft;

public:

    MyFloat() {
        ft = 0.1;
    }


    void getValue() {
        cout << ft << endl;
    }


    // Overloading the function-call operator ().
    //
    // First () → operator being overloaded
    // Second () → parameters accepted by the operator
    //
    // This allows us to call the object like:
    //     floaty(1);
    //
    // which is equivalent to:
    //     floaty.operator()(1);

    void operator()(float v) {
        ft += v;
    }

};


int main() {

    MyFloat floaty;

    floaty.getValue();      // 0.1


    floaty(1);              // ft becomes 1.1
    floaty.getValue();


    floaty(1.3);            // ft becomes 2.4
    floaty.getValue();


    return 0;
}