---
title: Leetcode 349. Intersection of Two Arrays
date: 2018-12-16 09:09:31
updated: 2018-12-16 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question


Given two arrays, write a function to compute their intersection.

**Example 1:**

> **Input:** nums1 = [1,2,2,1], nums2 = [2,2]
> **Output:** [2]

**Example 2:**

> **Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]
> **Output:** [9,4]

**Difficulty**:Easy

**Category**:Hash-Table, Sort, Two-Points, Binary-Search

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> s(nums1.begin(), nums1.end()), res;
    for (auto i : nums2) {
      if (s.count(i)) res.insert(i);
    }
    return vector<int>(res.begin(), res.end());
  }
};
```