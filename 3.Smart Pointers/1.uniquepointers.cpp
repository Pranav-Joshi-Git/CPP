#include <iostream>

// Mandatory for smart pointers
#include <memory>

// Generally, we need to be cautious about pointers.
// Main reason is memory leaks - which might even crash the program,
// waste memory, or potentially create security issues.
//
// new keyword    - allocates memory on the heap
// delete keyword - deallocates memory from the heap
// With new, we are responsible for using delete.
//
// Smart pointers solve the issue of manually remembering to use delete.
// A smart pointer is a wrapper around a real "raw" pointer.
//
// ! Refer this doc:
// https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170
//
//
// 1. Unique Pointers
//    - One unique_ptr owns the object.
//    - Memory is automatically freed when the unique_ptr goes out of scope.
//    - We cannot copy unique_ptr because there should only be one owner.
//    - Ownership can be transferred using move().


using namespace std;


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

  { // Empty scope

    // unique_ptr<User> sam = new User(); 
    // Not allowed because unique_ptr expects ownership to be created
    // through its constructor or make_unique().

    // unique_ptr<User> sam(new User());
    // Valid, but make_unique() is the preferred modern C++ approach.

    unique_ptr<User> sam = make_unique<User>();

    sam->testFunc();


    // unique_ptr<User> tom = sam;
    // Not allowed because unique_ptr cannot be copied.
    // This prevents multiple unique_ptr objects from owning the same object.

  } // As soon as the scope ends, sam is destroyed
    // and the User object is automatically destroyed/freed.

  cout << "Outside scope" << endl;


  return 0;
}