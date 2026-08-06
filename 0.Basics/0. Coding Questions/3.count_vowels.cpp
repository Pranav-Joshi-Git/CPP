#include <iostream>

using namespace std;

int main() {

  char name[] = "Pranav";

  int vowelsCount = 0;

  for (char ch : name) {
    if (ch == '\0') {
      break;
    }
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      vowelsCount++;
    }
  }

  cout << "Vowels: " << vowelsCount << endl;

  return 0;
}

// 3. Count Vowels (C-style Strings + Loops)
// Given:
// char name[] = "Pranav";
// Count how many vowels (a, e, i, o, u) are present and print the count.
// Expected Output
// Vowels = 2