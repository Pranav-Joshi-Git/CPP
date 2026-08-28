
#include <iostream>

using namespace std;

// ------------------------------------------------------------
// Print x, N times
// ------------------------------------------------------------
// Work happens BEFORE the recursive call.
// Therefore, printing happens while going DOWN.
//
// Example: x = 3, N = 5
// Output: 3 3 3 3 3
void printxNTimes(int x, int N) {
    if (N == 0) {
        return;
    }

    cout << x << endl;              // Work while going DOWN
    printxNTimes(x, N - 1);         // Recursive call
}


// ------------------------------------------------------------
// Print 1 to N — HEAD RECURSION
// ------------------------------------------------------------
// Recursive call happens BEFORE the work.
// Therefore, printing happens while COMING BACK.
//
// Going down: 5 → 4 → 3 → 2 → 1 → 0
// Coming back: 1 → 2 → 3 → 4 → 5
//
// Example: N = 5
// Output: 1 2 3 4 5
void print1ToNHeadRecursion(int N) {
    if (N == 0) {
        return;
    }

    print1ToNHeadRecursion(N - 1);  // Go deeper first
    cout << N << endl;              // Work while coming back
}


// ------------------------------------------------------------
// Print 1 to N — TAIL RECURSION
// ------------------------------------------------------------
// Work happens BEFORE the recursive call.
// We explicitly maintain the current value using 'i'.
//
// Example: N = 5
// Going down: 1 → 2 → 3 → 4 → 5
// Output: 1 2 3 4 5
void print1ToNTailRecursion(int i, int N) {
    if (i > N) {
        return;
    }

    cout << i << endl;              // Work while going DOWN
    print1ToNTailRecursion(i + 1, N);
}


// ------------------------------------------------------------
// Print N to 1 — TAIL RECURSION
// ------------------------------------------------------------
// Work happens BEFORE the recursive call.
// The value itself decreases on every call.
//
// Example: N = 5
// Going down: 5 → 4 → 3 → 2 → 1
// Output: 5 4 3 2 1
void printNTo1TailRecursion(int N) {
    if (N == 0) {
        return;
    }

    cout << N << endl;              // Work while going DOWN
    printNTo1TailRecursion(N - 1);
}


// ------------------------------------------------------------
// Print N to 1 — HEAD RECURSION
// ------------------------------------------------------------
// Recursive call happens BEFORE the work.
// We go from 1 → N while going down,
// then print N → 1 while coming back.
//
// Going down: 1 → 2 → 3 → 4 → 5
// Coming back: 5 → 4 → 3 → 2 → 1
//
// Example: N = 5
// Output: 5 4 3 2 1
void printNTo1HeadRecursion(int i, int N) {
    if (i > N) {
        return;
    }

    printNTo1HeadRecursion(i + 1, N); // Go deeper first
    cout << i << endl;               // Work while coming back
}


int main() {
    int x = 3;
    int N = 5;

    cout << "1. Print x N times (Tail Recursion):" << endl;
    printxNTimes(x, N);

    cout << "\n2. Print 1 to N (Head Recursion):" << endl;
    print1ToNHeadRecursion(N);

    cout << "\n3. Print 1 to N (Tail Recursion):" << endl;
    print1ToNTailRecursion(1, N);

    cout << "\n4. Print N to 1 (Head Recursion):" << endl;
    printNTo1HeadRecursion(1, N);

    cout << "\n5. Print N to 1 (Tail Recursion):" << endl;
    printNTo1TailRecursion(N);

    return 0;
}


//           WORK BEFORE RECURSION
//                  |
//      +-----------+-----------+
//      |                       |
//    1 → N                   N → 1
// current + 1              N - 1
//      |                       |
//      ↓                       ↓
//  Tail 1→N                Tail N→1


//           WORK AFTER RECURSION
//                  |
//      +-----------+-----------+
//      |                       |
//    1 → N                   N → 1
//      |                       |
//   N - 1                    i + 1
//      |                       |
//      ↓                       ↓
// Head 1→N                Head N→1