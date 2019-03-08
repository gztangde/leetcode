---
title: Leetcode 766. Toeplitz Matrix
date: 2018-12-24 09:09:31
updated: 2018-12-24 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

A matrix is  _Toeplitz_  if every diagonal from top-left to bottom-right has the same element.

Now given an  `M x N`  matrix, return `True` if and only if the matrix is  _Toeplitz_.  

![](/images/in-post/2018-12-24-Leetcode-766-Toeplitz-Matrix/2018-12-24-22-26-29.png)

**Note:**

1. `matrix`  will be a 2D array of integers.
2. `matrix`  will have a number of rows and columns in range  `[1, 20]`.
3. `matrix[i][j]`  will be integers in range  `[0, 99]`.

**Follow up:**

1. What if the matrix is stored on disk, and the memory is limited such that you can only load at most one row of the matrix into the memory at once?
2. What if the matrix is so large that you can only load up a partial row into the memory at once?

**Difficulty**:Easy

**Category**:Array

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    if (m <= 1) return true;

    for (int i = m - 1; i >= 0; --i) {
      int val = matrix[i][0];
      int p = 1;
      for (int j = i + 1; j < m && p < n; ++j) {
        if (matrix[j][p++] != val) return false;
      }
    }

    for (int i = 1; i < n; ++i) {
      int val = matrix[0][i];
      int p = 1;
      for (int j = i + 1; j < n && p < m; ++j) {
        if (matrix[p++][j] != val) return false;
      }
    }

    return true;
  }
};
```