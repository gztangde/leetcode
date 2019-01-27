---
title: Leetcode 1.Two Sum
date: 2018-05-12 00:38:02
updated: 2018-05-12 00:38:02
categories: Leetcode
tags: Leetcode
---

# Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
You may assume that each input would have exactly one solution, and you may not use the same element twice.  
Example:  
> Given nums = [2, 7, 11, 15], target = 9,  
> Because nums[0] + nums[1] = 2 + 7 = 9,  
> return [0, 1]. 

**Difficulty**:Easy
**Category**:Array

<!-- more -->

****

# Analyze

**O(n 2 ) runtime, O(1) space – Brute force**

如果使用暴力搜索，那么时间复杂度为O(n^2))，这会造成Time Limit Exceeded. 所以需要使用O(n)的算法来实现。  

**O(n) runtime, O(n) space – Hash table**

> 1. 先遍历一遍数组，建立HashMap数据
> 2. 第二遍遍历，开始查找，如果找到，则记录下来

<!--more-->

****

## Solution

## Solution 1

```cpp
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numsMap;
    vector<int> ans;
    ans.reserve(2);

    for (int i = 0; i < nums.size(); ++i)
      numsMap[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i) {
      const int diff = target - nums[i];
      if (numsMap.find(diff) != numsMap.end() && numsMap[diff] > i) {
        ans.emplace_back(i);
        ans.emplace_back(numsMap[diff]);
        return ans;
      }
    }
    return ans;
  }
};
```

**优化:** 合并两个`for`循环语句

```cpp
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numsMap;
    for (int i = 0; i < nums.size(); ++i) {
      const int diff = target - nums[i];
      if (numsMap.find(diff) != numsMap.end())
        return {numsMap[diff], i};
      numsMap[nums[i]] = i;
    }
    return {};
  }
};
```