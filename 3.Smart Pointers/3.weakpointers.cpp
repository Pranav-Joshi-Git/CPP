#include <iostream>
#include <memory>

using namespace std;


// weak_ptr is used to observe an object managed by shared_ptr
// without becoming an owner.
//
// shared_ptr  -> owns the object
// weak_ptr    -> observes the object, but does NOT own it
//
// Because weak_ptr does not own the object, it does not increase
// the shared_ptr reference count.
//
// A weak_ptr is useful when we want to access an object if it is
// still alive, without keeping that object alive ourselves.
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

    shared_ptr<User> tim = make_shared<User>();

    cout << "Reference count: "
         << tim.use_count() << endl; // 1


    // weak_ptr observes the object managed by tim.
    // It does NOT become an owner.
    weak_ptr<User> weakTim = tim;

    cout << "Reference count after weak_ptr: "
         << tim.use_count() << endl; // Still 1


    // Another shared_ptr becomes an owner.
    shared_ptr<User> sam = tim;

    cout << "Reference count after sam: "
         << tim.use_count() << endl; // 2


    // weak_ptr cannot directly access the object using ->.
    // We first need to check whether the object is still alive.
    //
    // lock() tries to create a shared_ptr from weakTim.
    // If the object still exists, it returns a valid shared_ptr.
    // If the object has already been destroyed, it returns nullptr.

    if (shared_ptr<User> user = weakTim.lock()) {

      cout << "User is still alive" << endl;

      user->testFunc();

    } else {

      cout << "User has already been destroyed" << endl;
    }

  } // sam and tim are destroyed.
    // Reference count becomes 0.
    // User is automatically destroyed.
    //
    // weakTim does NOT keep User alive.


  return 0;
}