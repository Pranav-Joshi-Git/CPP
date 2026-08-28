#include <iostream>
#include <string>

using namespace std;


// Lambda function syntax:
//
// [] (parameters) {
//      body
// };
//
// []      → capture list
// ()      → parameters
// {}      → function body
//
// Since a lambda doesn't have a regular function name,
// we can immediately call it using ().
//
// [](){}();


int main() {

    // Simple lambda function.
    // It is created and immediately called.

    []() {
        cout << "Hello World" << endl;
    }();


    // Lambda can also return a value.
    // We don't need to explicitly specify the return type here.
    // C++ automatically determines it from the return statement.

    int result = []() {
        return 100;
    }();

    cout << "Result: " << result << endl;


    // We can store a lambda in a variable using auto.
    //
    // This allows us to use the lambda multiple times,
    // just like calling a normal function.

    auto sum = [](auto a, auto b) {
        return a + b;
    };


    // Because parameters use auto, the same lambda
    // can work with different datatypes.

    cout << "Sum of 2 and 5 is: "
         << sum(2, 5) << endl;

    cout << "Sum of 2.5 and 5.3 is: "
         << sum(2.5, 5.3) << endl;


    // It can also work with strings because
    // string supports the + operator.

    string a = "abc";
    string d = "def";

    cout << sum(a, d) << endl;


    return 0;
}