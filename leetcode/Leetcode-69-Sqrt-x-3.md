---
title: Leetcode 69. Sqrt(x)
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 69. Sqrt(x)

Implement  `int sqrt(int x)`.

Compute and return the square root of  _x_, where _x_ is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**

> **Input:** 4
> **Output:** 2

**Example 2:**

> **Input:** 8
> **Output:** 2
> **Explanation:** The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

**Difficulty**:Easy

**Category**:Math, Binary-Search

<!-- more -->

# Analyze

# Solution

## Solution 1: Binary Search

Time Complexity: O(log n), Space Complexity: O(1)

```cpp
class Solution {
public:
  int mySqrt(int x) {
    if (x < 2) return x;
    int left = 0, right = x / 2 + 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // Move left == right, then we need to move left back
      x / mid < mid ? right = mid : left = mid + 1;
    }

    return left - 1;
  }
};
```