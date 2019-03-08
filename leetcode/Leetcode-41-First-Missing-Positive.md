---
title: Leetcode 41. First Missing Positive
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an unsorted integer array, find the smallest missing positive integer.

**Example 1:**

> Input: [1,2,0]
> Output: 3

**Example 2:**

> Input: [3,4,-1,1]
> Output: 2

**Example 3:**

> Input: [7,8,9,11,12]
> Output: 1

**Difficulty**:Medium

**Category**:Array

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    vec_sort(nums);

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) return i + 1;
    }

    return nums.size() + 1;
  }

  void vec_sort(vector<int>& nums) {
    // Build a array to store the numsbers
    const unsigned int len_n = nums.size();
    for (int i = 0; i < len_n; ++i) {
      while (nums[i] != i + 1) {
        if (nums[i] <= 0 || nums[i] > len_n || nums[i] == nums[nums[i] - 1]) break;
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
  }
};
```
