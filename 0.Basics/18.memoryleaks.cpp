#include <iostream>

using namespace std;

int main() {

    try {

        // 'new' dynamically allocates memory on the heap.
        // This creates an array of 10,000 integers.
        int* myPointer = new int[10000];

        cout << "Memory space allocated successfully." << endl;

        // Use the allocated memory here...
        myPointer[0] = 100;
        cout << "First value: " << myPointer[0] << endl;

        // IMPORTANT:
        // Memory allocated with 'new[]' must be released using 'delete[]'.
        // Otherwise, the memory becomes a memory leak.
        delete[] myPointer;

        cout << "Memory released." << endl;

        // After delete[], the pointer still contains the old address,
        // but that memory is no longer valid to access.
        // Do not use myPointer to read or write memory after delete[].

    } catch (...) {

        // new throws an exception if memory allocation fails.
        cout << "Failed to allocate memory." << endl;
    }

    return 0;
}