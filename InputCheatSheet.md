# C++ Input & Parsing Cheatsheet

Quick reference for handling common input formats in coding exams and day-to-day C++.

---

## Quick Reference

| Task | Function / Tool | Section |
| ---- | --------------- | ------- |
| Fast I/O setup | `ios::sync_with_stdio(false); cin.tie(NULL)` | [Fast I/O Boilerplate](#1-fast-io-boilerplate) |
| Read integer | `cin >> x` | [Primitive Input](#2-primitive-input) |
| Read complete line | `getline(cin, line)` | [Primitive Input](#2-primitive-input) |
| Clear leftover newline | `cin.ignore()` | [Primitive Input](#2-primitive-input) |
| String → integer | `stoi(str)` | [Type Conversion](#3-type-conversion) |
| String → long long | `stoll(str)` | [Type Conversion](#3-type-conversion) |
| Process values from string | `stringstream` | [String Parsing](#4-string-parsing) |
| Split by delimiter | `getline(ss, token, ',')` | [String Parsing](#4-string-parsing) |
| Comma-separated numbers → vector | `getline + stoi` | [String Parsing](#4-string-parsing) |
| Read into vector | `for loop + cin` | [Collections Input](#5-collections-input) |
| Read 2D matrix | `nested for loop` | [Collections Input](#5-collections-input) |
| Read pairs | `cin >> p.first >> p.second` | [Collections Input](#5-collections-input) |
| Read map | `cin >> key >> val` | [Collections Input](#5-collections-input) |
| T test cases | `while (T--)` | [Input Patterns](#6-input-patterns) |
| Read until EOF | `while (cin >> x)` | [Input Patterns](#6-input-patterns) |
| Vector output | `for (int x : nums)` | [Output Patterns](#7-output-patterns) |
| Output without trailing space | `if (i > 0) cout << " "` | [Output Patterns](#7-output-patterns) |

---

## 1. Fast I/O Boilerplate

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // cin, cout, getline all work normally below — only faster now
    int n;
    cin >> n;

    return 0;
}
```

By default, C++ syncs `cin`/`cout` with C's `scanf`/`printf` and flushes `cout` before every `cin` read. Both add overhead. These two lines disable that, making I/O significantly faster for large inputs.

| Line | What it does |
| ---- | ------------ |
| `ios::sync_with_stdio(false)` | Stops syncing with `scanf`/`printf` — `cin` becomes faster |
| `cin.tie(NULL)` | Stops auto-flushing `cout` before each `cin` read |

**When to use:** Any problem with large input — add as a habit at the top of `main()`.

**When NOT to use:**
- Mixing `cin` with `scanf`/`printf` in the same program — output order will break.
- Interactive problems where you must print then immediately wait for input — the flush is needed there.

---

## 2. Primitive Input

### Single value

```cpp
int n;
cin >> n;
```

### Multiple values

```cpp
int a, b;
cin >> a >> b;
```

`cin >>` skips all whitespace (spaces, newlines, tabs), so both formats work:

```text
10 20
```

```text
10
20
```

---

### Read an entire line

```cpp
string line;
getline(cin, line);
```

### Input

```text
hello world this is C++
```

### Result

```text
line = "hello world this is C++"
```

---

### `cin` + `getline()` issue

If `cin >>` is used before `getline()`, a leftover newline stays in the buffer and `getline()` reads an empty string instead of the actual line. Fix this by calling `cin.ignore()` after `cin >>` to discard that newline.

```cpp
int n;
cin >> n;
cin.ignore();   // discard the leftover newline

string line;
getline(cin, line);
```

If multiple lines were read with `cin >>` before `getline()`, use the safer form to clear the entire remaining line:

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
```

### Input

```text
5
hello world
```

---

## 3. Type Conversion

| Function | Returns | Notes |
| -------- | ------- | ----- |
| `stoi(s)` | `int` | handles leading spaces and sign |
| `stol(s)` | `long` | |
| `stoll(s)` | `long long` | use for large numbers |
| `stof(s)` | `float` | |
| `stod(s)` | `double` | prefer over `stof` for precision |

```cpp
int a       = stoi("123");
long long b = stoll("9876543210");
double c    = stod("3.14");
int d       = stoi(" -45 ");   // -45, leading/trailing spaces handled
```

`stoi()` throws an exception if the string is not a valid number (e.g. empty string `""`). This can happen with comma-separated input if there is a trailing comma — make sure to validate or trim tokens if needed.

---

## 4. String Parsing

```cpp
#include <sstream>   // only needed if not using #include <bits/stdc++.h>
```

### Space-separated values

`stringstream` lets you treat a string like `cin` — `ss >> x` reads the next token from the string, just like `cin >> x` reads from the terminal.

```cpp
string line = "3 -4 2 -1";
stringstream ss(line);

vector<int> nums;
int x;

while (ss >> x) {
    nums.push_back(x);
}
```

### Result

```text
nums = [3, -4, 2, -1]
```

---

### Split by delimiter

`getline(stream, variable, delimiter)` — reads from `stream` into `variable` until it hits `delimiter`.

```cpp
string line = "apple,banana,mango";
stringstream ss(line);

string word;
while (getline(ss, word, ',')) {
    cout << word << endl;
}
```

### Output

```text
apple
banana
mango
```

---

### Comma-separated numbers → `vector<int>`

```cpp
string line;
getline(cin, line);

stringstream ss(line);
vector<int> nums;
string token;

while (getline(ss, token, ',')) {
    nums.push_back(stoi(token));
}
```

### Input

```text
3,-4, 2,-1
```

### Result

```text
nums = [3, -4, 2, -1]
```

`stoi()` handles leading spaces like `" 2"` automatically.

---

## 5. Collections Input

### 1D Vector

```cpp
int n;
cin >> n;

vector<int> nums(n);
for (int i = 0; i < n; i++) {
    cin >> nums[i];
}
```

### Input

```text
5
10 20 30 40 50
```

### Result

```text
nums = [10, 20, 30, 40, 50]
```

---

### 2D Matrix

```cpp
int rows, cols;
cin >> rows >> cols;

vector<vector<int>> mat(rows, vector<int>(cols));
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> mat[i][j];
    }
}
```

### Input

```text
3 3
1 2 3
4 5 6
7 8 9
```

---

### Pairs

```cpp
int n;
cin >> n;

vector<pair<int, int>> pairs(n);
for (int i = 0; i < n; i++) {
    cin >> pairs[i].first >> pairs[i].second;
}
```

### Input

```text
3
1 2
3 4
5 6
```

---

### Map (key-value)

```cpp
int n;
cin >> n;

map<string, int> mp;
for (int i = 0; i < n; i++) {
    string key;
    int val;
    cin >> key >> val;
    mp[key] = val;
}
```

### Input

```text
3
apple 5
banana 3
mango 8
```

---

## 6. Input Patterns

### T test cases

```cpp
int T;
cin >> T;

while (T--) {
    int n;
    cin >> n;
    // solve for each test case
}
```

### Input

```text
3
5
10
7
```

---

### Read until EOF (no `n` given)

Use when the problem does not tell you how many values there are — keep reading until the input runs out.

```cpp
int x;
while (cin >> x) {
    // process x
}
```

```cpp
string line;
while (getline(cin, line)) {
    // process line
}
```

`cin >> x` returns false when there is no more input, so the loop exits automatically. In an exam, this is triggered when the judge's input ends. Locally, press `Ctrl+D` (Linux/Mac) or `Ctrl+Z` (Windows) to signal EOF.

---

### Mixed input (`cin` + `getline`)

```cpp
int n;
cin >> n;
cin.ignore();

string line;
getline(cin, line);
```

### Input

```text
5
hello world
```

---

## 7. Output Patterns

Prefer `"\n"` over `endl` — `endl` flushes the buffer every time it is called, which is slow inside loops. `"\n"` just prints a newline without flushing.

```cpp
cout << x << "\n";   // fast
cout << x << endl;   // slow — flushes buffer every call
```

### Simple output

```cpp
for (int x : nums) {
    cout << x << " ";
}
cout << "\n";
```

### Without trailing space

```cpp
for (int i = 0; i < (int)nums.size(); i++) {
    if (i > 0) cout << " ";
    cout << nums[i];
}
cout << "\n";
```

`(int)` cast on `nums.size()` avoids a signed/unsigned comparison warning — `size()` returns an unsigned type, but `i` is `int`.
