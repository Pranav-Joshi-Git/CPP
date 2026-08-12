#include <iostream>

using namespace std;

struct User {

  const int id;
  int age;

  // Constructor: provides default values when a User object is created.
  User() : id(101), age(22) {}
};

int main() {
  // Stack and Heap are broadly same (both are part of RAM)
  // but allocation part(starting initialization) is little different

  // STACK MEMORY
  // Local variables are normally created on the stack.
  // Memory is automatically released when the variable goes out of scope.
  int score = 100;
  User mike;

  cout << "Mike's ID: " << mike.id << endl;
  cout << "Mike's age: " << mike.age << endl;

  // HEAP MEMORY
  // 'new' dynamically allocates memory on the heap.
  // The memory remains allocated until we explicitly release it.

  int *heapScore = new int;

  *heapScore = score;

  cout << "Heap score: " << *heapScore << endl;

  // A User object can also be created dynamically on the heap.
  User *nike = new User;

  cout << "Nike's ID: " << nike->id << endl;
  cout << "Nike's age: " << nike->age << endl;

  // Memory allocated with 'new' must be released with 'delete'.
  delete heapScore;
  delete nike;

  return 0;
}