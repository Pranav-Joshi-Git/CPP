#include <iostream>
#include <list>

using namespace std;


// std::vector
// - Stores elements in continuous memory.
// - Fast random access using [].
// - Inserting/removing from the middle can be expensive.
//
// std::list
// - Stores elements as separate nodes connected through pointers.
// - Does NOT require continuous memory.
// - No direct/random access using [].
// - Traversing to a particular position is O(n).
// - Inserting/removing elements at a known position is efficient.
//
// Think:
// vector → fast access
// list   → efficient insertion/deletion when position is known


int main() {

    list<int> myList;


    // push_back() adds an element to the end of the list.
    for (int i = 3; i <= 10; ++i) {
        myList.push_back(i);
    }


    // front() → first element
    // back()  → last element

    cout << "First Element: " << myList.front() << endl;
    cout << "Last Element: " << myList.back() << endl;


    // pop_back() removes the last element.
    myList.pop_back();


    // reverse() reverses the order of elements.
    myList.reverse();


    cout << "After reverse: ";

    for (auto i : myList) {
        cout << i << " ";
    }

    cout << endl;


    // sort() sorts the elements in ascending order.
    //
    // list has its own sort() member function because
    // std::sort() requires random-access iterators,
    // while list provides bidirectional iterators.

    myList.sort();


    cout << "After sort: ";

    for (auto i : myList) {
        cout << i << " ";
    }

    cout << endl;


    return 0;
}