#include <iostream>
#include <string>

using namespace std;

string getSum (string & s1, string & s2) {
    // return stoi(s1) + stoi(s2);
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    vector<string> resultVec;
    string str = "";

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? (s1[i] - '0') : 0;
        int digit2 = j >= 0 ? (s2[j] - '0') : 0;

        int total = digit1 + digit2 + carry;
        carry = total / 10;

        resultVec.push_back(to_string(total%10));
        i--;
        j--;
    }
    for (int i = resultVec.size() - 1; i >= 0; i--) {
        str += resultVec[i];
    }
    return str;

}

int main() {
    string s1 = "123";
    string s2 = "77";
    cout << getSum(s1, s2) << endl;
    return 0;
}


// Given two non-negative integer strings num1 and num2, 
// return their sum as a string (e.g., “123” + “77” → “200”). 