#include <iostream>
#include <string>

using namespace std;

int main() {
  int number;
  string name;

  cout << "Enter a number: ";
  cin >> number; // Reads a single value (stops at whitespace).

  // Remove the leftover '\n' from the input buffer.
  // Without this, getline() will read the newline instead of waiting for input.
  cin.ignore();

  cout << "Enter your name: ";
  getline(cin, name); // Reads the entire line, including spaces. Use only with strings.

  cout << "Welcome " << name << "! Your ID is " << 1000 + number << endl;

  return 0;
}