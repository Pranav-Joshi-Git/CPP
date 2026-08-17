#include <iostream>
#include <queue>

using namespace std;


// Priority Queue
//
// Stores elements based on priority rather than insertion order.
//
// By default:
// → Highest element has the highest priority.
// → Internally uses a max heap.
//
// Example:
//
// 10
//  9
//  5
//  3
//  2
//
// top() → 10
//
//
// Commonly used functions:
//
// push()     → adds an element
// emplace()  → adds an element
// top()      → accesses the highest-priority element
// pop()      → removes the highest-priority element
// size()     → returns number of elements
// empty()    → checks whether priority queue is empty
// swap()     → swaps contents of two priority queues
//
// NOTE:
// priority_queue does not provide iterators.
//
//
// Minimum Priority Queue:
//
// priority_queue<int, vector<int>, greater<int>>
//
// → Smallest element gets the highest priority.
// → Internally behaves like a min heap.


void explainPriorityQueue() {

    // Default priority queue → Max Heap.
    // Largest element stays at the top.

    priority_queue<int> pq;

    pq.emplace(5);
    pq.emplace(2);
    pq.emplace(3);
    pq.emplace(10);
    pq.emplace(88);
    pq.emplace(9);


    // Minimum priority queue → Min Heap.
    // Smallest element stays at the top.

    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.emplace(5);
    pq2.emplace(2);
    pq2.emplace(3);
    pq2.emplace(10);
    pq2.emplace(88);
    pq2.emplace(9);


    // top() → highest-priority element.

    cout << "Max Heap Top: " << pq.top() << endl;

    // pop() → removes the highest-priority element.
    pq.pop();

    cout << "Max Heap Top after pop: " << pq.top() << endl;


    cout << "Max Heap: ";

    // To process all elements:
    // read top → process it → pop it.
    //
    // NOTE: This empties the priority queue.

    while (!pq.empty()) {

        cout << pq.top() << " ";

        pq.pop();
    }

    cout << endl;


    cout << "Min Heap Top: " << pq2.top() << endl;

    pq2.pop();

    cout << "Min Heap Top after pop: " << pq2.top() << endl;


    cout << "Min Heap: ";

    while (!pq2.empty()) {

        cout << pq2.top() << " ";

        pq2.pop();
    }

    cout << endl;
}


int main() {

    explainPriorityQueue();

    return 0;
}