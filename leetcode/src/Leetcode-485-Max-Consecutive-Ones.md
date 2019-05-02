---
title: Leetcode 485. Max Consecutive Ones
date: 2018-12-25 09:09:31
updated: 2018-12-25 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary array, find the maximum number of consecutive 1s in this array.

**Example 1:**  

> **Input:** [1,1,0,1,1,1]
> **Output:** 3
> **Explanation:** The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

**Note:**

- The input array will only contain  `0`  and  `1`.
- The length of input array is a positive integer and will not exceed 10,000

**Difficulty**:Easy

**Category**:Array

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, temp = 0;
    for (int x : nums) {
      x ? temp++ : temp = 0;
      res = max(res, temp);
    }
    return res;
  }
};
```
