// #include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int my_atoi(string s) {
  int i = 0;
  int n = s.length();

  // 1. Skip leading spaces
  while (i < n && s[i] == ' ') {
    i++;
  }

  // 2. Check sign
  int sign = 1;

  if (i < n && (s[i] == '+' || s[i] == '-')) {
    if (s[i] == '-') {
      sign = -1;
    }
    i++;
  }

  // 3. Build the number
  int result = 0;

  while (i < n && isdigit(s[i])) {

    int digit = s[i] - '0';

    // 4. Check overflow BEFORE multiplying
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }

    result = result * 10 + digit;
    i++;
  }

  return result * sign;
}

int main() {
  string str = "42";
  cout << my_atoi(str) << endl;
  string str1 = "-42";
  //   cout << "Front: " << str1.front() << endl;
  cout << my_atoi(str1) << endl;
  string str2 = "4193 with words";
  cout << my_atoi(str2) << endl;
  string str3 = "words and 987";
  cout << my_atoi(str3) << endl;
  string str4 = "-91283472332";
  cout << my_atoi(str4) << endl;
  string str5 = "2147483648";
  cout << my_atoi(str5) << endl;
  string str6 = "-2147483649";
  cout << my_atoi(str5) << endl;

  return 0;
}

// Implement atoi, converting a string to a 32-bit signed integer
// with proper overflow handling.
// # Example usage:
// print(my_atoi("42"))  # 42
// print(my_atoi("   -42"))  # -42
// print(my_atoi("4193 with words"))  # 4193
// print(my_atoi("words and 987"))  # 0
// print(my_atoi("-91283472332"))  # -2147483648
// print(my_atoi("2147483648"))  # 2147483647
// print(my_atoi("-2147483649"))  # -2147483648