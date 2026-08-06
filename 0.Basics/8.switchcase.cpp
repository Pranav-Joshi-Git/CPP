#include <iostream>

using namespace std;

int main() {

  int rating = 7;

  // switch is used when comparing one variable against multiple constant values.
  switch (rating) {

  case 1:
    cout << "Rating is 1 Star" << endl;
    break; // Exit the switch after executing this case.

  case 2:
    cout << "Rating is 2 Stars" << endl;
    break;

  case 3:
    cout << "Rating is 3 Stars" << endl;
    break;

  case 4:
    cout << "Rating is 4 Stars" << endl;
    break;

  case 5:
    cout << "Rating is 5 Stars" << endl;
    break;

  default: // Executes when no case matches.
    cout << "Rating is not available" << endl;
    break;
  }

  return 0;
}