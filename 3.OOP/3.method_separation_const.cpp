#include <iostream>

using namespace std;

class User {

    int _secret = 22;

public:

    // Only declaration inside the class.
    // Definition is written separately below.
    void classMessage();

    // const method → promises not to modify the object.
    int getSecret() const {
        return _secret;
    }
};


// Scope resolution operator (::)
// tells C++ that classMessage() belongs to User.
void User::classMessage() {
    cout << "Class is great" << endl;
}


int main() {

    // Normal object.
    User sam;

    sam.classMessage();
    cout << "Secret: " << sam.getSecret() << endl;


    // Constant object.
    const User rock;

    // A const object can only call const methods.
    cout << "Rock's secret: " << rock.getSecret() << endl;

    // rock.classMessage(); // Error: classMessage() is not const.

    return 0;
}