---
title: Leetcode 217. Contains Duplicate
date: 2018-12-25 09:09:31
updated: 2018-12-25 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**Example 1:**

> **Input:** [1,2,3,1]
> **Output:** true

**Example 2:**

> **Input:** [1,2,3,4]
> **Output:** false

**Example 3:**

> **Input:** [1,1,1,3,3,4,3,2,4,2]
> **Output:** true

**Difficulty**:Easy

**Category**:Array, Hash-Table

<!-- more -->

------------

# Analyze

# Solution

```cpp
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int x : nums) {
      std::unordered_map<int, int>::iterator got = counts.find(x);
      if (got == counts.end())
        counts.insert({x, 0});
      else
        return true;
    }
    return false;
  }
};
```