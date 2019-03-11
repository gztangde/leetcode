---
title: Leetcode 74. Search a 2D Matrix
date: 2018-12-17 19:09:31
updated: 2018-12-17 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Write an efficient algorithm that searches for a value in an  _m_  x  _n_  matrix. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

![](/images/in-post/2018-12-17-Leetcode-74-Search-a-2D-Matrix/2018-12-17-16-10-27.png)

**Difficulty**:Medium

**Category**:Array, Binary-Search

<!-- more -->

# Solution

这道题要求搜索一个二维矩阵，由于给的矩阵是有序, 可以考虑采用 `Binary Search`

## Solution: Binary Search

Time complexity: O(log(row*col)), Space complexity: O(1)

```cpp
class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    if (target < matrix[0][0] || target > matrix.back().back()) return false;
    const int row = matrix.size(), col = matrix[0].size();
    int left = 0, right = row * col;

    // Binary Search: No repeat elements.
    while (left < right) {
      int mid = left + (right - left) / 2;

      int mid_val = matrix[mid / col][mid % col];
      if (mid_val == target) return true;
      else if ( mid_val < target) left = mid + 1;
      else right = mid;
    }
    return false;
  }
};
```

# Follow up

如果矩阵的每一行的行内是有序的，　但是每一行的数字并不能保证比前一行的最后一个元素大，但是对应列的元素比上一行是要大的。

```
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
```

Leetcode 240. Search a 2D Matrix II