#include <bits/stdc++.h>

using namespace std;

//Internally - vector uses an dynamic array.

void explainVector() {
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(0);
    vec.emplace_back(4); //another way to push element in vector.

    cout << "Size of vector: " << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    //access
    cout << vec[0] << endl;
    cout << vec.at(1) << endl;


    //insert
    vec.insert(vec.begin(), 4); // insert(location, value)

    //iterator
    vector<int>::iterator beginItr = vec.begin(); // returns a pointer where the first element is
    vector<int>::iterator endItr = vec.end(); //pointer to the location after the last element
    // auto endItr = vec.end(); // another way - automatically assings type of the operator
    cout << *beginItr << endl; //prints first element
    
    for (auto i = beginItr; i < endItr; i++){
        cout << *i << " ";
    }
    cout << endl;


    // for each loop on vector
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;


    //reverse iterator

    auto reverseBegin = vec.rbegin(); // points to last element
    auto reverseEnd = vec.rend(); // points to location before first element

    for (auto i = reverseBegin; i < reverseEnd; i++) { // reverse traversal, no need to do > or -- with i
        cout << *i << " ";
    }
    cout << endl;

    vector<int> vec2(5); // this will have 5 zeroes initially and we didn't mentioned what elements are in it, it assigned 0s
    // vector<int> vec2(5, 8); // this will have 5 8s into it
    // vector<int> vec2 = {7, 8} // adding 2 elements at the time of declaring the vector
    
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.emplace_back(6);

    for(auto i : vec2){
        cout << i << " ";
    }
    cout << endl;

    //duplicating the vectors
    vector<int> duplicateVec (vec); // creates duplicate vector using vec
    vector<int> duplicateVec2 (vec.beign() + 1, vec.end()); // creates duplicate skipping first element 

    cout << vec.front() << endl; // provides first element
    cout << vec.back() << endl; // provides last element
    cout << vec.pop_back() << endl; // removes last element


    //erase
    // vec.erase(vec.begin());//removes first element
    // vec.erase(vec.beign() + 2);//removes 3rd element

    // vec.erase(vec.begin()+1, vec.end()-1); // can provide range(start and end) to erase

    //clear
    vec.clear(); //clears entire vector

    //swap

    vector<int> vec1 = {5,6};
    vector<int> vec2 = {7,8};

    swap(vec1, vec2);


}

int main () {
    explainVector();
    return 0;
}