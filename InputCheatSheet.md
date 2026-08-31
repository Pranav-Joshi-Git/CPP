# C++ Input & Parsing Cheatsheet

Quick reference for handling common input formats while solving DSA / competitive programming problems.


---

## 1. Basic Input — `cin`

Use `cin` when values are separated by spaces or newlines.

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

### Input

```text
10 20
```

---

## 2. Input into a Vector

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

## 3. Read an Entire Line — `getline()`

Use `getline()` when you need to read the **complete line**, including spaces.

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

## 4. `cin` + `getline()` Issue

If you use `cin >>` before `getline()`, there may be a leftover newline.

```cpp
int n;
cin >> n;

string line;
cin.ignore();
getline(cin, line);
```

### Why?

After:

```cpp
cin >> n;
```

the newline after `n` is still in the input buffer.

`cin.ignore()` removes it before `getline()` reads the line.

---

## 5. String → Integer — `stoi()`

Use `stoi()` to convert a string into an integer.

```cpp
string s = "123";

int num = stoi(s);
```

### Negative numbers

```cpp
string s = "-45";

int num = stoi(s);
```

### Whitespace

`stoi()` handles leading/trailing whitespace.

```cpp
string s = " 123 ";

int num = stoi(s);   // 123
```

---

## 6. `stringstream`

`stringstream` is useful for extracting values from a string.

Include:

```cpp
#include <sstream>
```

### Space-separated values

```cpp
string line = "3 -4 2 -1 -3 2 1";

stringstream ss(line);

vector<int> nums;
int x;

while (ss >> x) {
    nums.push_back(x);
}
```

### Result

```text
nums = [3, -4, 2, -1, -3, 2, 1]
```

### Important

`stringstream` automatically handles spaces.

For example:

```text
"3 -4  2   -1"
```

can still be extracted correctly.

---

## 7. Comma-Separated Input

Suppose the input is:

```text
3,-4, 2,-1,-3, 2, 1
```

### Convert commas to spaces

```cpp
string line;
getline(cin, line);

for (char &c : line) {
    if (c == ',') {
        c = ' ';
    }
}

stringstream ss(line);

vector<int> nums;
int x;

while (ss >> x) {
    nums.push_back(x);
}
```

### Result

```text
nums = [3, -4, 2, -1, -3, 2, 1]
```

This is useful when the input contains commas and inconsistent spaces.

---

## 8. Split a String Using a Delimiter

Use `getline()` with a delimiter when you need to split a string.

### Example

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

The third argument:

```cpp
','
```

tells `getline()` to split whenever it encounters a comma.

---

## 9. Comma-Separated Numbers → `vector<int>`

For input such as:

```text
3,-4, 2,-1,-3, 2, 1
```

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

### Result

```text
nums = [3, -4, 2, -1, -3, 2, 1]
```

`stoi()` handles values such as:

```text
"3"
"-4"
" 2"
" 1"
```

---

## 10. Vector → Output

### Simple output

```cpp
for (int x : nums) {
    cout << x << " ";
}

cout << endl;
```

### Output without trailing space

```cpp
for (int i = 0; i < nums.size(); i++) {

    if (i > 0) {
        cout << " ";
    }

    cout << nums[i];
}

cout << endl;
```

---

# Common Input Patterns

## Pattern 1 — Normal Numbers

### Input

```text
5
10 20 30 40 50
```

### Code

```cpp
int n;
cin >> n;

vector<int> nums(n);

for (int i = 0; i < n; i++) {
    cin >> nums[i];
}
```

---

## Pattern 2 — Complete Line

### Input

```text
hello world
```

### Code

```cpp
string line;
getline(cin, line);
```

---

## Pattern 3 — Space-Separated Numbers in a Line

### Input

```text
3 -4 2 -1 -3 2 1
```

### Code

```cpp
string line;
getline(cin, line);

stringstream ss(line);

vector<int> nums;
int x;

while (ss >> x) {
    nums.push_back(x);
}
```

---

## Pattern 4 — Comma-Separated Numbers

### Input

```text
3,-4, 2,-1,-3, 2, 1
```

### Code

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

---

# Quick Reference

| Task                         | Function / Tool           |
| ---------------------------- | ------------------------- |
| Read integer                 | `cin >> x`                |
| Read string without spaces   | `cin >> str`              |
| Read complete line           | `getline(cin, line)`      |
| Clear leftover newline       | `cin.ignore()`            |
| String → integer             | `stoi(str)`               |
| Process values from a string | `stringstream`            |
| Split using delimiter        | `getline(ss, token, ',')` |
| Vector → output              | `for (int x : nums)`      |

---

# Mental Map

```text
Normal input
    ↓
cin >>

Complete line
    ↓
getline()

String → integer
    ↓
stoi()

String → multiple values
    ↓
stringstream

Comma-separated string
    ↓
getline(ss, token, ',')

Multiple values → vector<int>
    ↓
vector<int> nums
```

---



```cpp
cin >> x;

getline(cin, line);

cin.ignore();

stoi(str);

stringstream ss(line);

getline(ss, token, ',');
```
