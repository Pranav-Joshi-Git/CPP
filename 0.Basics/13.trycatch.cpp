#include <iostream>

using namespace std;

int main() {

  // Uncomment one at a time to test different catch blocks.
  // int callApi = 2;
  // float callApi = 2.0;
  char callApi = 2;

  try {
    cout << "Trying to use API value" << endl;
    cout << "Did some testing" << endl;

    throw callApi; // Throw an exception.

    // No code executes after throw.
    cout << "This line will never execute." << endl;

    // The catch block must match the type of the value thrown.
  } catch (int err) {
    cout << "Integer exception handled" << endl;
  } catch (float err) {
    cout << "Float exception handled" << endl;
  } catch (...) { // Fallback: handles any exception not caught above.
    cout << "Unknown exception handled" << endl;
  }

  // Program continues after the exception is handled.
  cout << "Keep on moving with next part of the code" << endl;

  return 0;
}