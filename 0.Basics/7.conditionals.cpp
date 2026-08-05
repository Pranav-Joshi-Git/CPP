#include <iostream>

using namespace std;

int main() {

  int marks = 78;

  // if - else if - else
  if (marks >= 90) {
    cout << "Grade: A" << endl;
  } else if (marks >= 75) {
    cout << "Grade: B" << endl;
  } else {
    cout << "Grade: C" << endl;
  }

  // Truthy/Falsy:
  // 0, NULL (or nullptr) -> false
  // Any non-zero value (1, -1, 42, ...) -> true
  int isLoggedIn = 1;

  if (isLoggedIn) {
    cout << "User is logged in." << endl;
  }

  // Ternary operator: (condition) ? true_value : false_value
  cout << "Result: " << (marks >= 35 ? "Pass" : "Fail") << endl;

  return 0;
}