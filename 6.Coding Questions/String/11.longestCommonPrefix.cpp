#include <algorithm>
#include <iostream>

using namespace std;

string longestCommonPrefix (vector<string> & words) {
    string output;
    vector<string> temp = words;
    sort(temp.begin(), temp.end());
    
    string first = words[0];
    string last = words[words.size()-1];

    for (int i=0; i < min(first.length(), last.length()); i++) {
        if (first[i] != last[i]) {
            return output;
        }
        output.push_back(first[i]);
    }
    return output;
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(words) << endl;
    vector<string> words2 = {"dog" , "cat" , "animal", "monkey"};
    cout << longestCommonPrefix(words2) << endl;
    vector<string> words3 = {"lady" , "lazy"};
    cout << longestCommonPrefix(words3) << endl;
    return 0;
}

// Write a function to find the longest common prefix string amongst 
// an array of strings. If there is no common prefix, return an empty string “”.

// Example usage:
// vector<string> words = {"flower", "flow", "flight"};
// cout << longestCommonPrefix(words);  // Output: "fl"