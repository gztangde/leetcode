---
title: Leetcode 64. Minimum Path Sum
date: 2018-12-22 09:09:31
updated: 2018-12-22 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a  _m_  x  _n_  grid filled with non-negative numbers, find a path from top left to bottom right which  _minimizes_  the sum of all numbers along its path.

**Note:**  You can only move either down or right at any point in time.

**Example:**
![](/images/in-post/2018-12-22-Leetcode-64-Minimum-Path-Sum/2018-12-22-23-47-20.png)

**Difficulty**:Medium

**Category**:Array, Dynamic-Programming

<!-- more -->

# Analyze

# Solution

```cpp
// f[i][j]=min(f[i-1][j], f[i][j-1])+grid[i][j]
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    const unsigned int m = grid.size(), n = grid[0].size();
    
    int f[m][n];
    f[0][0] = grid[0][0];
    for (unsigned int i = 1; i < m; ++i) {
      f[i][0] = f[i-1][0] + grid[i][0];
    }
    
    for (unsigned int j = 1; j < n; ++j) {
      f[0][j] = f[0][j-1] + grid[0][j];
    }
    
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
      }
    }
    return f[m-1][n-1];
  }
};
```
