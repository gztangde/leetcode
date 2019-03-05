---
title: Leetcode 33. Search in Rotated Sorted Array
date: 2018-11-06 06:09:31
updated: 2018-11-06 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]`  might become  `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return  `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of _O_(log _n_).

**Example 1:**

> **Input:** nums = [`4,5,6,7,0,1,2]`, target = 0
> **Output:** 4

**Example 2:**

> **Input:** nums = [`4,5,6,7,0,1,2]`, target = 3
> **Output:** -1

<!-- more -->

# Solution

## Solution 1: Binary Search

二分查找, 确定左右边界, 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的，我们只要在有序的半段里用首尾两个数组来判断目标值是否在这一区域内，这样就可以确定保留哪半边了，代码如下：

Time complexity: O(log n)
Space complexity: O(1)

```cpp
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left != right) {
      const int mid = left + (right - left) / 2;
      // Find the Target at the mid index.
      if (nums[mid] == target) return mid;

      // There are sorted elements in the left part.
      if (nums[left] <= nums[mid]) {
        nums[left] <= target&& nums[mid] >= target ? right = mid : left = mid + 1;
      } else {  // There are sorted elements in the right part.
        nums[mid] < target&& nums[right - 1] >= target ? left = mid + 1 : right = mid;
      }
    }

    return -1;
  }
};
```