#include <iostream>

using namespace std;

int main() {

  int numArray[4] = {1, 2, 3, 4};

  // The array name represents the address of its first element.
  cout << numArray << endl;

  // Initialize all elements to 0.
  int anotherArray[4] = {};

  anotherArray[0] = 9;
  anotherArray[1] = 19;

  cout << anotherArray[3] << endl; // Prints 0.

  cout << anotherArray[0] << endl; // Before update

  // anotherArray points to the first element.
  *anotherArray = 29;

  cout << anotherArray[0] << endl; // First element updated to 29.

  cout << anotherArray[1] << endl;

  // Pointer to the first element of the array.
  int *arrayPointer = anotherArray;

  arrayPointer++;      // Move to the next element.
  *arrayPointer = 209; // Update the second element.

  cout << anotherArray[1] << endl; // Prints 209.

  return 0;
}