---
title: Leetcode 169. Majority Element
date: 2018-12-25 09:09:31
updated: 2018-12-25 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an array of size  _n_, find the majority element. The majority element is the element that appears  **more than**  `⌊ n/2 ⌋`  times.

You may assume that the array is non-empty and the majority element always exist in the array.

**Example 1:**

> **Input:** [3,2,3]
> **Output:** 3

**Example 2:**

> **Input:** [2,2,1,1,1,2,2]
> **Output:** 2

**Difficulty**:Easy

**Category**:Array

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int x : nums) {
      std::unordered_map<int, int>::iterator got = counts.find(x);
      if (got == counts.end())
        counts.insert({x, 1});
      else
        got->second++;
    }

    for (auto& x : counts) {
      if (x.second > nums.size() / 2) return x.first;
    }
    return 0;
  }
};
```
