#include <iostream>
#include <set>

using namespace std;


// SET
//
// → Stores only UNIQUE elements.
// → Elements are automatically stored in ASCENDING order.
// → Does not allow duplicate values.
//
// Internally, std::set is generally implemented using
// a balanced binary search tree.
//
// Commonly used functions:
//
// insert()       → adds an element
// erase()        → removes an element
// find()         → returns iterator to an element
// count()        → checks whether an element exists
// size()         → returns number of elements
// empty()        → checks whether set is empty
// begin()        → iterator to first element
// end()          → iterator just after last element
// lower_bound()  → first element >= given value
// upper_bound()  → first element > given value
// clear()        → removes all elements
//
// Time complexity of insert/find/erase:
// O(log N)


void explainSet() {

    set<int> st;


    // insert() adds an element.
    //
    // Duplicate values are automatically ignored.

    st.insert(2);
    st.insert(29);
    st.insert(2);   // duplicate → ignored
    st.insert(12);
    st.insert(12);  // duplicate → ignored
    st.insert(21);
    st.insert(22);
    st.insert(22);  // duplicate → ignored
    st.insert(18);
    st.insert(17);
    st.insert(11);


    cout << "Set: ";

    // Elements are automatically printed in ascending order.
    for (auto i : st) {
        cout << i << " ";
    }

    cout << endl;


    // find() returns an iterator pointing to the element.
    //
    // If the element does not exist,
    // find() returns st.end().

    auto it = st.find(12);

    if (it != st.end()) {
        cout << "Found: " << *it << endl;
    }


    // count()
    //
    // For a set, count() returns:
    // 1 → element exists
    // 0 → element doesn't exist
    //
    // Useful when we only want to check existence.

    cout << "Does 21 exist? " << st.count(21) << endl;


    // erase(value) removes the given value.

    st.erase(21);


    cout << "After erasing 21: ";

    for (auto i : st) {
        cout << i << " ";
    }

    cout << endl;


    // end() points just AFTER the last element.
    //
    // To access the last element:
    // move one step backwards.

    auto it2 = st.end();

    --it2;

    st.erase(it2);


    cout << "After erasing last element: ";

    for (auto i : st) {
        cout << i << " ";
    }

    cout << endl;


    // LOWER BOUND
    //
    // Returns an iterator pointing to the first element
    // that is >= the given value.

    auto it_lb = st.lower_bound(11);

    if (it_lb != st.end()) {
        cout << "Lower bound of 11: " << *it_lb << endl;
    }


    // If no element satisfies the condition,
    // lower_bound() returns st.end().


    // UPPER BOUND
    //
    // Returns an iterator pointing to the first element
    // that is > the given value.

    auto it_ub = st.upper_bound(22);

    if (it_ub != st.end()) {
        cout << "Upper bound of 22: " << *it_ub << endl;
    }


    // RANGE ERASE
    //
    // erase(first, last)
    //
    // Removes elements from first iterator
    // up to, but NOT including, last iterator.

    auto it3 = st.begin();

    ++it3;

    auto it4 = st.end();

    --it4;
    --it4;

    st.erase(it3, it4);


    cout << "After range erase: ";

    for (auto i : st) {
        cout << i << " ";
    }

    cout << endl;
}


int main() {

    explainSet();

    return 0;
}