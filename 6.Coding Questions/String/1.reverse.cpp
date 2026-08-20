#include <iostream>
#include <utility>

using namespace std;

string customReverse(string& st) {
    int len = st.length();
    string str = st;

    if(len == 0) return "";
    if(len == 1) return str;

    int left = 0;
    int right = len - 1;

    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }

    return str;
    // return string(st.rbegin(), st.rend());
}

int main() {
    string str = "hello";
    cout << customReverse(str) << endl;
    return 0;
}


// The function used takes a string s and returns a new string that is its 
// reverse by swapping characters from both ends. Here's the code using C++:
// Original: "hello"  →  Reversed: "olleh"
// Original: "racecar"  →  Reversed: "racecar"
// Original: ""  →  Reversed: ""
// Original: "A"  →  Reversed: "A"