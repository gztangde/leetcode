---
title: Leetcode 213. House Robber II
date: 2019-03-21 21:12:59
updated: 2019-03-21 21:12:59
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

题目大意: 相当于在一列数组中取出一个或多个不相邻数，使其和最大(考虑收尾是相连接的)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are  **arranged in a circle.**  That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight  **without alerting the police**.

**Example 1:**

**Input:** [2,3,2]
**Output:** 3
**Explanation:** You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.

**Example 2:**

**Input:** [1,2,3,1]
**Output:** 4
**Explanation:** Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.

**Difficulty**:Medium

**Category**:

# Analyze


# Solution

## Solution 1: DP

```cpp
class Solution {
public:
 int rob(vector<int>& nums) {
   if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
   return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
 }

 private:
  int rob(vector<int>& nums, int left, int right) {
    int robEven = 0, robOdd = 0, n = nums.size();
    for (int i = left; i < right; ++i) {
      if (i % 2 == 0) {
        robEven = max(robEven + nums[i], robOdd);
      } else {
        robOdd = max(robEven, robOdd + nums[i]);
      }
    }

    return max(robEven, robOdd);
  }
};
```

## Solution 2

```cpp
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
    return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }
  int rob(vector<int>& nums, int left, int right) {
    int rob = 0, notRob = 0;
    for (int i = left; i < right; ++i) {
      int preRob = rob, preNotRob = notRob;
      rob = preNotRob + nums[i];
      notRob = max(preRob, preNotRob);
    }
    return max(rob, notRob);
  }
};
```