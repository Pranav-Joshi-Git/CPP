#include <bits/stdc++.h>

using namespace std;

// Internally - list and deque uses linked list
// deque - same as list or vector (functions)
// The primary difference between std::list and std::deque 
// in the C++ STL lies in their internal memory layout and random 
// access capabilities. While std::list is implemented as a doubly 
// linked list with elements scattered across memory, 
// std::deque (double-ended queue) uses a central map pointing to small, 
// fixed-size contiguous chunks of memory. As a result, std::deque supports O(1) 
// random access (indexing via []), whereas std::list does not support indexing 
// and requires O(N) sequential traversal.

// Add quick checklist here for when to use what? :

void explainList() {
    //almost similar to list except memory allocation - its not continuous
    list<int> ls = {6,7};    
    // in list we have push as front - which was not the case in vector
    ls.push_front(1);
    ls.emplace_front(2); //another way to push_front

    for (auto i : ls) {
        cout << i << " ";
    }
    cout << endl;

    //all remaining function in list are same as vector.

}


int main () {
    explainList();
    return 0;
}