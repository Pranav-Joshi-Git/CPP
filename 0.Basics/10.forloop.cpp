#include <iostream>

using namespace std;

int main() {

    // Size is inferred from the number of elements.
    int myNums[] = {2, 3, 4, 5, 6};

    // for loop:
    // initialization; condition; update
    for (int i = 0; i < 5; i++) {
        cout << "Current Number is: " << myNums[i] << endl;
    }

    cout << "\nRange-based for loop:" << endl;

    // 'num' is each element of the array.
    // No index is needed.
    for (int num : myNums) {
        cout << num << endl;
    }

    return 0;
}