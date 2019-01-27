
# Question

An array is  _monotonic_  if it is either monotone increasing or monotone decreasing.

An array  `A`  is monotone increasing if for all  `i <= j`,  `A[i] <= A[j]`. An array  `A`  is monotone decreasing if for all  `i <= j`,  `A[i] >= A[j]`.

Return  `true`  if and only if the given array  `A`  is monotonic.

**Example 1:**

> **Input:** [1,2,2,3]
> **Output:** true

**Example 2:**

> **Input:** [6,5,4,4]
> **Output:** true

**Example 3:**

> **Input:** [1,3,2]
> **Output:** false

**Example 4:**

> **Input:** [1,2,4,5]
> **Output:** true

**Example 5:**

> **Input:** [1,1,1]
> **Output:** true

**Note:**

1. `1 <= A.length <= 50000`
2. `-100000 <= A[i] <= 100000`

**Difficulty**:Easy
**Category**:Array


------------

# Analyze

------------

# Solution

## Solution 1

```cpp
class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    bool increate_flag = false, decreate_flag = false;
    int temp = 0;
    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] == A[i + 1]) continue;
      A[i] > A[i + 1] ? decreate_flag = true : increate_flag = true;
      temp = i;
      break;
    }

    if (increate_flag) {
      for (int j = temp; j < A.size() - 1; ++j) {
        if (A[j] <= A[j + 1]) continue;
        return false;
      }
    }

    if (decreate_flag) {
      for (int j = temp; j < A.size() - 1; ++j) {
        if (A[j] >= A[j + 1]) continue;
        return false;
      }
    }
    return true;
  }
};
```

## Solution 2

```cpp
class Solution {
 public:
  bool isMonotonic(vector<int>& A) { return increasing(A) || decreasing(A); }

  bool increasing(vector<int>& A) {
    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] > A[i + 1]) return false;
    }
    return true;
  }
  bool decreasing(vector<int>& A) {
    for (int i = 0; i < A.size() - 1; ++i) {
      if (A[i] < A[i + 1]) return false;
    }
    return true;
  }
};
```
