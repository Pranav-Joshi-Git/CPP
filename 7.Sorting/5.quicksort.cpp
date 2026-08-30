#include <iostream>
#include <utility>

using namespace std;


/*
    =========================
          QUICK SORT
    =========================

    Idea:
    - Choose an element as the pivot.
    - Rearrange the array so that:
          elements <= pivot are on the left
          elements > pivot are on the right
    - Place the pivot in its correct position.
    - Recursively apply the same process to the left and right portions.

    Mental Model:

        [ <= pivot | pivot | > pivot ]
                       ↑
                  final position

    Partitioning:
    - i moves from left to right looking for an element > pivot.
    - j moves from right to left looking for an element <= pivot.
    - If i < j, swap those two misplaced elements.
    - When i >= j, j is the position where the pivot belongs.

    !Time Complexity:
    - Best:    O(N log N)
    - Average: O(N log N)
    - Worst:   O(N²)
      (e.g. consistently choosing the smallest/largest element as pivot)

    !Space Complexity:
    - Average: O(log N) → recursive call stack
    - Worst:   O(N)     → recursive call stack
    - Sorting itself is in-place → O(1) extra array space
*/


/*
    Partition the portion of nums from [low ... high].

    Pivot:
        nums[low]

    After partitioning:

        [ elements <= pivot | pivot | elements > pivot ]

    Returns the final index of the pivot.
*/
int getPartitionIndex(vector<int> &nums, int low, int high) {

    // Choose the first element as the pivot
    int pivot = low;

    // i searches from the left for an element > pivot
    int i = low;

    // j searches from the right for an element <= pivot
    int j = high;


    while (i < j) {

        /*
            Move i to the right while the current element
            is already on the correct side of the pivot.

            Stop when:
            - nums[i] > pivot, OR
            - i reaches the end of the current portion.
        */
        while (nums[i] <= nums[pivot] && i <= high - 1) {
            i++;
        }


        /*
            Move j to the left while the current element
            is already on the correct side of the pivot.

            Stop when:
            - nums[j] <= pivot, OR
            - j reaches the beginning of the current portion.
        */
        while (nums[j] > nums[pivot] && j >= low + 1) {
            j--;
        }


        /*
            i found an element > pivot on the left side.
            j found an element <= pivot on the right side.

            These elements are on the wrong sides,
            so swap them.
        */
        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }


    /*
        i and j have crossed.

        j is now the correct position for the pivot.

        Put the pivot (currently at nums[low])
        into its final position.
    */
    swap(nums[low], nums[j]);

    return j;
}


/*
    Recursively apply Quick Sort to the portion [low ... high].

    Base Case:
    - If low >= high, there are 0 or 1 elements.
    - Such a portion is already sorted.
*/
void performQuickSort(vector<int> &nums, int low, int high) {

    if (low < high) {

        // Partition the current portion
        // and get the pivot's final position
        int pIndex = getPartitionIndex(nums, low, high);

        // Recursively sort the portion to the left of pivot
        performQuickSort(nums, low, pIndex - 1);

        // Recursively sort the portion to the right of pivot
        performQuickSort(nums, pIndex + 1, high);
    }
}


/*
    Wrapper function:
    Start Quick Sort for the complete array.
*/
void quickSort(vector<int>& nums) {
    performQuickSort(nums, 0, nums.size() - 1);
}


int main() {

    vector<int> vec = {13, 46, 24, 52, 20, 9};

    quickSort(vec);

    for (int i : vec) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}