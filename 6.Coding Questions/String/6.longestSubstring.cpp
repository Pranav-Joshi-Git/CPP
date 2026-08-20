#include <iostream>

using namespace std;

int lengthOfLongestSubstringBruteForce (string & str) {
    int maxLength = 0;
    for (int i = 0; i < str.length(); i++) {
        int charHash[255] = {0};
        for (int j = i; j < str.length(); j++) {
            if(charHash[str[j]] == 1) {
                break;
            }
            maxLength = max(maxLength, j-i+1);
            charHash[str[j]] = 1;
        }
    }
    return maxLength;
}

int lengthOfLongestSubstringOptimized (string & str) {
    int hashArr[256] = {-1};
    fill(hashArr, hashArr + 256, -1);
    int left = 0;
    int right = 0;
    int maxLength = 0;

    while (right < str.length()) {
        if(hashArr[str[right]] != -1) {
            if(hashArr[str[right]] >= left) {
                left = hashArr[str[right]] + 1;
            }
        }
        int len = right - left + 1;
        maxLength = max (len, maxLength);
        hashArr[str[right]] = right;
        right++;
    }
    return maxLength;
}


int main() {
    // string s = "abcabcbb";
    // string s = "bbbbb";
    // string s = "abcdef";
    string s = "abca";
    cout << lengthOfLongestSubstringBruteForce(s) << endl;
    cout << lengthOfLongestSubstringOptimized(s) << endl;
    return 0;
}

// Given a string s, find the length of the longest substring without repeating 
// characters (e.g., “abcabcbb” → 3).
// Example usage
// let s = "abcabcbb";
// console.log(lengthOfLongestSubstring(s));  // Output: 3