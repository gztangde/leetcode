---
title: Leetcode 494. Target Sum
date: 2019-01-25 17:29:16
updated: 2019-01-25 17:29:16
categories: 

- [Leetcode]
- [Leetcode, DFS]
- [Leetcode, DP]
tags: Leetcode
notshow: true
top:
---

# Question

You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols  `+`  and  `-`. For each integer, you should choose one from  `+`  and  `-`  as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

**Example 1:**  

```
**Input:** nums is [1, 1, 1, 1, 1], S is 3. 
**Output:** 5
**Explanation:** 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
```

**Note:**  

1. The length of the given array is positive and will not exceed 20.
2. The sum of elements in the given array will not exceed 1000.
3. Your output answer is guaranteed to be fitted in a 32-bit integer.

**Difficulty**:Medium
**Category**:Dynamic-Programming, Depth-First-Search

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: DFS

```cpp
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0, ans = 0;
    for (int& i : nums) sum += i;
    if (sum < abs(S)) return 0;
    dfs(nums, 0, S, ans);
    return ans;
  }

 private:
  void dfs(vector<int>& nums, int index, int s, int& ans) {
    if (index == nums.size()) {
      if (s == 0) ++ans;
      return;
    }
    dfs(nums, index + 1, s - nums[index], ans);
    dfs(nums, index + 1, s + nums[index], ans);
  }
};
```

<!-- TODO: There are about five solutions for this problem. you can find these information from the websit: https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/ -->

