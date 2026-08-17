#include <iostream>
#include <memory>

using namespace std;

// In shared pointers, it is allowed to create copies and share ownership
// of the same object.
//
// Unlike unique_ptr, multiple shared_ptr objects can own the same object.
// The object is destroyed only when the LAST shared_ptr owning it is destroyed.
//
// shared_ptr internally keeps track of how many shared_ptr objects
// are currently sharing ownership. This is called the reference count.
//
// ! Refer smart pointer documentation:
// https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170


class User {

public:

  User() {
    cout << "User created" << endl;
  }

  ~User() {
    cout << "User destroyed" << endl;
  }

  void testFunc() {
    cout << "I am a test function" << endl;
  }
};


int main() {

  {

    // shared_ptr<User> tim(new User());
    // Valid, but make_shared() is the preferred modern C++ approach.

    shared_ptr<User> tim = make_shared<User>();

    cout << "Reference count: " << tim.use_count() << endl;


    // Copying is allowed.
    // Both pointers now share ownership of the same User object.
    shared_ptr<User> john = tim;

    cout << "Reference count: " << tim.use_count() << endl;


    // Both can access the same object.
    tim->testFunc();
    john->testFunc();


    {
      // Another shared owner.
      shared_ptr<User> sam = john;

      cout << "Reference count: " << tim.use_count() << endl;

    } // sam is destroyed → reference count decreases.


    cout << "Reference count: " << tim.use_count() << endl;

  } // john and tim are destroyed.
    // Reference count becomes 0 → User is automatically destroyed.


  cout << "Outside scope" << endl;


  return 0;
}