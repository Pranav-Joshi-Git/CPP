#include <iostream>

using namespace std;

int main () {
    int nums [] = {10,20,30,40,50};
    int sum = 0;
    for(int num : nums) {
        sum += num;
    }
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}





// 1. Sum of Array (Loops + Arrays)

// Write a program that:

// Creates an integer array {10, 20, 30, 40, 50}.
// Uses a for loop to calculate the sum.
// Prints the final sum.

// Expected Output

// Sum = 150