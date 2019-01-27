---
title: Leetcode 961. N-Repeated Element in Size 2N Array
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

In a array  `A`  of size  `2N`, there are  `N+1`  unique elements, and exactly one of these elements is repeated N times.

Return the element repeated  `N`  times.

**Example 1:**

> **Input:** [1,2,3,3]
> **Output:** 3

**Example 2:**

> **Input:** [2,1,2,5,3,2]
> **Output:** 2

**Example 3:**

> **Input:** [5,1,5,2,5,3,5,4]
> **Output:** 5

**Note:**

1. `4 <= A.length <= 10000`
2. `0 <= A[i] < 10000`
3. `A.length`  is even

**Difficulty**:Easy
**Category**:Hash-Table

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int repeatedNTimes(vector<int>& A) {
    unordered_set<int> rec;
    for (int i = 0; i < A.size(); ++i) {
      if (rec.count(A[i]))
        return A[i];
      else
        rec.insert(A[i]);
    }
  }
};
```
