---
title: Leetcode 29. Divide Two Integers
date: 2019-01-22 21:45:39
updated: 2019-01-22 21:45:39
categories: 
- [Leetcode]
- [Leetcode, Math]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given two integers  `dividend`  and  `divisor`, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing  `dividend`  by  `divisor`.

The integer division should truncate toward zero.

**Example 1:**

> **Input:** dividend = 10, divisor = 3
> **Output:** 3

**Example 2:**

> **Input:** dividend = 7, divisor = -3
> **Output:** -2

**Note:**

- Both dividend and divisor will be 32-bit signed integers.
- The divisor will never be 0.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231, 231  − 1]. For the purpose of this problem, assume that your function returns 231  − 1 when the division result overflows.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

这道题目规定我们不能使用乘法，除法以及取余操作。我们可以考虑在这道题目使用 `Bit Operation`

## Solution 1: Implement

```cpp
class Solution {
 public:
  int divide(int dividend, int divisor) {
    long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
    if (m < n) return 0;
    while (m >= n) {
      long long t = n, p = 1;
      while (m > (t << 1)) {
        t <<= 1;
        p <<= 1;
      }
      res += p;
      m -= t;
    }
    if ((dividend < 0) ^ (divisor < 0)) res = -res;
    return res > INT_MAX ? INT_MAX : res;
  }
};
```

## Solution 2: Recursion

```cpp
class Solution {
 public:
  int divide(int dividend, int divisor) {
    long long res = 0;
    long long m = abs((long long)dividend), n = abs((long long)divisor);
    if (m < n) return 0;
    long long t = n, p = 1;
    while (m > (t << 1)) {
      t <<= 1;
      p <<= 1;
    }
    res += p + divide(m - t, n);
    if ((dividend < 0) ^ (divisor < 0)) res = -res;
    return res > INT_MAX ? INT_MAX : res;
  }
};
```