# C++ Cheatsheet

## 1. Character Functions

```cpp
// #include <cctype> — standalone functions, not object.method()

isdigit(ch);
isalpha(ch);
isalnum(ch);

islower(ch);
isupper(ch);

tolower(ch);
toupper(ch);
```

---

## 2. String

```cpp
string str = "hello";

str.length();               // number of characters
str.size();                 // number of characters
str.empty();                // true if empty

str.front();                // first char
str.back();                 // last char

str[0];                     // access by index
str.substr(1, 3);           // substring(startIndex, length)
str.find("ll");             // index of first occurrence, string::npos if not found

str.push_back('x');         // append char to end
str.pop_back();             // remove last char
str.erase(1, 3);            // remove 3 chars starting at index 1
str.clear();                // remove all chars

str == "hello";             // comparison
str < "hello";              // lexicographical comparison

reverse(str.begin(), str.end());

// iteration
for (char ch : str) { }
for (int i = 0; i < str.length(); i++) { str[i]; }
for (auto i = str.begin(); i != str.end(); i++) { *i; }
```

### string::npos

```cpp
if (str.find("abc") != string::npos) { }   // found
if (str.find("abc") == string::npos) { }   // not found
```

---

## 3. Array

```cpp
int arr[5] = {1, 2, 3, 4, 5};

arr[0];                                 // access by index

int n = sizeof(arr) / sizeof(arr[0]);   // size — only valid in same scope, not after passing to function

// iteration
for (int x : arr) { }
for (int i = 0; i < n; i++) { arr[i]; }
for (auto i = arr; i != arr + n; i++) { *i; }      // pointer iteration

sort(arr, arr + n);

// passing to function — size must be passed separately
void func(int arr[], int n) { }
```

---

## 4. Type Conversion

```cpp
// string ↔ int
int n    = stoi("123");
string s = to_string(123);

// char ↔ int
int n   = ch - '0';         // char digit → int  ('5' → 5)
char ch = '0' + n;          // int → char digit  (5 → '5')

int n   = (int)ch;          // char → ASCII value
char ch = (char)n;          // ASCII value → char
```

---

## 5. Useful Constants

```cpp
// #include <climits>
INT_MAX;        // 2,147,483,647  — use to initialize a min tracker
INT_MIN;        // -2,147,483,648 — use to initialize a max tracker
LLONG_MAX;      // for long long max
LLONG_MIN;      // for long long min
```

---

> **Iteration — when to use which:**
> - `for (auto x : c)` — simplest; use when you only need values
> - `for (int i = 0; ...)` — use when you need the index (arrays/vectors only)
> - `for (auto i = c.begin(); i != c.end(); i++)` — use when you need iterators, e.g. for map/set or iterator-based operations.

---

## Container Complexity Summary

| Container | Access | Insert / Find / Erase | Ordered |
|---|---|---|---|
| `vector` | `O(1)` | `O(1)` end, `O(n)` middle | — |
| `map` | — | `O(log n)` | yes (by key) |
| `unordered_map` | — | `O(1)` avg | no |
| `set` | — | `O(log n)` | yes |
| `unordered_set` | — | `O(1)` avg | no |
| `stack` | top only | `O(1)` | — |
| `queue` | front/back | `O(1)` | — |
| `priority_queue` | `O(1)` top | `O(log n)` push/pop | by priority |

> Iteration is `O(n)` for all containers.

---

## 6. Vector

```cpp
vector<int> v = {1, 2, 3};

v.size();                                   // number of elements
v.empty();                                  // true if empty

v.front();                                  // first element
v.back();                                   // last element

v.push_back(10);                            // add to end
v.pop_back();                               // remove last element
v.clear();                                  // remove all elements

v[0];                                       // access by index

// binary search on sorted range
lower_bound(v.begin(), v.end(), x);         // returns iterator to first element which is >= x
upper_bound(v.begin(), v.end(), x);         // returns iterator to first element which is >  x

// number of occurrences of x in a sorted vector  
upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);      

// iteration
for (int x : v) { }
for (int i = 0; i < v.size(); i++) { v[i]; }
for (auto i = v.begin(); i != v.end(); i++) { *i; }

sort(v.begin(), v.end());
reverse(v.begin(), v.end());
count(v.begin(), v.end(), 5);               // count occurrences of 5
```

| Operation | Time Complexity |
|---|---|
| `v[i]` / `front` / `back` | `O(1)` |
| `push_back` / `pop_back` | `O(1)` amortized |
| insert / erase (beginning or middle) | `O(n)` |
| iteration | `O(n)` |

---

## 7. Map

```cpp
map<char, int> mp;          // sorted by key, O(log n)

mp['a']++;                  // insert(creates if not present) or update 
mp['b'] = 10;

mp.find('a');               // returns iterator, mp.end() if not found
if (mp.find('a') != mp.end()) { }   // check if key exists
mp.count('a');              // 0 or 1 — quick existence check
if (mp.count('a')) {
    // exists
}

mp.erase('a');
mp.size();
mp.empty();

// range-based: dot notation (i.first / i.second)
for (auto i : mp) { i.first; i.second; }

// iterator-based: arrow notation (i->first / i->second)
for (auto i = mp.begin(); i != mp.end(); i++) { i->first; i->second; }
```

| Operation | Time Complexity |
|---|---|
| insert / find / erase | `O(log n)` |
| iteration | `O(n)` |

---

## 8. Unordered Map

```cpp
unordered_map<char, int> mp;    // no ordering, avg O(1)
```

Same API as `map`: `[]`, `find()`, `count()`, `erase()`, `size()`, `empty()`. Iterate with range-based for.

| Operation | Time Complexity |
|---|---|
| insert / find / erase | `O(1)` avg |
| iteration | `O(n)` |

---

## 9. Set

```cpp
set<int> s;                 // unique values, sorted

s.insert(10);
s.erase(10);

if (s.find(10) != s.end()) { }  // check existence
s.count(10);                    // 0 or 1 — quick existence check

s.size();
s.empty();

// iteration
for (int x : s) { }                                        // sorted order
for (auto i = s.begin(); i != s.end(); i++) { *i; }
```

| Operation | Time Complexity |
|---|---|
| insert / find / erase | `O(log n)` |
| iteration | `O(n)` |

---

## 10. Unordered Set

```cpp
unordered_set<int> s;       // unique values, no ordering, avg O(1)
```

Same API as `set`: `insert()`, `find()`, `count()`, `erase()`, `size()`, `empty()`. Iterate with range-based for (no ordering).

| Operation | Time Complexity |
|---|---|
| insert / find / erase | `O(1)` avg |
| iteration | `O(n)` |

---

## 11. Algorithms

```cpp
// standalone functions, not object.method()

sort(v.begin(), v.end());
sort(v.begin(), v.end(), greater<int>());           // descending
sort(v.begin(), v.end(), [](int a, int b) {         // custom comparator
    return a > b;
});

reverse(v.begin(), v.end());

count(v.begin(), v.end(), 5);                       // count occurrences

max(a, b);
min(a, b);
swap(a, b);
```

---

## 12. Pair

```cpp
pair<char, int> p = {'a', 5};

p.first;        // 'a'
p.second;       // 5

i->first;       // key — when i is a map iterator
i->second;      // value
```

> Access to `first` / `second` is always `O(1)`.

---

## 13. Priority Queue

```cpp
priority_queue<int> pq;                                 // max heap by default

pq.push(10);
pq.top();       // largest element
pq.pop();       // removes top

pq.size();
pq.empty();

priority_queue<int, vector<int>, greater<int>> pq;      // min heap
```

| Operation | Time Complexity |
|---|---|
| `push` / `pop` | `O(log n)` |
| `top` | `O(1)` |

---

## 14. Stack

```cpp
stack<int> st;              // LIFO — last in, first out

st.push(10);
st.top();                   // top element (most recently pushed)
st.pop();                   // removes top

st.size();
st.empty();
```

| Operation | Time Complexity |
|---|---|
| `push` / `pop` / `top` | `O(1)` |

---

## 15. Queue

```cpp
queue<int> q;               // FIFO — first in, first out

q.push(10);
q.front();                  // first element (oldest, removed next)
q.back();                   // last element (most recently added)
q.pop();                    // removes front

q.size();
q.empty();
```

| Operation | Time Complexity |
|---|---|
| `push` / `pop` / `front` / `back` | `O(1)` |
