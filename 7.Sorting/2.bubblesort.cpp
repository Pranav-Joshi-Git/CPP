#include <iostream>

using namespace std;

/*
    Bubble Sort

    Idea:
    - Compare adjacent elements and swap them if they are in the wrong order.
    - After each pass, the largest unsorted element "bubbles" to the end.
    - The unsorted portion becomes smaller after every pass.

    Example:
    [13, 46, 24, 52, 20, 9]
        ↓
    Compare adjacent elements and swap when needed.
        ↓
    After the first pass, the largest element (52) reaches the end.
        ↓
    Repeat for the remaining unsorted portion.

    Time Complexity:
    - Best:    O(N²)
    - Average: O(N²)
    - Worst:   O(N²)

    Space Complexity:
    - O(1) → In-place sorting
*/

void bubbleSort(vector<int> &nums) {
    int n = nums.size();

    // i represents the last index of the current unsorted portion
    for (int i = n - 1; i >= 1; i--) {

        // Compare adjacent elements within the unsorted portion
        for (int j = 0; j <= i - 1; j++) {

            // Swap if elements are in the wrong order
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}


/*
    Optimized Bubble Sort

    Improvement:
    - If no swaps happen during a complete pass,
      the array is already sorted.
    - We can stop early instead of completing the remaining passes.

    Time Complexity:
    - Best:    O(N)    → Array is already sorted
    - Average: O(N²)
    - Worst:   O(N²)

    Space Complexity:
    - O(1) → In-place sorting
*/

void bubbleSortOptimized(vector<int> &nums) {
    int n = nums.size();

    // i represents the last index of the current unsorted portion
    for (int i = n - 1; i >= 1; i--) {

        // Tracks whether any swap happened during this pass
        bool swapped = false;

        // Compare adjacent elements
        for (int j = 0; j <= i - 1; j++) {

            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }

        // No swaps means the array is already sorted
        if (!swapped) {
            break;
        }
    }
}


int main() {

    vector<int> vec1 = {13, 46, 24, 52, 20, 9};
    vector<int> vec2 = {9, 13, 20, 24, 46, 52};

    // Normal Bubble Sort
    bubbleSort(vec1);

    for (int i : vec1) {
        cout << i << " ";
    }

    cout << endl;

    // Optimized Bubble Sort
    bubbleSortOptimized(vec2);

    for (int i : vec2) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}