#include <iostream>

using namespace std;

int main() {

  int score = 200;

  // Pointer: stores the memory address of score.
  int *myPointer = &score;

  cout << "Score: " << score << endl;
  cout << "Address stored in pointer: " << myPointer << endl;
  cout << "Value using pointer: " << *myPointer << endl;

  // Reference: another name (alias) for score.
  int &anotherScore = score;

  // Updating the reference also updates score.
  anotherScore = 800;

  cout << "\nAfter updating through reference:\n";
  cout << "\nScore: " << score << endl;
  cout << "Reference: " << anotherScore << endl;
  cout << "Value using pointer: " << *myPointer << endl;

  return 0;
}