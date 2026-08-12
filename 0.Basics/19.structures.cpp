#include <iostream>

using namespace std;

struct User {

    const int userId;      // Cannot be changed after initialization.
    const char *name;      // Pointer can change, but characters cannot be modified through it.
    const char *email;     // Pointer can change, but characters cannot be modified through it.
    int courseCount;       // Can be changed.
};

int main() {

    User mickey = {
        1,
        "Mickey Mouse",
        "mickey@cartoon.com",
        2
    };

    User donald = {
        2,
        "Donald Duck",
        "donald@cartoon.com",
        3
    };

    // Pointer storing the address of donald.
    User *d = &donald;

    cout << "User Id: " << mickey.userId << endl;
    cout << "Name: " << mickey.name << endl;

    cout << "User Id: " << donald.userId << endl;
    cout << "Name: " << donald.name << endl;

    // Regular struct member access using '.' operator.
    cout << "Courses assigned to " << donald.name
         << ": " << donald.courseCount << endl;

    donald.courseCount = 5;

    cout << "Updated course count: " << donald.courseCount << endl;

    // donald.userId = 10; // Error: userId is const.

    // email pointer itself can be changed.
    donald.email = "donaldduck@cartoon.com";

    cout << "Updated email: " << donald.email << endl;

    // Access struct members through a pointer using ->.
    d->courseCount = 12;

    cout << "Updated course count using pointer: "
         << donald.courseCount << endl;

    return 0;
}