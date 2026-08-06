#include <cmath>
#include <iostream>

using namespace std;

int main() {

  cout << "Size of float       : " << sizeof(float) * 8 << " bits" << endl;
  cout << "Size of double      : " << sizeof(double) * 8 << " bits" << endl;
  cout << "Size of long double : " << sizeof(long double) * 8 << " bits\n"
       << endl;

  float preciseValue = 20.2;

  cout << "Value: " << preciseValue << endl;

  printf("%f\n", preciseValue);      // Prints 20.200001 (or a very close value)
  printf("%.30f\n\n", preciseValue); // Print 30 digits after the decimal point.

  // Floating-point numbers cannot exactly represent many decimal values.
  // Therefore, comparing them using == is unreliable.
  float myFloat = 20.2 + 20.2;

  if (myFloat == 40.4) {
    cout << "Exactly equal" << endl;
  } else {
    cout << "Not exactly equal (precision issue)" << endl;
  }

  // Small tolerance for floating-point comparison.
  float epsilon = 0.0001f;

  // If the difference is within epsilon,
  // consider the two floating-point values equal.
  if (fabs(myFloat - 40.4f) < epsilon) {
    cout << "Approximately equal" << endl;
  }

  return 0;
}