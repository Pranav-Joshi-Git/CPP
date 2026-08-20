#include <cctype>
#include <iostream>

using namespace std;

bool isCustomPalindrome(string &str) {
  int left = 0;
  int right = str.length() - 1;
  while (left < right) {
    if (!isalnum(str[left])) {
      left++;
      continue;
    }
    if (!isalnum(str[right])) {
      right--;
      continue;
    }
    if (tolower(str[left]) != tolower(str[right])) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

int main() {
  string st = "A man, a plan, a canal: Panama";
  cout << isCustomPalindrome(st) << endl;
  return 0;
}

// Determine whether a given string reads the same forwards and backwards,
// ignoring non-alphanumeric characters and case
// (e.g., “A man, a plan, a canal: Panama” → true).