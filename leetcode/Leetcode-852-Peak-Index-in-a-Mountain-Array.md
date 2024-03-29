---
title: Leetcode 852. Peak Index in a Mountain Array
date: 2019-01-21 15:31:51
updated: 2019-01-21 15:31:51
categories: 
- [Leetcode]
- [Leetcode, ]
tags: Leetcode
notshow: true
top:
---

# Question

Let's call an array  `A`  a  _mountain_ if the following properties hold:

- `A.length >= 3`
- There exists some  `0 < i < A.length - 1`  such that  `A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]`

Given an array that is definitely a mountain, return any `i` such that `A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]`.

**Example 1:**

> **Input:** [0,1,0]
> **Output:** 1

**Example 2:**

> **Input:** [0,2,1,0]
> **Output:** 1

**Note:**

1. `3 <= A.length <= 10000`
2. `0 <= A[i] <= 10^6`
3. A is a mountain, as defined above.

**Difficulty**:Easy

**Category**:Binary-Search

<!-- more -->

# Analyze

这是一道 easy 题目， 可以通过线扫描，找到最大的顶点数值， 也可以通过Binary Search 的方式在 `log n` 的时间内找到。

# Solution

## Solution 1: Line Scan

Time Complexity: O(n), Space Complexity: O(1)

```cpp
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    for (int i = 1; i < A.size(); ++i)
      if (A[i] < A[i - 1]) return i - 1;
    return 0;
  }
};
```

## Solution 2: Binary Search

Time complexity: O(log n), Space Complexity: O(1)

```cpp
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& A) {
    // Binary Search
    int left = 0, right = A.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (A[mid] > A[mid + 1]) right = mid; // For the left part
      else left = mid + 1;
    }
    return left;
  }
};
```