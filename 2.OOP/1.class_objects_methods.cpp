#include <iostream>

using namespace std;

class User {

    // Class members are private by default.
    // Data members store the object's data.
    int _secret = 22;

public:

    string name = "default";

    // Method: function belonging to the class.
    void classMessage() {
        cout << "Class is great " << name << endl;
    }
};

int main() {

    User sam;

    // name was not set, so the default value is returned.
    sam.classMessage();

    sam.name = "Sam";
    sam.classMessage();


    User john;

    // name was not set for john either, so it uses "default".
    john.classMessage();

    john.name = "John";
    john.classMessage();

    return 0;
}