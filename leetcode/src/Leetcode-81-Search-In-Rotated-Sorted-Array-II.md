---
title: Leetcode 81. Search in Rotated Sorted Array II
date: 2018-11-07 06:09:31
updated: 2018-11-07 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,0,1,2,2,5,6]`  might become  `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return  `true`, otherwise return  `false`.

**Example 1:**

> **Input:** nums = [2`,5,6,0,0,1,2]`, target = 0
> **Output:** true

**Example 2:**

> **Input:** nums = [2`,5,6,0,0,1,2]`, target = 3
> **Output:** false

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where  `nums`  may contain duplicates.
- Would this affect the run-time complexity? How and why?

<!-- more -->

# Solution

## Solution 1: Binary Search

现在数组中允许出现重复数字，这个也会影响我们选择哪半边继续搜索，由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全符合之前所说的规律：**如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，则左半段是有序的。而如果可以有重复值，就会出现来面两种情况，[3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，目标值3既可以在左边又可以在右边**，那怎么办么，对于这种情况其实处理非常简单，只要把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止

Time complexity: O(logn)
Space complexity: O(1)

> Runtime: 8 ms, faster than 100.00% of C++ online submissions for Search in Rotated Sorted Array II.
> Memory Usage: 8.9 MB, less than 14.56% of C++ online submissions for Search in Rotated Sorted Array II.

```cpp
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left != right) {
      const int mid = left + (right - left) / 2;
      // Find the Target at the mid index.
      if (nums[mid] == target) return true;

      // There are sorted elements in the left part.
      if (nums[left] < nums[mid]) {
        if (nums[left] <= target && nums[mid] > target) {
          right = mid;
        } else {
          left = mid + 1;
        }
      } else if (nums[left] == nums[mid]) {
        left++;
      } else {  // There are sorted elements in the right part.
        if (nums[mid] < target && nums[right - 1] >= target) {
          left = mid + 1;
        } else {
          right = mid;
        }
      }
    }
    return false;
  }
};
```
