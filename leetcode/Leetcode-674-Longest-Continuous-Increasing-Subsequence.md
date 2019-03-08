---
title: Leetcode 674. Longest Continuous Increasing Subsequence
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given an unsorted array of integers, find the length of longest  `continuous`  increasing subsequence (subarray).

**Example 1:**  

> **Input:** [1,3,5,4,7]
> **Output:** 3
> **Explanation:** The longest continuous increasing subsequence is [1,3,5], its length is 3. Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 

**Example 2:**  

> **Input:** [2,2,2,2,2]
> **Output:** 1
> **Explanation:** The longest continuous increasing subsequence is [2], its length is 1. 

**Note:**  Length of the array will not exceed 10,000.

**Difficulty**:Easy

**Category**:Array, DP

<!-- more -->

# Analyze

# Solution

## Solution 1: 动态规划求解

![](/images/in-post/2019-01-07-Leetcode-674-Longest-Continuous-Increasing-Subsequence/2019-01-07-23-04-23.png)

```cpp
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> res(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) res[i] = res[i - 1] + 1;
    }

    int max_res = 1;
    for (int i : res) max_res = max(max_res, i);
    return max_res;
  }
};
```

## Solution 2: 优化

```cpp
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int cur = 1;
    int ans = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++cur;
        ans = max(cur, ans);
      } else
        cur = 1;
    }

    return ans;
  }
};
```
