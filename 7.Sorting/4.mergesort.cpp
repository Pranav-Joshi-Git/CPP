#include <iostream>

using namespace std;

/*
    Merge Sort

    Idea:
    - Divide the array into smaller halves recursively.
    - Continue dividing until each subarray contains one element.
    - Merge the smaller sorted subarrays back together.
    - During merging, compare elements from both halves and
      place the smaller element into a temporary array.

    Mental Model:

        [13, 46, 24, 52, 20, 9]
                  ↓
             Divide in half
          [13, 46, 24] [52, 20, 9]
             ↓              ↓
          Divide          Divide
             ↓              ↓
        [13] [46,24]    [52] [20,9]
             ↓              ↓
          ... continue until single elements
             ↓
        Merge sorted subarrays back together
             ↓
        [9, 13, 20, 24, 46, 52]

    !Time Complexity:
    - Best:    O(N log N)
    - Average: O(N log N)
    - Worst:   O(N log N)

    !Space Complexity:
    - O(N) → Temporary array used during merging
*/


/*
    Merge two sorted portions of nums:

        [low ... mid]     [mid+1 ... high]

    Both portions are already sorted.
    We merge them into temp in sorted order.
*/
void merge(vector<int> &nums, int low, int mid, int high) {

    vector<int> temp;

    // Pointers for the two sorted portions
    int left = low;
    int right = mid + 1;

    // Compare elements from both halves
    // and add the smaller one to temp
    while (left <= mid && right <= high) {

        if (nums[left] < nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    // Add any remaining elements from the left half
    while (left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    // Add any remaining elements from the right half
    while (right <= high) {
        temp.push_back(nums[right]);
        right++;
    }


    /*
        Copy the sorted elements from temp back into nums.

        IMPORTANT:
        temp always starts at index 0,
        but the merged portion of nums starts at index `low`.

        Example:

        nums:
        index →  0   1   2   3   4   5
                 X   X   |   X   X   X   X
                         ↑           ↑
                        low         high

        Suppose:
        low = 2
        high = 5

        temp:
        index →  0   1   2   3
                 13  20  24  46

        We need:

            nums[2] = temp[0]
            nums[3] = temp[1]
            nums[4] = temp[2]
            nums[5] = temp[3]

        Therefore:

            temp index = nums index - low
                       = i - low

        So:

            i = 2 → temp[2 - 2] = temp[0]
            i = 3 → temp[3 - 2] = temp[1]
            i = 4 → temp[4 - 2] = temp[2]
            i = 5 → temp[5 - 2] = temp[3]

        This works for EVERY recursive subarray,
        not just the first division.
    */

    for (int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}


/*
    Recursively divide the array into smaller portions.

    Base Case:
    - When low == high, the portion contains only one element.
    - A single element is already sorted.
*/
void mergeSort(vector<int> &nums, int low, int high) {

    if (low == high) {
        return;
    }

    // Find the middle of the current portion
    int mid = (low + high) / 2;

    // Sort the left half
    mergeSort(nums, low, mid);

    // Sort the right half
    mergeSort(nums, mid + 1, high);

    // Merge the two sorted halves
    merge(nums, low, mid, high);
}


/*
    Wrapper function:
    Start Merge Sort for the complete array.
*/
void performMergeSort(vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
}


int main() {

    vector<int> vec = {13, 46, 24, 52, 20, 9};

    performMergeSort(vec);

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}