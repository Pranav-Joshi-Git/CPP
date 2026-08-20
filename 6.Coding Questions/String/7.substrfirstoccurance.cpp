#include <iostream>

using namespace std;

int getFirstOccurance(string & haystack, string & needle) {   
    // using built in function
    // int pos = haystack.find(needle);
    // if (pos == string::npos) {
    //     return -1;
    // }
    // return pos;

    //own logic
    for (int i = 0; i < haystack.length(); i++) {
        if (needle[0] == haystack [i]) {
            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string haystack = "hello";
    string needle = "ll";
    cout << getFirstOccurance(haystack, needle) << endl;
    return 0;
}

// Return the index of the first occurrence of needle in haystack, 
// or -1 if not found (e.g., “hello”, “ll” → 2). 
// strStr(haystack, needle)