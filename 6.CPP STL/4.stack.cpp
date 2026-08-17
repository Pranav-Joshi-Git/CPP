#include <iostream>
#include <stack>

using namespace std;


// LIFO - Last In First Out
//
// Think of a stack of plates:
//
//     27  ← top
//     17
//     73
//     71
//     7
//     1
//
// The last element added is the first one removed.
//
// Use stack when you need:
// → Last-in-first-out behavior
// → Undo operations
// → Bracket matching
// → DFS / recursion-related problems
// → Monotonic stack problems


void explainStack() {

    stack<int> st;


    // push() adds an element to the top.
    st.push(1);
    st.push(7);
    st.push(71);
    st.push(73);
    st.push(17);
    st.push(27);

    // emplace() is another way to add an element to the top.
    st.emplace(79);


    cout << "Size: " << st.size() << endl;


    // Stack does not provide iterators.
    // We can only directly access the top element.
    //
    // Commonly used functions:
    //
    // push()     → adds an element to the top
    // emplace()  → adds an element to the top
    // pop()      → removes the top element
    // top()      → accesses the top element
    // size()     → returns number of elements
    // empty()    → checks whether stack is empty
    // swap()     → swaps contents of two stacks


    cout << "Top: " << st.top() << " ";

    // pop() removes the top element.
    st.pop();

    cout << "Top: " << st.top() << " ";

    st.pop();

    cout << "Top: " << st.top() << endl;


    // To process all elements:
    // read the top → process it → pop it.
    //
    // NOTE: This will empty the stack.

    cout << "Remaining elements: ";

    while (!st.empty()) {

        cout << st.top() << " ";

        st.pop();
    }

    cout << endl;
}


int main() {

    explainStack();

    return 0;
}