---
title: Leetcode 540. Single Element in a Sorted Array
date: 2019-01-21 19:43:11
updated: 2019-01-21 19:43:11
categories: 
- [Leetcode]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.

**Example 1:**  

> **Input:** [1,1,2,3,3,4,4,8,8]
> **Output:** 2

**Example 2:**  

> **Input:** [3,3,7,7,10,11,11]
> **Output:** 10

**Note:**  Your solution should run in O(log n) time and O(1) space.

**Difficulty**:Medium

**Category**:Binary-Search

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int singleNonDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size();
    while (left < right) {
      const int mid = left + (right - left) / 2;
      int n = 0;
      mid % 2 == 0 ? n = mid + 1 : n = mid - 1;
      // const int n = mid ^ 1;
      if (nums[n] == nums[mid]) {
        left = mid + 1;
      } else
        right = mid;
    }
    return nums[left];
  }
};
```


