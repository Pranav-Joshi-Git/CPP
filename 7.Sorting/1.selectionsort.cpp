
#include <iostream>
#include <utility>

using namespace std;


void selectionSort(vector<int> & nums) {
    int n = nums.size();

    // i represents the position where the next minimum should be placed
    for (int i = 0; i <= n - 2; i++) {

        // Assume current element is the minimum
        int mini = i;

        // Find the minimum element in the remaining unsorted portion
        for (int j = i + 1; j <= n - 1; j++) {
            if (nums[j] < nums[mini]) {
                mini = j;
            }
        }

        // Place the minimum element at the current position
        swap(nums[mini], nums[i]);
    }
}

int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};

    selectionSort(vec);

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}

/*
    Selection Sort

    Idea:
    - Divide the array into a sorted and an unsorted portion.
    - For each position i, find the minimum element in the unsorted portion.
    - Swap the minimum element with nums[i].
    - After each iteration, the sorted portion grows by one element.

    Example:
    [13, 46, 24, 52, 20, 9]
     ↓
    Find minimum (9) and place it at index 0
    [9, 46, 24, 52, 20, 13]
     ↓
    Find next minimum (13) and place it at index 1
    [9, 13, 24, 52, 20, 46]
     ↓
    Continue until the array is sorted.

    Time Complexity:
    - Best:    O(N²)
    - Average: O(N²)
    - Worst:   O(N²)

    Space Complexity:
    - O(1) → In-place sorting
*/