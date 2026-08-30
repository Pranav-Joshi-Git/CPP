#include <iostream>
#include <utility>

using namespace std;


int getPartitionIndex (vector<int> & nums, int low, int high) {
    int pivot = low;
    int i = low;
    int j = high;

    while (i < j) {
        while(nums[i] <= nums[pivot] && i <= high-1) {
            i++;
        }
        while(nums[j] > nums[pivot] && j >= low+1) {
            j--;
        }

        if(i < j) {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[low], nums[j]);
    return j;
}

void performQuickSort(vector<int> &nums, int low, int high) {
    if(low < high) {

        int pIndex = getPartitionIndex(nums, low, high);
        performQuickSort(nums, low, pIndex - 1);
        performQuickSort(nums, pIndex+1, high);
    }
}


void quickSort(vector<int>& nums) {
    performQuickSort(nums, 0, nums.size()-1);
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