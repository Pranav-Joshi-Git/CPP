#include <iostream>
#include <list>

using namespace std;


// When to use:
//
// vector
// → Default choice for most DSA problems.
// → Use when you need fast random access and mostly work at the end.
//
// list
// → Use when you frequently insert/delete elements at known positions.
// → No random access using [].
//
// deque
// → Use when you need fast insertion/deletion from both front and back.
// → Also supports random access.


void explainList() {

    cout << "===== LIST =====" << endl;


    // list is implemented as a doubly linked list.
    // Elements do not need to be stored in continuous memory.

    list<int> ls = {6, 7};


    // Unlike vector, list provides push_front().
    ls.push_front(1);


    // emplace_front() is another way to add an element
    // at the beginning.
    ls.emplace_front(2);


    cout << "List: ";

    for (auto i : ls) {
        cout << i << " ";
    }

    cout << endl;


    // Most commonly used functions are similar to vector:
    //
    // push_back()
    // emplace_back()
    // pop_back()
    // pop_front()
    // front()
    // back()
    // size()
    // empty()
    // clear()
    // erase()
    // reverse()
    // sort()


    cout << "First element: " << ls.front() << endl;
    cout << "Last element: " << ls.back() << endl;
}


int main() {

    explainList();

    return 0;
}