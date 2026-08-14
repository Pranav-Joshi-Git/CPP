#include <iostream>

using namespace std;

class User {

    // Private data cannot be accessed directly from outside the class.
    int _secret = 22;

public:

    // Setter → modifies private data.
    void setSecret(int newSecret) {
        _secret = newSecret;
    }

    // Getter → reads private data.
    int getSecret() {
        return _secret;
    }
};

int main() {

    User sam;

    // sam._secret = 333; // Error: _secret is private.

    sam.setSecret(333);

    cout << "Secret: " << sam.getSecret() << endl;

    return 0;
}