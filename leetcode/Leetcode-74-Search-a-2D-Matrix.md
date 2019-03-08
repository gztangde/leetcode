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

# Analyze

# Solution

```cpp
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;

    int left = 0, right = matrix.size() * matrix[0].size();
    while (left < right) {
      int mid = (left + right) / 2;
      int val = matrix[mid / matrix[0].size()][mid % matrix[0].size()];
      if (val == target)
        return true;
      else if (val < target)
        left = mid + 1;
      else
        right = mid;
    }
    return false;
  }
};
```
