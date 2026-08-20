#include <iostream>

using namespace std;

bool isAnagram(string & str1, string & str2){

    if(str1.length() != str2.length()) return false;
    if(str1.empty() && str2.empty()) return true;


    int charArr[256] = {0};
    for (int i = 0; i < str1.length(); i++) {
        charArr[str1[i]]++;
        charArr[str2[i]]--;
    }

    for (int i : charArr) {
        if(i!=0) return false;
    }

    return true;



}

int main() { 
    string str1 = "rat";
    string str2 = "car";
    cout << isAnagram(str1, str2) << endl;
    return 0; 
}



// Given two strings s and t, determine if t is an anagram of s
// (i.e., they contain the same characters in any order).
//  Example usage and expected output:
// console.log(isAnagram("anagram", "nagaram")); // true
// console.log(isAnagram("rat",     "car"));     // false
// console.log(isAnagram("aacc",    "ccac"));    // false
// console.log(isAnagram("",        ""));        // true