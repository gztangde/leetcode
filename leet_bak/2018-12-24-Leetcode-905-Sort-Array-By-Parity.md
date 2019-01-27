---
title: Leetcode 905. Sort Array By Parity
date: 2018-12-23 09:09:31
updated: 2018-12-23 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `A`  of non-negative integers, return an array consisting of all the even elements of  `A`, followed by all the odd elements of  `A`.

You may return any answer array that satisfies this condition.

**Example 1:**

**Input:** [3,1,2,4]
**Output:** [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

**Note:**

1. `1 <= A.length <= 5000`
2. `0 <= A[i] <= 5000`

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
  vector<int> sortArrayByParity(vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while (left < right) {
      while (A[left] % 2 == 0) ++left;
      while (A[right] & 1) --right;
      if (left < right) swap(A[left++], A[right--]);
    }
    return A;
  }
};
```