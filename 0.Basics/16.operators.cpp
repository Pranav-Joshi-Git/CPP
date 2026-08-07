#include <iostream>

using namespace std;

int main() {

  int life = 3;
  int points = 4;

  // Assignment operator.
  int score = points;

  // Arithmetic operators: +, -, *, /, %
  score = points + life;

  // Unary operator (negation).
  score = -points;

  // Compound assignment.
  // Preferred over: score = score + points;
  // It is shorter, clearer, and for some user-defined types (e.g. std::string)
  // it can also avoid creating temporary objects.
  score += points;

  // Comparison operators: ==, !=, <, >, <=, >=
  if (life == 0) {
    cout << "Inside if block" << endl;
  }

  bool signedIn = true;
  bool admin = true;
  bool isFbUser = false;
  bool isGoogleUser = true;

  // Logical AND (&&): both conditions must be true.
  if (admin && signedIn) {
    cout << "Welcome Admin!" << endl;
  } else {
    cout << "No admin access" << endl;
  }

  // Logical OR (||): at least one condition must be true.
  // Parentheses improve readability.
  if ((isFbUser || isGoogleUser) && signedIn) {
    cout << "Welcome User!" << endl;
  }

  return 0;
}