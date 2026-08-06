#include <iostream>

using namespace std;

int main() {

  int num;
  cout << "Enter a number: ";
  cin >> num;

  if (num % 2 == 0) {
    cout << "even" << endl;
  } else {
    cout << "odd" << endl;
  }

  return 0;
}

// 2. Even or Odd (Conditionals)
//  Take an integer input from the user and print:
//  "Even" if the number is even.
//  "Odd" otherwise.
//  Example
//  Input:
//  7
//  Output:
//  Odd