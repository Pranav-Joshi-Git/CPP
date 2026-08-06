#include <iostream>

using namespace std;

int main() {

  int numbers[] = {4, 5, 6, 7, 8, 9, 0};
  int i = 0;

  cout << "Using while:" << endl;

  // while: condition is checked before each iteration.
  while (i < 7) {
    cout << numbers[i] << endl;
    i++;
  }

  cout << "\nUsing break:\n";

  i = 0;
  while (i < 7) {
    if (i == 5) {
      break; // Exit the loop immediately.
    }

    cout << numbers[i] << endl;
    i++;
  }

  cout << "\nUsing continue:\n";

  i = 0;
  while (i < 7) {
    if (i == 5) {
      i++;      // Prevent infinite loop.
      continue; // Skip the remaining statements of this iteration.
    }

    cout << numbers[i] << endl;
    i++;
  }

  cout << "\nUsing do-while:\n";

  i = 0;

  // do-while: loop body executes at least once.
  do {
    cout << numbers[i] << endl;
    i++;
  } while (i < 7);

  return 0;
}