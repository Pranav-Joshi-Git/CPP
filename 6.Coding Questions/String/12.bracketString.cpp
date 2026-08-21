#include <iostream>
#include <map>
#include <stack>

using namespace std;

bool isValid (string & str) {
    map<char, char> bracketsMap;
    bracketsMap[')'] = '(';
    bracketsMap['}'] = '{';
    bracketsMap[']'] = '[';

    stack<char> bracketsStack;

    for (char ch : str) {
        //checking if it is closing bracket
        if(bracketsMap.count(ch)) {
            if (bracketsStack.empty() || bracketsStack.top() != bracketsMap[ch]) {
                return false;
            }
            bracketsStack.pop();
        } else if (ch == '{' || ch == '(' || ch == '[') {
            bracketsStack.push(ch);
        } else {
            return false;
        }
    }
    return bracketsStack.empty();
}

int main() {
    string inp = "({[]})";
    cout << isValid(inp) << endl;
    return 0;
}

// Given a string containing just the characters ‘(‘, ‘)’, ‘{‘, ‘}’, ‘[‘, and ‘]’, 
// determine if the input string is valid. An input string is valid if:
// Example usage:
// input_str = "({[]})"
// print(is_valid(input_str))  # Output: True