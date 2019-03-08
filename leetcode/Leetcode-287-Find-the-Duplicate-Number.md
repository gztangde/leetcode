---
title: Leetcode 287. Find the Duplicate Number
date: 2019-01-21 15:02:42
updated: 2019-01-21 15:02:42
categories: 
- [Leetcode]
- [Leetcode, Array]
- [Leetcode, Two-Points]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given an array  _nums_  containing  _n_  + 1 integers where each integer is between 1 and  _n_  (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

**Example 1:**

**Input:** `[1,3,4,2,2]`
**Output:** 2

**Example 2:**

**Input:** [3,1,3,4,2]
**Output:** 3

**Note:**

1. You  **must not**  modify the array (assume the array is read only).
2. You must use only constant,  _O_(1) extra space.
3. Your runtime complexity should be less than  _O_(_n_2).
4. There is only one duplicate number in the array, but it could be repeated more than once.

**Difficulty**:Medium

**Category**:Array, Two-Points, Binary-Search

<!-- more -->

# Analyze

# Solution

## Solution1: Binary Search

```cpp
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int left = 0, right = nums.size();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int count = 0;
      for (int num : nums)
        if (num <= mid) count++;
      if (count <= mid)
        left = mid + 1;
      else
        right = mid;
    }
    return left;
  }
};
```

## Solution 2: Two-Points

```cpp
// Author: Huahua
// Running time: 4 ms
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (true) {
      // Each step: the slow point move one step
      // Each step: the fast point move two steps
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) break;
    }
    fast = 0;
    while (fast != slow) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
```
