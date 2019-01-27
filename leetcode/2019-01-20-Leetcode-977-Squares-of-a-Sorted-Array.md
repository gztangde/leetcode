---
title: Leetcode 977. Squares of a Sorted Array
date: 2019-01-20 00:24:25
updated: 2019-01-20 00:24:25
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of integers  `A` sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

**Example 1:**

**Input:** [-4,-1,0,3,10]
**Output:** [0,1,9,16,100]

**Example 2:**

**Input:** [-7,-3,2,3,11]
**Output:** [4,9,9,49,121]

**Note:**

1. `1 <= A.length <= 10000`
2. `-10000 <= A[i] <= 10000`
3. `A` is sorted in non-decreasing order.

**Difficulty**:Medium
**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    for (int i = 0; i < A.size(); ++i) {
      A[i] = A[i] * A[i];
    }
    sort(A.begin(), A.end());
    return A;
  }
};
```
