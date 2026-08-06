#include <iostream>

using namespace std;

int main() {

  // C-style string: compiler automatically adds '\0' (null terminator).
  char myString[] = "Pranav";

  // Same string initialized manually.
  // '\0' must be added explicitly to mark the end of the string.
  char myName[] = {'P', 'r', 'a', 'n', 'a', 'v', '\0'};

  cout << "My name is " << myString << endl;
  cout << "My name is " << myName << endl;

  cout << "\nLooping using index:\n";

  // Stop when the null terminator ('\0') is reached.
  for (int i = 0; myName[i] != '\0'; i++) {
    cout << "Character: " << myName[i] << endl;
  }

  // Same logic works for myString.
  // myString[i] is equivalent to myString[i] != '\0'
  // because '\0' is false and any other character is true.
  for (int i = 0; myString[i]; i++) {
    cout << "Character: " << myString[i] << endl;
  }

  cout << "\nLooping using pointer:\n";

  // Start at the first character and move one character at a time.
  for (char *ptr = myString; *ptr; ptr++) {
    cout << "Character: " << *ptr
         << endl; // Dereference to get the current character.
  }

  cout << "\nRange-based for loop:\n";

  // Includes the null terminator ('\0') as the last element.
  for (char ch : myString) {
    cout << "Character: " << ch << endl;
  }

  cout << "\nSkipping the null terminator:\n";

  for (char ch : myString) {
    if (ch == '\0')
      break;
    cout << "Character: " << ch << endl;
  }

  return 0;
}