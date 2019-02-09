---
title: Leetcode 693. Binary Number with Alternating Bits
date: 2019-02-08 19:49:53
updated: 2019-02-08 19:49:53
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

**Example 1:**  

**Input:** 5
**Output:** True
**Explanation:**
The binary representation of 5 is: 101

**Example 2:**  

**Input:** 7
**Output:** False
**Explanation:**
The binary representation of 7 is: 111.

**Example 3:**  

**Input:** 11
**Output:** False
**Explanation:**
The binary representation of 11 is: 1011.

**Example 4:**  

**Input:** 10
**Output:** True
**Explanation:**
The binary representation of 10 is: 1010.

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

这个对于中间分割数据, 相同的两位不一样的情况下, 数据 `n` 和 `n >> 1`求`异或`的话, 就可以得到全为 `11111111` 的数据, 我们只要判断得到的数所有位都是1就可以了.

------------

# Solution

```cpp
class Solution {
 public:
  bool hasAlternatingBits(int n) {
    int a = (n ^ (n >> 1));
    if (a == INT_MAX) return true;
    return (a & long(a + 1)) == 0;
  }
};
```