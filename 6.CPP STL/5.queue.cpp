#include <iostream>
#include <queue>

using namespace std;


// FIFO -> First In First Out
//
// Think of a normal queue:
//
// Front                         Back
//   ↓                             ↓
//  [2] → [21] → [12] → [24] → [25]
//
// 2 will leave first because it entered first.
//
// Use queue when you need:
// → First-in-first-out behavior
// → BFS
// → Processing items in arrival order


void explainQueue() {

    queue<int> q;


    // push() adds an element to the back.
    q.push(2);
    q.push(21);
    q.push(12);
    q.push(24);
    q.push(25);


    // front() → access the first element.
    // back()  → access the last element.
    // pop()   → removes the first element.
    //
    // Queue does not provide iterators.

    while (q.empty() == false) {

        cout << q.front() << " ";

        q.pop();
    }


    // Other commonly used functions:
    //
    // size()
    // empty()
    // front()
    // back()
    // push()
    // emplace()
    // pop()
    // swap()
}


int main() {

    explainQueue();

    return 0;
}