#include <iostream>

using namespace std;

// Function with no return value.
void sayHello() { cout << "Hello from function!" << endl; }

// Function that returns an integer.
int getLuckyNumber() { return 7; }

void printMessage() { cout << "Learning C++ Functions" << endl; }

int main() {

  sayHello();

  // The returned value can be used in an expression.
  cout << getLuckyNumber() + 3 << endl;

  printMessage();

  return 0;
}