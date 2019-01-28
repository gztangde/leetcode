---
title: Leetcode 941. Valid Mountain Array
date: 2019-01-08 21:36:49
updated: 2019-01-08 21:36:49
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  `A`  of integers, return  `true`  if and only if it is a  _valid mountain array_.

Recall that A is a mountain array if and only if:

- `A.length >= 3`
- There exists some  `i`  with `0 < i < A.length - 1` such that:
    - `A[0] < A[1] < ... A[i-1] < A[i]`
    - `A[i] > A[i+1] > ... > A[B.length - 1]`

**Example 1:**

> **Input:** [2,1]
> **Output:** false

**Example 2:**

> **Input:** [3,5,5]
> **Output:** false

**Example 3:**

> **Input:** [0,3,2,1]
> **Output:** true

**Note:**

1. `0 <= A.length <= 10000`
2. `0 <= A[i] <= 10000`

**Difficulty**:Easy

**Category**:Math

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// Runtimes: 36ms
class Solution {
 public:
  bool validMountainArray(vector<int>& A) {
    if (A.size() < 3) return false;
    bool has_up = false, has_down = false;
    for (int i = 1; i < A.size(); ++i) {
      if (A[i] > A[i - 1]) {
        if (has_down) return false;
        has_up = true;

      } else if (A[i] < A[i - 1]) {
        if (!has_up) return false;
        has_down = true;
      } else {
        return false;
      }
    }
    return has_up && has_down;
  }
};
```
