#include <algorithm>
#include <iostream>

using namespace std;

// std::binary_search() requires the range to be sorted.
//
// It uses binary search internally, which repeatedly divides
// the search range in half.
//
// Because of this, the elements must be sorted before
// binary_search() is used.

int main() {

  int numbers[6] = {2, 4, 1, 7, 3, 9};

  cout << "Unsorted array: " << endl;

  for (int num : numbers) {
    cout << num << " ";
  }

  // Sort the array before using binary_search().
  sort(numbers, numbers + 6);

  cout << "\nSorted array: " << endl;

  for (int num : numbers) {
    cout << num << " ";
  }

  cout << endl;

  // binary_search() returns:
  // true  → value exists
  // false → value does not exist
  //
  // It searches between:
  // numbers     → beginning
  // numbers + 6 → one position after the last element

  if (binary_search(numbers, numbers + 6, 12)) {

    cout << "Number Found" << endl;

  } else {

    cout << "Number Not Found" << endl;
  }

  return 0;
}