#include <iostream>
#include <vector>

using namespace std;


// Internally, vector uses a dynamic array.
// It stores elements in continuous memory.

void explainVector() {

    cout << "\n===== Creating and Adding Elements =====\n";

    vector<int> vec;

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(0);

    // emplace_back() is another way to add an element
    // at the end of the vector.
    vec.emplace_back(4);


    cout << "Vector: ";

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << "\nSize of vector: " << vec.size() << endl;


    cout << "\n===== Accessing Elements =====\n";

    // Access using [].
    cout << "First element using []: " << vec[0] << endl;

    // Access using at().
    cout << "Second element using at(): " << vec.at(1) << endl;


    cout << "\n===== Inserting Elements =====\n";

    // insert(location, value)
    // Inserts 4 at the beginning.
    vec.insert(vec.begin(), 4);

    cout << "After inserting 4 at beginning: ";

    for (auto i : vec) {
        cout << i << " ";
    }

    cout << endl;


    cout << "\n===== Iterators =====\n";

    // begin() → iterator pointing to the first element.
    // end()   → iterator pointing just after the last element.

    vector<int>::iterator beginItr = vec.begin();
    vector<int>::iterator endItr = vec.end();

    // auto can also automatically determine the iterator type.
    // auto endItr = vec.end();

    cout << "First element using begin(): "
         << *beginItr << endl;


    cout << "Traversing using iterators: ";

    for (auto i = beginItr; i != endItr; i++) {
        cout << *i << " ";
    }

    cout << endl;


    cout << "\n===== Range-Based For Loop =====\n";

    for (auto i : vec) {
        cout << i << " ";
    }

    cout << endl;


    cout << "\n===== Reverse Iterators =====\n";

    // rbegin() → points to the last element.
    // rend()   → points just before the first element.

    auto reverseBegin = vec.rbegin();
    auto reverseEnd = vec.rend();

    cout << "Reverse traversal: ";

    for (auto i = reverseBegin; i != reverseEnd; i++) {
        cout << *i << " ";
    }

    cout << endl;


    cout << "\n===== Creating Vectors with Initial Values =====\n";

    // Creates a vector containing 5 zeros.
    vector<int> vec2(5);

    // Creates a vector containing five 8s:
    // vector<int> vec2(5, 8);

    // Creates a vector with the given elements:
    // vector<int> vec2 = {7, 8};


    vec2.push_back(4);
    vec2.push_back(5);
    vec2.emplace_back(6);


    cout << "vec2: ";

    for (auto i : vec2) {
        cout << i << " ";
    }

    cout << endl;


    cout << "\n===== Copying Vectors =====\n";

    // Creates a complete copy of vec.
    vector<int> duplicateVec(vec);

    cout << "Complete copy: ";

    for (auto i : duplicateVec) {
        cout << i << " ";
    }

    cout << endl;


    // Creates a copy starting from the second element.
    vector<int> duplicateVec2(vec.begin() + 1, vec.end());

    cout << "Copy from second element: ";

    for (auto i : duplicateVec2) {
        cout << i << " ";
    }

    cout << endl;


    cout << "\n===== Front and Back =====\n";

    // front() → first element.
    // back()  → last element.

    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;


    cout << "\n===== Erasing Elements =====\n";

    // pop_back() removes the last element.
    // vec.pop_back();

    // erase() removes an element or a range of elements.

    // Removes first element:
    // vec.erase(vec.begin());

    // Removes third element:
    // vec.erase(vec.begin() + 2);

    // Removes a range:
    // vec.erase(vec.begin() + 1, vec.end() - 1);


    cout << "\n===== Clearing Vector =====\n";

    // clear() removes all elements from the vector.
    vec.clear();

    cout << "Size after clear(): " << vec.size() << endl;


    cout << "\n===== Swapping Vectors =====\n";

    vector<int> vec1 = {5, 6};
    vector<int> vec3 = {7, 8};

    cout << "Before swap:" << endl;

    cout << "vec1: ";
    for (auto i : vec1) {
        cout << i << " ";
    }

    cout << endl;

    cout << "vec3: ";
    for (auto i : vec3) {
        cout << i << " ";
    }

    cout << endl;


    // swap() exchanges the contents of two vectors.
    swap(vec1, vec3);


    cout << "After swap:" << endl;

    cout << "vec1: ";
    for (auto i : vec1) {
        cout << i << " ";
    }

    cout << endl;

    cout << "vec3: ";
    for (auto i : vec3) {
        cout << i << " ";
    }

    cout << endl;
}


int main() {
    explainVector();
    return 0;
}