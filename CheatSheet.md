# C++ DSA Cheatsheet

> Quick reference for C++ syntax while solving DSA problems.
> **Don't memorize everything — use it for a week and let repetition build muscle memory.**

---

## 1. String

```cpp
string str = "hello";
```

### Common Member Functions — `str.`

```cpp
str.length();       // length
str.size();         // length
str.empty();        // true / false

str.front();        // first character
str.back();         // last character

str[0];             // access character
str.at(0);          // access character

str.substr(1, 3);   // substring: starting index, length
str.find("ll");     // index of first occurrence

str.push_back('x');
str.pop_back();

str.clear();

str.begin();
str.end();

str.rbegin();
str.rend();
```

### String Comparison

```cpp
str == "hello";
str != "hello";
str < "hello";      // lexicographical comparison
```

### Reverse a String

```cpp
reverse(str.begin(), str.end());
```

---

## 2. Vector

```cpp
vector<int> v = {1, 2, 3};
```

### Common Member Functions — `v.`

```cpp
v.size();
v.empty();

v.front();
v.back();

v.push_back(10);
v.pop_back();

v.clear();

v[0];
v.at(0);

v.begin();
v.end();

v.rbegin();
v.rend();
```

### Common Algorithms

```cpp
sort(v.begin(), v.end());

reverse(v.begin(), v.end());

count(v.begin(), v.end(), 5);
```

---

## 3. Map

```cpp
map<char, int> mp;
```

### Think

```text
key → value
```

### Access / Insert

```cpp
mp['a']++;
mp['b'] = 10;

cout << mp['a'];
```

### Find

```cpp
mp.find('a');
```

Common check:

```cpp
if (mp.find('a') != mp.end()) {
    // key exists
}
```

### Delete

```cpp
mp.erase('a');
```

### Size

```cpp
mp.size();
mp.empty();
```

### Iterate

```cpp
for (auto i = mp.begin(); i != mp.end(); i++) {
    cout << i->first;    // key
    cout << i->second;   // value
}
```

Or:

```cpp
for (auto i : mp) {
    cout << i.first;
    cout << i.second;
}
```

### Remember

```text
i.first   → key
i.second  → value

i->first  → key, when i is an iterator
i->second → value, when i is an iterator
```

---

## 4. Unordered Map

```cpp
unordered_map<char, int> mp;
```

Usage is almost identical to `map`.

```cpp
mp['a']++;

mp.find('a');

mp.erase('a');

mp.size();
mp.empty();
```

### Iteration

```cpp
for (auto i : mp) {
    cout << i.first;
    cout << i.second;
}
```

### Difference

| `map`                 | `unordered_map`           |
| --------------------- | ------------------------- |
| Sorted by key         | No ordering guarantee     |
| `O(log n)` operations | Average `O(1)` operations |

---

## 5. Set

```cpp
set<int> s;
```

Stores **unique values**.

```cpp
s.insert(10);
s.insert(20);

s.find(10);

s.erase(10);

s.size();
s.empty();
```

### Check Existence

```cpp
if (s.find(10) != s.end()) {
    // exists
}
```

---

## 6. Unordered Set

```cpp
unordered_set<int> s;
```

```cpp
s.insert(10);

s.find(10);

s.erase(10);

s.size();
s.empty();
```

### Difference

| `set`      | `unordered_set`       |
| ---------- | --------------------- |
| Sorted     | No ordering guarantee |
| `O(log n)` | Average `O(1)`        |

---

## 7. Algorithms

> These are generally **standalone functions**, not `object.function()`.

### Sort

```cpp
sort(v.begin(), v.end());
```

Descending:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Custom comparator:

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

### Reverse

```cpp
reverse(v.begin(), v.end());

reverse(str.begin(), str.end());
```

### Count

```cpp
count(v.begin(), v.end(), 5);

count(str.begin(), str.end(), 'a');
```

### Min / Max

```cpp
max(a, b);
min(a, b);
```

### Swap

```cpp
swap(a, b);
```

---

## 8. Character Functions

Include:

```cpp
#include <cctype>
```

These are **standalone functions**.

```cpp
isdigit(ch);
isalpha(ch);
isalnum(ch);

islower(ch);
isupper(ch);

tolower(ch);
toupper(ch);
```

### Examples

```cpp
if (isalnum(str[i])) {
    // character is alphanumeric
}
```

```cpp
char ch = tolower(str[i]);
```

---

## 9. String ↔ Integer Conversion

### String → Integer

```cpp
string str = "123";

int n = stoi(str);
```

### Integer → String

```cpp
int n = 123;

string str = to_string(n);
```

---

## 10. `string::npos`

`find()` returns the position if something is found.

If it isn't found:

```cpp
string::npos
```

### Example

```cpp
if (str.find("abc") == string::npos) {
    // not found
}
```

### Common Pattern

```cpp
if (str.find(ch) != string::npos) {
    // found
}
```

> **Remember:** `string::npos` basically means **"not found"**.

---

## 11. Iterators

When you see:

```cpp
v.begin();
v.end();
```

Think:

> Iterator pointing to the beginning/end of the container.

Most commonly used with algorithms:

```cpp
sort(v.begin(), v.end());

reverse(v.begin(), v.end());

count(v.begin(), v.end(), x);
```

### General Pattern

```cpp
container.begin()
container.end()
```

---

## 12. Pair

```cpp
pair<char, int> p;
```

### Access

```cpp
p.first;
p.second;
```

### Example

```cpp
pair<char, int> p = {'a', 5};

cout << p.first;   // a
cout << p.second;  // 5
```

### Common with Maps

```cpp
i->first;
i->second;
```

---

## 13. Priority Queue

```cpp
priority_queue<int> pq;
```

### Max Heap by Default

```cpp
pq.push(10);
pq.push(5);
pq.push(20);

pq.top();      // 20

pq.pop();      // removes top element

pq.empty();
pq.size();
```

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

## 14. Raw Array

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

### Access

```cpp
arr[0];
arr[i];
```

### Get Size

```cpp
int n = sizeof(arr) / sizeof(arr[0]);
```

> **Important:** When passed to a function, the array size generally needs to be passed separately.

```cpp
void func(int arr[], int n) {
    // ...
}
```

For vectors:

```cpp
v.size();
```

---

# Quick Mental Classification

The biggest thing to remember is **what comes before/after `.`**

## 1. Container / Member Operation

Usually:

```cpp
object.function()
```

Examples:

```cpp
str.length();
str.find();

v.size();
v.push_back();

mp.find();
mp.erase();

s.insert();
```

Think:

> **"I have an object → use `.` → call its member function."**

---

## 2. General Algorithm / Function

Usually:

```cpp
function(...)
```

Examples:

```cpp
sort(...);
reverse(...);
count(...);

max(...);
min(...);
swap(...);
```

Think:

> **"This operation works on things → call the function directly."**

---

## 3. Character Operation

```cpp
isdigit(ch);
isalpha(ch);
isalnum(ch);

islower(ch);
isupper(ch);

tolower(ch);
toupper(ch);
```

These are standalone functions.

---

## 4. Conversion

```cpp
stoi(str);
to_string(n);
```

These are also standalone functions.

---

# ⭐ One-Page DSA Reference

## String

```cpp
string str;

str.size();
str.empty();

str.front();
str.back();

str[0];
str.at(0);

str.substr(start, length);
str.find("abc");

str.push_back(ch);
str.pop_back();

str.clear();

str.begin();
str.end();

str.rbegin();
str.rend();
```

## Vector

```cpp
vector<int> v;

v.size();
v.empty();

v.front();
v.back();

v.push_back(x);
v.pop_back();

v.clear();

v[0];
v.at(0);

v.begin();
v.end();

v.rbegin();
v.rend();
```

## Map

```cpp
map<char, int> mp;

mp[key]++;
mp[key] = value;

mp.find(key);
mp.erase(key);

mp.size();
mp.empty();

mp.begin();
mp.end();
```

### Map Element

```cpp
i.first;       // key
i.second;      // value

i->first;      // key, when i is iterator
i->second;     // value, when i is iterator
```

## Set

```cpp
set<int> s;

s.insert(x);
s.find(x);
s.erase(x);

s.size();
s.empty();
```

## Algorithms

```cpp
sort(v.begin(), v.end());

reverse(v.begin(), v.end());

count(v.begin(), v.end(), x);

max(a, b);
min(a, b);

swap(a, b);
```

## Characters

```cpp
isdigit(ch);
isalpha(ch);
isalnum(ch);

islower(ch);
isupper(ch);

tolower(ch);
toupper(ch);
```

## Conversion

```cpp
stoi(str);

to_string(n);
```

## Special

```cpp
string::npos;
```

## Priority Queue

```cpp
priority_queue<int> pq;

pq.push(x);
pq.pop();
pq.top();

pq.size();
pq.empty();
```

### Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> minPQ;
```

---

# 🧠 The Rule for the Next Week

> **Don't try to memorize this.**

If you forget:

```cpp
str.find(...)
```

**Look it up.**

If you forget:

```cpp
sort(v.begin(), v.end())
```

**Look it up.**

If you forget:

```cpp
mp[key]++;
```

**Look it up.**

The goal is not to memorize the cheatsheet.

The goal is to use it repeatedly until you **stop needing it**.
