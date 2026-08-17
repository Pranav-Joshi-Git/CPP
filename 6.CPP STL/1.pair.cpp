#include <iostream>

using namespace std;


void explainPair() {

    // pair stores exactly two values.
    // The two values can be of different data types.

    pair<int, int> pair1 = {3, 2};

    // Another way of creating a pair:
    // pair<int, int> pair1 = make_pair(3, 2);

    cout << pair1.first << " " << pair1.second << endl;


    // The two values don't have to be of the same type.

    pair<int, char> pair2 = {2, 'b'};

    cout << pair2.first << " " << pair2.second << endl;


    // A pair can also contain another pair.

    pair<pair<int, char>, int> pair3 = {{4, 'c'}, 9};

    cout << pair3.first.first
         << " "
         << pair3.first.second
         << " - "
         << pair3.second
         << endl;
}


int main() {

    explainPair();

    return 0;
}