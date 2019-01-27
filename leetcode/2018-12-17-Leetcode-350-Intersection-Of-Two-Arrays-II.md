---
title: Leetcode 350. Intersection of Two Arrays II
date: 2018-12-17 09:09:31
updated: 2018-12-17 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given two arrays, write a function to compute their intersection.

**Example 1:**

> **Input:** nums1 = [1,2,2,1], nums2 = [2,2]
> **Output:** [2,2]

**Example 2:**

> **Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
> **Output:** [4,9]

**Note:**

- Each element in the result should appear as many times as it shows in both arrays.
- The result can be in any order.

**Follow up:**

- What if the given array is already sorted? How would you optimize your algorithm?
- What if  _nums1_'s size is small compared to  _nums2_'s size? Which algorithm is better?
- What if elements of  _nums2_  are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

**Difficulty**:Easy
**Category**:Hash-Table, Two-Points, Binary-Search, Sort

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> num_map;
    vector<int> res;
    for (int i : nums1) num_map[i]++;
    for (int i : nums2) {
      if (num_map[i]) {
        res.emplace_back(i);
        num_map[i]--;
      }
    }
    return res;
  }
};

```