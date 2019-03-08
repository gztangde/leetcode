---
title: Leetcode 448. Find All Numbers Disappeared in an Array
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of integers where 1 ≤ a[i] ≤  _n_  (_n_  = size of array), some elements appear twice and others appear once.

Find all the elements of [1,  _n_] inclusive that do not appear in this array.

Could you do it without extra space and in O(_n_) runtime? You may assume the returned list does not count as extra space.

**Example:**

> **Input:**
> [4,3,2,7,8,2,3,1]
> **Output:**
> [5,6]

**Difficulty**:Easy

**Category**:Array

<!-- more -->

------------

# Analyze

这道题目可以说是： [Leetcode 41. First Missing Positive](../Leetcode-41-First-Missing-Positive/)题目的升级版，只需要将找到的丢失的数据一次存下来就好了，可以延续使用那一道题目的代码。

# Solution

```cpp
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    vec_sort(nums);

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i + 1) res.emplace_back(i + 1);
    }

    return res;
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