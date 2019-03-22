---
title: Leetcode 53. Maximum Subarray
date: 2018-12-19 09:09:31
updated: 2018-12-19 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an integer array  `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

**Example:**

**Input:** [-2,1,-3,4,-1,2,1,-5,4],
**Output:** 6
**Explanation:** [4,-1,2,1] has the largest sum = 6.

**Follow up:**

If you have figured out the O(_n_) solution, try coding another solution using the divide and conquer approach, which is more subtle.

**Difficulty**:Easy

**Category**:Array, Divide-and-Conquer, Dynamic-Programming

<!-- more -->

# Analyze

这道题目是求解最大的连续子序列和，依次处理每个元素：

- 如果当前元素加上之前的和 < 这个元素本身的数值， 那么就取这个元素本身的数值作为临时值
- 如果得到的临时数值比之前的最大值还要大，那么就替换这个数值

解决方案：如`Solution1`

# Solution

Time complexity: O(n), Space Complexity: O(1)

```cpp
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN, temp = 0;
    for (int& num : nums) {
      temp = max(temp + num, num);
      ans = max(temp, ans);
    }
    return ans;
  }
};
```

## Solution 2: Divide and Conquer

题目还要求我们用分治法Divide and Conquer Approach来解，这个分治法的思想就类似于二分搜索法，我们需要把数组一分为二，分别找出左边和右边的最大子数组之和，然后还要从中间开始向左右分别扫描，求出的最大值分别和左右两边得出的最大值相比较取最大的那一个

```cpp
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    return helper(nums, 0, (int)nums.size() - 1);
  }

  int helper(vector<int>& nums, int left, int right) {
    if (left >= right) return nums[left];
    int mid = left + (right - left) / 2;
    int lmax = helper(nums, left, mid - 1);
    int rmax = helper(nums, mid + 1, right);
    int mmax = nums[mid], t = mmax;

    for (int i = mid - 1; i >= left; --i) {
      t += nums[i];
      mmax = max(mmax, t);
    }

    t = mmax;
    for (int i = mid + 1; i <= right; ++i) {
      t += nums[i];
      mmax = max(mmax, t);
    }
    return max(mmax, max(lmax, rmax));
  }
};
```