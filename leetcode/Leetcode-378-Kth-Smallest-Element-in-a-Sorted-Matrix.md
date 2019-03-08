---
title: Leetcode 378. Kth Smallest Element in a Sorted Matrix
date: 2019-01-19 17:39:40
updated: 2019-01-19 17:39:40
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
- [Leetcode, Heap]
tags: Leetcode
notshow: true
top:
---

# Question

Given a  _n_  x  _n_  matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

**Example:**

```
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
```

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ n2.

**Difficulty**:Medium

**Category**:Binary-Search, Heap

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;
    while (l < r) {
      long m = l + (r - l) / 2;
      int total = 0;
      for (vector<int>& x : matrix) {
        total += upper_bound(x, m);
      }
      if (total >= k)
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

 private:
  int upper_bound(vector<int>& A, int val) {
    int l = 0, r = A.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      A[m] > val ? r = m : l = m + 1;
    }
    return l;
  }
};
```