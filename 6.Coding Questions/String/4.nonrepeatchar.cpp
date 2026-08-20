#include <iostream>
#include <map>

using namespace std;

char nonRepeatingChar (string & str) {

    map <char, int> freqMap;
    char nonRepChar;
    for (char ch : str) {
        freqMap[ch]++;
    }

    for (char ch : str) {
        if(freqMap[ch] == 1) {
            return ch;
        }
    }
    return '\0';
}

int main() {
    string str = "loveleetcode";
    cout << nonRepeatingChar(str) << endl;
    return 0;
}


//Find the first character in a string that does not repeat (e.g., “leetcode” → ‘l’).