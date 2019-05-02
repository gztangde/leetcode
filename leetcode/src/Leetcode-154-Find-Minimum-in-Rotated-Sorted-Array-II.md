---
title: Leetcode 154. Find Minimum in Rotated Sorted Array II
date: 2019-03-11 14:23:32
updated: 2019-03-11 14:23:32
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 154. Find Minimum in Rotated Sorted Array II

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

Find the minimum element.

The array may contain duplicates.

**Example 1:**

**Input:** [1,3,5]
**Output:** 1

**Example 2:**

**Input:** [2,2,2,0,1]
**Output:** 0

**Note:**

- This is a follow up problem to [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/).
- Would allow duplicates affect the run-time complexity? How and why?

**Difficulty**:Hard

**Category**:

# Solution

## Solution 1: Binary Search

```cpp
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1, ans = nums[0];
    if (nums[left] < nums[right]) return nums[0];

    while (left < right - 1) {
      int mid = left + (right - left) / 2;

      // If the mid value > left value, then move the right part search.
      if (nums[left] < nums[mid]) {
        ans = min(ans, nums[left]);
        left = mid;
      }
      else if (nums[left] > nums[mid]) right = mid;
      else ++left;
    }
    return min(ans, min(nums[left], nums[right]));
  }
};
```

## Solution 2: Divide and conquer

cite: [花花酱 LeetCode 154. Find Minimum in Rotated Sorted Array II](https://zxi.mytechroad.com/blog/divide-and-conquer/leetcode-154-find-minimum-in-rotated-sorted-array-ii/)

Time complexity:
* Average: O(log n)
* Worst: O(n)

Space complexity: O(1)

```cpp
// Author: Huahua
class Solution {
public:
    int findMin(vector<int> &num) {
        return findMin(num, 0, num.size()-1);
    }

    int findMin(const vector<int>& num, int l, int r)
    {
        // One or two elements, solve it directly
        if (l+1 >= r) return
            min(num[l], num[r]);

        // Sorted
        if (num[l] < num[r])
            return num[l];

        int m = l + (r-l)/2;

        // Recursively find the solution
        return min(findMin(num, l, m - 1),
                   findMin(num, m, r));
    }
};
```