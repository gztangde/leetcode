---
title: Leetcode 53. Maximum Subarray
date: 2018-12-19 09:09:31
updated: 2018-12-19 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an integer array  `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

**Input:** [-2,1,-3,4,-1,2,1,-5,4],
**Output:** 6
**Explanation:** [4,-1,2,1] has the largest sum = 6.

**Follow up:**

If you have figured out the O(_n_) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**Difficulty**:Easy
**Category**:Array, Divide-and-Conquer, Dynamic-Programming

<!-- more -->

------------

# Analyze

这道题目是求解最大的连续子序列和，依次处理每个元素：

- 如果当前元素加上之前的和 < 这个元素本身的数值， 那么就取这个元素本身的数值作为临时值
- 如果得到的临时数值比之前的最大值还要大，那么就替换这个数值

解决方案：如`Solution1`

------------

# Solution

```cpp
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int res = INT_MIN, temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
      temp = max(temp + nums[i], nums[i]);
      res = max(temp, res);
    }
    return res;
  }
};
```