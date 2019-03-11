---
title: Leetcode 240. Search a 2D Matrix II
date: 2019-03-11 15:47:52
updated: 2019-03-11 15:47:52
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

Write an efficient algorithm that searches for a value in an  _m_  x  _n_  matrix. This matrix has the following properties:

-   Integers in each row are sorted in ascending from left to right.
-   Integers in each column are sorted in ascending from top to bottom.

**Example:**

Consider the following matrix:

```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

Given target = `5`, return `true`.

Given target = `20`, return `false`.

**Difficulty**:Medium

**Category**:

# Solution

下角和右上角的数。左下角的18，往上所有的数变小，往右所有数增加，那么我们就可以和目标数相比较，如果目标数大，就往右搜，如果目标数小，就往上搜。这样就可以判断目标数是否存在。当然我们也可以把起始数放在右上角，往左和下搜，停止条件设置正确就行. 

```cpp
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    if (target < matrix[0][0] || target > matrix.back().back()) return false;

    int row = matrix.size() - 1, col = 0;

    while (col < matrix[0].size() && row >= 0) {
      int val = matrix[row][col];
      if (val == target) return true;
      val > target ? --row : ++col;
    }
    return false;
  }
};
```