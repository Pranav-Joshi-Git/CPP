#include <iostream>
#include <utility>

using namespace std;

/*
    Insertion Sort

    Idea:
    - Treat the left portion of the array as sorted.
    - Pick the current element from the unsorted portion.
    - Move it left until it reaches its correct position.
    - The sorted portion grows by one element after each iteration.

    Mental Model:
    [ Sorted Portion | Unsorted Portion ]
                       ↑
                  Pick current element
                       ↓
              Move it left until
              it is in the right place.

    Example:
    [13, 46, 24, 52, 20, 9]

    13 is already sorted.
    Insert 46 → [13, 46]
    Insert 24 → [13, 24, 46]
    Insert 52 → [13, 24, 46, 52]
    Insert 20 → [13, 20, 24, 46, 52]
    Insert 9  → [9, 13, 20, 24, 46, 52]

    Time Complexity:
    - Best:    O(N)    → Array is already sorted
    - Average: O(N²)
    - Worst:   O(N²)   → Array is sorted in reverse order

    Space Complexity:
    - O(1) → In-place sorting
*/

void insertionSort(vector<int> &nums) {
    int n = nums.size();

    // Start from index 1 because the first element is already sorted
    for (int i = 1; i < n; i++) {

        // j represents the current element being inserted
        int j = i;

        // Move the current element left while it is smaller
        // than the element immediately before it
        while (j > 0 && nums[j - 1] > nums[j]) {

            // Swap with the previous element
            swap(nums[j - 1], nums[j]);

            // Continue moving left
            j--;
        }
    }
}


int main() {
    vector<int> vec = {13, 46, 24, 52, 20, 9};

    insertionSort(vec);

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}