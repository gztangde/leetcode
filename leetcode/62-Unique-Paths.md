
# Question

A robot is located at the top-left corner of a  _m_  x  _n_  grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

![](/images/in-post/2018-12-22-Leetcode-62-Unique-Paths/2018-12-23-00-05-37.png)

Above is a 7 x 3 grid. How many possible unique paths are there?

**Note:**  _m_  and  _n_  will be at most 100.

**Example 1:**

> **Input:** m = 3, n = 2
> **Output:** 3
> **Explanation:**
> From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
> 1. Right -> Right -> Down
> 2. Right -> Down -> Right
> 3. Down -> Right -> Right

**Example 2:**

> **Input:** m = 7, n = 3
> **Output:** 28

**Difficulty**:Medium
**Category**:Array, Dynamic-Programming


------------

# Analyze

------------

# Solution

## Solution 1

超出了时间限制：

```cpp
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 0 || n == 0) return 0;
    if (m == 1 && n == 1) return 1;
    return uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
  }
};
```

## Solution 2

```cpp
// f[i][j]=f[i-1][j]+f[i][j-1]
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> f(n, 0);
    f[0] = 1;
    for (unsigned int i = 0; i < m; ++i) {
      for (unsigned int j = 1; j < n; ++j) {
        // f[i][j]=f[i-1][j]+f[i][j-1]
        f[j] = f[j] + f[j - 1];
      }
    }
    return f[n - 1];
  }
};
```

## Solution 3

```cpp
// f[i][j]=f[i-1][j]+f[i][j-1]
class Solution {
 public:
  int uniquePaths(int m, int n) {
    int f[n];
    fill_n(&f[0], n, 0);
    f[0] = 1;
    for (unsigned int i = 0; i < m; ++i) {
      for (unsigned int j = 1; j < n; ++j) {
        f[j] = f[j] + f[j - 1];
      }
    }
    return f[n - 1];
  }
};
```