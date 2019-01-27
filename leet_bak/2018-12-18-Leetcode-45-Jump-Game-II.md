---
title: Leetcode 45. Jump Game II
date: 2018-12-18 09:09:31
updated: 2018-12-18 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

**Example:**

> **Input:** [2,3,1,1,4]
> **Output:** 2
> **Explanation:** The minimum number of jumps to reach the last index is 2.Jump 1 step from index 0 to 1, then 3 steps to the last index.

**Note:**

You can assume that you can always reach the last index.

**Difficulty**:Hard
**Category**:Greedy, Array

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// TODO: Try to use other method to solve this problem.
class Solution {
 public:
  int jump(vector<int>& nums) {
    // 1. If size() <= 1, there is no step for this question.
    if (nums.size() <= 1) return 0;
    int step = 0, left = 0, right = 0;
    // Right: each step, we can arrive the longest one.
    while (left <= right) {
      step++;
      const int old_right = right;
      for (int i = left; i <= old_right; ++i) {
        int new_right = i + nums[i];
        if (new_right >= nums.size() - 1) return step;
        // Move one step, there will add a new right positon.
        if (new_right > right) right = new_right;
      }
      left = old_right + 1;
    }
    return 0;
  }
};
```