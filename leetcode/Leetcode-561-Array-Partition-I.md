---
title: Leetcode 561. Array Partition I
date: 2018-12-24 09:09:31
updated: 2018-12-24 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of  **2n**  integers, your task is to group these integers into  **n**  pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

**Example 1:**  

> **Input:** [1,4,3,2]
> **Output:** 4
> **Explanation:** n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

**Note:**  

1. **n**  is a positive integer, which is in the range of [1, 10000].
2. All the integers in the array will be in the range of [-10000, 10000].

**Difficulty**:Easy

**Category**:Array

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    int res = 0, len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i = i + 2) {
      res += nums[i];
    }
    return res;
  }
};
```