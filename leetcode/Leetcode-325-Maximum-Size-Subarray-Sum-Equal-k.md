---
title: Leetcode 325. Maximum Size Subarray Sum Equals k
date: 2019-03-02 16:41:46
updated: 2019-03-02 16:41:46
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 325. Maximum Size Subarray Sum Equals k

Given an array  _nums_  and a target value  _k_, find the maximum length of a subarray that sums to  _k_. If there isn't one, return 0 instead.

**Example 1:**  

Given  _nums_  =  `[1, -1, 5, -2, 3]`,  _k_  =  `3`,  
return  `4`. (because the subarray  `[1, -1, 5, -2]`  sums to 3 and is the longest)

**Example 2:**  

Given  _nums_  =  `[-2, -1, 2, 1]`,  _k_  =  `1`,  
return  `2`. (because the subarray  `[-1, 2]`  sums to 1 and is the longest)

**Follow Up:**  
Can you do it in O(_n_) time?

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

这道题给我们一个一维数组nums，让我们求和为k最大子数组，默认子数组必须连续，题目中提醒我们必须要在O(n)的时间复杂度完成. 

# Solution

该方案来自于博客文章：[Maximum Size Subarray Sum Equals k 最大子数组之和为k](http://www.cnblogs.com/grandyang/p/5336668.html)

```cpp
class Solution {
 public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    // sum: 累加
    int sum = 0, res = 0;
    unordered_map<int, int> m; // [value -> lastindex]
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      //边累加边处理
      if (sum == k)
        res = i + 1;
      else if (m.count(sum - k))
        res = max(res, i - m[sum - k]);
      // Save the first index when we get the sum
      if (!m.count(sum)) m[sum] = i;
    }
    return res;
  }
};
```