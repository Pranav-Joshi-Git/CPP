#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string apiCall() {
    return "Got some data from web";
}

int apiResponseCode() {
    return 200;
}

int main() {

    // 'auto' is not a datatype.
    // It asks the compiler to automatically deduce the type
    // from the value assigned to the variable.
    auto response = apiCall();          // Compiler deduces: string

    cout << "API Call Response: " << response << endl;

    if (typeid(response) == typeid(string)) {
        cout << "Type matches string" << endl;
    }

    auto responseCode = apiResponseCode(); // Compiler deduces: int

    cout << "API Call Response Code: " << responseCode << endl;

    if (typeid(responseCode) == typeid(int)) {
        cout << "Type matches int" << endl;
    }

    return 0;
}