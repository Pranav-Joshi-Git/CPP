#include <iostream>
#include <queue>

using namespace std;


int main() {

    // queue follows FIFO:
    //
    // First In → First Out
    //
    // The first element inserted is the first element removed.
    //
    // Think of a real-world queue:
    //
    // 10 → 12 → 14 → 16 → 18
    // ↑                    ↑
    // front                back

    queue<int> myQueue;


    // push() adds an element to the back of the queue.
    myQueue.push(10);
    myQueue.push(12);
    myQueue.push(14);
    myQueue.push(16);
    myQueue.push(18);


    cout << "First Value: " << myQueue.front() << endl;
    cout << "Last Value: " << myQueue.back() << endl;


    // pop() removes the element from the front.
    myQueue.pop();

    cout << "First Value: " << myQueue.front() << endl;
    cout << "Last Value: " << myQueue.back() << endl;


    // A queue doesn't provide normal iterators.
    // To process every element, we can repeatedly:
    //
    // 1. Read front()
    // 2. Process it
    // 3. pop() it
    //
    // IMPORTANT:
    // This empties the queue.

    while (!myQueue.empty()) {

        cout << myQueue.front() << " ";

        myQueue.pop();
    }

    cout << endl;
    cout << "Outside Loop" << endl;


    // The queue is now empty.
    //
    // DO NOT do this:
    //
    // cout << myQueue.front() << endl;
    //
    // Calling front() on an empty queue is invalid/undefined behavior.


    // ---------------------------------------------------------
    // Priority Queue
    // ---------------------------------------------------------


    // priority_queue does NOT follow normal FIFO ordering.
    //
    // The element with the highest priority comes to the top.
    //
    // For priority_queue<int>, the largest value has
    // the highest priority by default.

    priority_queue<int> myPrioQueue;

    myPrioQueue.push(10);
    myPrioQueue.push(40);
    myPrioQueue.push(50);
    myPrioQueue.push(5);


    // top() → gives the highest-priority element.
    //
    // pop() → removes the highest-priority element.

    while (!myPrioQueue.empty()) {

        cout << myPrioQueue.top() << " ";

        myPrioQueue.pop();
    }

    cout << endl;


    return 0;
}