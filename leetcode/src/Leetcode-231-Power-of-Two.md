---
title: Leetcode 231. Power of Two
date: 2019-02-08 00:51:42
updated: 2019-02-08 00:51:42
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an integer, write a function to determine if it is a power of two.

**Example 1:**

**Input:** 1
**Output:** true 
**Explanation:** 20 = 1

**Example 2:**

**Input:** 16
**Output:** true
**Explanation:** 24 = 16

**Example 3:**

**Input:** 218
**Output:** false

**Difficulty**:Easy

**Category**:Math, Bit-Manipulation

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    bitset<32> bit(n);
    return n > 0 && bit.count() == 1;
  }
};
```

## Solution 2

```cpp
class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};
```