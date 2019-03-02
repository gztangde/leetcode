---
title: Leetcode 90. Subsets II
date: 2018-08-23 13:42:10
updated: 2018-08-23 13:42:10
categories: Leetcode
tags: Leetcode
notshow: true
---

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

> Input: [1,2,2]  
> Output:  
> [  
>  [2],  
>  [1],  
>  [1,2,2],  
>  [2,2],  
>  [1,2],  
>  []  
> ] 


**Difficulty**:Medium

**Category**:  
<!--more-->
*****

# Analyze
这道题目在`78 Subsets`的基础上添加了处理重复元素的部分，所以在这个位置需要对重复元素进程处理，需要保证不能有重复的子集出现在回答中。    


# solution

## Solution 1 : DFS

```cpp
class Solution {
 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    if (nums.empty()) return {{}};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> out;
    ans.emplace_back(out);
    subsetsWithDupDFS(nums, 0, out, ans);
    return ans;
  }
 private:
  void subsetsWithDupDFS(vector<int>& nums, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (index == nums.size()) return;
    for (int i = index; i < nums.size(); ++i) {
      if (i > index && nums[i] == nums[i - 1]) continue;
      out.emplace_back(nums[i]);
      ans.emplace_back(out);
      subsetsWithDupDFS(nums, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```


# updated

* 03/01/2019 Review(BFS 6mins)