#include <iostream>
#include <string>
#include <utility> // std::move

using namespace std;


// Regular swap.
// Values are copied between variables.
void swapValues(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;
}


// Using std::move.
// std::move itself does NOT move the value.
// It converts the variable into an rvalue reference,
// allowing move operations to be used when available.
//
// std::move() gives permission to treat an object as movable.
//
// For int, there isn't really a performance benefit because
// moving an int is essentially the same as copying it.
void moveSwap(int &a, int &b) {

    int temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}


string printMe() {
    return "I am print";
}


int main() {

    int a = 5;
    int b = 10;

    swapValues(a, b);

    cout << "a: " << a << ", b: " << b << endl;


    int c = 4;
    int d = 3;

    moveSwap(c, d);

    cout << "c: " << c << ", d: " << d << endl;


    // Lvalue:
    // An object that has a persistent identity/location in memory.
    //
    // Rvalue:
    // A temporary value that generally does not have a persistent
    // identity that we can use after the expression.
    //
    // Here:
    // x → lvalue
    // 7 → rvalue

    int x = 7;


    // printMe() returns a temporary string (rvalue).
    //
    // The returned string is used to initialize s.
    // Modern C++ can move or construct the result directly,
    // rather than necessarily making an extra copy.
    string s = printMe();


    // && is an rvalue reference.
    //
    // printMe() returns a temporary string, so ss can bind to it.
    // ss refers to that temporary object.
    string &&ss = printMe();


    return 0;
}