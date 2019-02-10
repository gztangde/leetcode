---
title: Leetcode 62. Unique Paths
date: 2018-12-22 09:09:31
updated: 2018-12-22 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

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

<!-- more -->

------------

# Solution

## Solution 1: Recursive(递归) Time Limit Exceeded

首先我们想到的是使用递归来求解该问题, 对于矩阵中的格子(i, j)，假设从(1, 1)到它的路径数量为path(i, j), 递归公式为 `path(i, j) = path(i-1, j) + path(i, j-1)`.

很好理解，因为机器人只能向右或向下运动，因此它只能是从(i-1, j)或(i, j-1) 运动到(i, j)的，所以路径数量也就是到达这两个格子的路径数量之和。而递归终止条件是 `m == 0 || n == 0`.

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

## Solution 2: DP

**Buttom-Up Dynamic Programming** 转变为动态规划来求解, 使用 `f[i]`表示在每一行的第 `i` 个位置可能存在的前进路线的方式, 这就可以使用 `f[j] = f[j] + f[j - 1];` 来表示在每一行的第 `j` 个位置的路径可能数量.

```cpp
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector<int> f(n, 0);
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

上面不使用 vector也是可以的, 可使用数组.

```cpp
int f[n];
fill_n(&f[0], n, 0);
```
