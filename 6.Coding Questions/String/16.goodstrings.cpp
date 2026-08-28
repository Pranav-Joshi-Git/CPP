#include <iostream>

using namespace std;

int main() {
  int testCases;
  vector<string> inp;
  vector<string> output;
  cin >> testCases;
  for (int i = 0; i < testCases; i++) {
    string temp;
    cin >> temp;
    inp.push_back(temp);
  }

  for (string temp : inp) {
    for (int j = 0; j < temp.length();) {
      if (j < temp.length() - 1 && temp[j] == temp[j + 1]) {
        temp.erase(j, 1); // don't increment j; the next char shifted into index j
      } else {
        j++;
      }
    }
    output.push_back(temp);
    cout << temp << endl;
  }

  cout << "\nOutput:\n" << endl;

  return 0;
}

// Jon is very fond of strings. (Or so he thinks!) But, he does not like strings
// which have same consecutive letters. No one has any idea why it is so. He
// calls these strings as Bad strings. So, Good strings are the strings which do
// not have same consecutive letters. Now, the problem is quite simple. Given a
// string S, you need to convert it into a Good String. You simply need to
// perform one operation - if there are two same consecutive letters, delete one
// of them.

// Input:

// The first line contains an integer T, denoting the number of test cases.

// The next T lines contains the test cases consisting of a string S, which
// consists of only lower case letters.

// Output:

// For each test case, print the answer to the given problem.

// Constraints:

// 1 <= T <= 10 1 <= |S| <= 30

// Sample Input

// 4

// abb
// aaab
// ababa
// aabbaa

// Sample Output
// ab
// ab
// ababa
// ab
