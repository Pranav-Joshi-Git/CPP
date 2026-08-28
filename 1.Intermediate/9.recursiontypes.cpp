#include <iostream>

using namespace std;

// HEAD RECURSION:
// Recursive call happens FIRST, then the actual work is performed.
// Therefore, the work happens while the calls are RETURNING / UNWINDING.
//
// For count = 5:
// 5 → 4 → 3 → 2 → 1 → 0
// Then while returning:
// 1 → 2 → 3 → 4 → 5
void headRecursion(int count) {
    if (count > 0) {
        headRecursion(count - 1);  // Go deeper first
        cout << count << " ";      // Work happens while coming back
    }
}

// TAIL RECURSION:
// Actual work happens FIRST, and the recursive call is the LAST operation.
// Therefore, the work happens while going DOWN.
// There is no work left to perform after the recursive call returns.
//
// For count = 5:
// Print 5 → 4 → 3 → 2 → 1 → 0
void tailRecursion(int count) {
    if (count > 0) {
        cout << count << " ";      // Work happens first
        tailRecursion(count - 1);  // Recursive call happens last
    }
}

int main() {
    int count = 5;

    cout << "Head Recursion: ";
    headRecursion(count);
    cout << endl;

    cout << "Tail Recursion: ";
    tailRecursion(count);
    cout << endl;

    return 0;
}


// **Quick mental model:**

// HEAD:
//     Recursive call
//           ↓
//         Work
//     → Work happens while RETURNING

// TAIL:
//         Work
//           ↓
//     Recursive call
//     → Work happens while GOING DOWN

// TIME COMPLEXITY:
// Based on the total number of recursive calls.
// One recursive call per level × n levels → O(n).

// SPACE COMPLEXITY:
// Based on maximum recursion depth (call stack).
// n active recursive calls → O(n) stack space.


// NOTE:
// "n recursive calls" does NOT always mean O(n) time.
// Multiple recursive calls can create a recursion tree,
// potentially making time complexity O(2^n), etc.


// HEAD RECURSION vs TAIL RECURSION
//
// Aspect                 | Head Recursion             | Tail Recursion
// -----------------------|----------------------------|---------------------------
// Order of execution     | Recursive call first       | Work first
// Work timing            | Work while returning       | Work while going down
// Loop conversion        | Usually less direct        | Usually straightforward
// Tail-call optimization | Not applicable             | May be optimized