#include <iostream>

using namespace std;

int main() {
  int nums[] = {12, 45, 7, 90, 23};

  int max = nums[0];

  for (int num : nums) {
    if(num > max){
        max = num;
    }
  }

  cout << "Largest = " << max << endl;

  return 0;
}

// 4. Find the Largest Number (Arrays + Loops + if)
// Given:
// int nums[] = {12, 45, 7, 90, 23};
// Find and print the largest number without using any built-in functions.
// Expected Output
// Largest = 90