#include <bits/stdc++.h>

using namespace std;

void explainPair () {
    pair <int, int> pair1 = {3,2};
    // pair <int, int> pair1 = make_pair (3,2); // another way of initializing pair
    cout << pair1.first << " " << pair.second << endl;

    pair <int, char> pair2 = {2, 'b'};
    cout << pair2.first << " " << pair.second << endl;

    pair <pair <int, char>, int> pair3 = {{4, 'c'}, 9};
    cout << pair3.first.first << " " << pair3.first.second << " - " << pair3.second << endl;

}

int main () {
    explainPair();
    return 0;
}