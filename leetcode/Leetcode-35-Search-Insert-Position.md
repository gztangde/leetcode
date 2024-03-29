---
title: Leetcode 35. Search Insert Position
date: 2018-10-27 16:09:31
updated: 2018-10-27 16:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question


Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

**Example 1:**

> **Input:** [1,3,5,6], 5
> **Output:** 2

**Example 2:**

> **Input:** [1,3,5,6], 2
> **Output:** 1

**Example 3:**

> **Input:** [1,3,5,6], 7
> **Output:** 4

**Example 4:**

> **Input:** [1,3,5,6], 0
> **Output:** 0

<!-- more -->

---------

# Solution

## Solution 1: Binary Search

```cpp
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.back() < target) return nums.size();
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target)
        return mid;
      else if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }
    return right;
  }
};
```

## Solution 2: Scan

```cpp
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] >= target) return i;
    }
    return nums.size();
  }
};
```