#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<vector<string>> getAnagramGroups(vector<string> &inp) {

  map<string, vector<string>> res;
  vector<vector<string>> output;

  for (auto i : inp) {
    string temp = i;
    sort(temp.begin(), temp.end());
    res[temp].push_back(i);
  }

  for (auto i = res.begin(); i != res.end(); i++) {
        output.push_back(res[i->first]);
  }

  return output;

}

int main() {

  vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
  int vecSize = input.size();
  vector<vector<string>> result = getAnagramGroups(input);

  for (auto i = result.begin(); i != result.end(); i++) {
    for (auto j = i->begin(); j != i->end(); j++) {
      cout << *j << " ";
    }
    cout << endl;
  }

  return 0;
}

// Given an array of strings, group the anagrams together.
// {"eat", "tea", "tan", "ate", "nat", "bat"};
// eat tea ate
// tan nat
// bat