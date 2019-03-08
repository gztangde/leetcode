---
title: Leetcode 342. Power of Four
date: 2019-02-08 00:55:11
updated: 2019-02-08 00:55:11
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

**Example 1:**

**Input:** 16
**Output:** true

**Example 2:**

**Input:** 5
**Output:** false

**Follow up**: Could you solve it without loops/recursion?

**Difficulty**:Easy

**Category**:Bit-Manipulation

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isPowerOfFour(int num) {
    int temp = 0b01010101010101010101010101010101;
    return num > 0 && (num & (num - 1)) == 0 && (num & temp) != 0;
  }
};
```