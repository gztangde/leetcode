---
title: Leetcode 287. Find the Duplicate Number
date: 2019-01-26 16:43:02
updated: 2019-01-26 16:43:02
categories: 
- [Leetcode]
- [Leetcode, Array]
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
**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

双指针的解法

<!-- TODO:Think about using 二分查找的方法
public int findDuplicate(int[] nums) {
     int l = 1, h = nums.length - 1;
     while (l <= h) {
         int mid = l + (h - l) / 2;
         int cnt = 0;
         for (int i = 0; i < nums.length; i++) {
             if (nums[i] <= mid) cnt++;
         }
         if (cnt > mid) h = mid - 1;
         else l = mid + 1;
     }
     return l;
}
 -->

```cpp
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

<!-- 
------------

# Leetcode Question Summary


------------ -->
