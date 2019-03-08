---
title: Leetcode 476. Number Complement
date: 2019-02-08 23:15:18
updated: 2019-02-08 23:15:18
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

**Note:**  

1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.

**Example 1:**

**Input:** 5
**Output:** 2
**Explanation:** The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

**Example 2:**  

**Input:** 1
**Output:** 0
**Explanation:** The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

**Difficulty**:Easy

**Category**:Bit-Manipulation

<!-- more -->

------------

# Analyze

This idea is come from the [leetcode discuss](https://leetcode.com/problems/number-complement/discuss/96017/3-line-C%2B%2B). The actual process for the solution like:

```
num           = 00000101
mask          = 11111000
mask ^ num    = 11111101
~(mask ^ num) = 00000010
```

------------

# Solution

```cpp
class Solution {
 public:
  int findComplement(int num) {
    int mask = ~0;
    int bit = 0;
    while (mask & num) mask &= ~(1 << bit++);
    return ~(mask ^ num);
  }
};
```