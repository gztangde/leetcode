---
title: Leetcode 54. Spiral Matrix
date: 2018-10-28 06:09:31
updated: 2018-10-28 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a matrix of  _m_  x  _n_  elements (_m_  rows,  _n_  columns), return all elements of the matrix in spiral order.

**Example 1:**
> **Input:**
> [
> [ 1, 2, 3 ],
> [ 4, 5, 6 ],
> [ 7, 8, 9 ]
>]
> **Output:** [1,2,3,6,9,8,7,4,5]

**Example 2:**

> **Input:**
> [
>  [1, 2, 3, 4],
>  [5, 6, 7, 8],
>  [9,10,11,12]
> ]
> **Output:** [1,2,3,4,8,12,11,10,9,5,6,7]

<!-- more -->

-------------------

# Solution

```cpp
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty() || matrix[0].size() == 0) return res;
    int m = matrix.size(), n = matrix[0].size();
    int p = m, q = n;
    int c = m > n ? (n + 1) / 2 : (m + 1) / 2;

    for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
      for (int row_up = i; row_up <= i + q - 1; ++row_up)  // up
        res.emplace_back(matrix[i][row_up]);

      for (int row_right = i + 1; row_right <= i + p - 1; ++row_right)  // right
        res.emplace_back(matrix[row_right][i + q - 1]);

      if (p == 1 || q == 1) break;
      for (int row_bottom = n - i - 2; row_bottom >= i; --row_bottom)  // Bottom
        res.emplace_back(matrix[i + p - 1][row_bottom]);

      for (int row_left = m - i - 2; row_left > i; --row_left)  // Lift
        res.emplace_back(matrix[row_left][i]);
    }
    return res;
  }
};
```