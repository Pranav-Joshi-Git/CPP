#include <iostream>
#include <map>

using namespace std;

bool isIsomorphic (string & str1, string & str2) {

    if (str1.length() != str2.length()) return false;

    map <char, int> map1;
    map <char, int> map2;

    for (int i=0; i < str1.length(); i++) {
        if (map1[str1[i]] != map2[str2[i]]) {
            return false;
        }
        map1[str1[i]] = i + 1;
        map2[str2[i]] = i + 1;
    }

    return true;

}

int main() {
    string str1 = "egg";
    string str2 = "add";
    string str3 = "foo";
    string str4 = "bar";
    string str5 = "paper";
    string str6 = "title";
    
    cout << isIsomorphic(str1, str2) << endl;
    cout << isIsomorphic(str3, str4) << endl;
    cout << isIsomorphic(str5, str6) << endl;
    return 0;
}


// Given two strings s and t, determine if they are isomorphic.
// Example usage:
// console.log(isIsomorphic("egg", "add"));  // Output: true
// console.log(isIsomorphic("foo", "bar"));  // Output: false
// console.log(isIsomorphic("paper", "title"));  // Output: true