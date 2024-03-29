---
title: Leetcode 78. Subsets
date: 2018-08-23 07:42:10
updated: 2018-08-23 07:42:10
categories: Leetcode
tags: Leetcode
notshow: true
---
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

> Input: nums = [1,2,3]
> Output:
> [
>  [3],
>  [1],
>  [2],
>  [1,2,3],
>  [1,3],
>  [2,3],
>  [1,2],
>  []
> ]

**Difficulty**:Medium

**Category**:  
<!--more-->
*****

# Analyze

求子集集合的问题，我们可以每次处理一个元素，将当前的元素加到之前存在的所有子集里面，这样能够很方便的处理。

需要提前压进去一个空集

# Solution

## Solution 1 : DFS

```cpp
// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Subsets.
class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    if (nums.empty()) return {{}};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> out;
    ans.emplace_back(out);
    subsetsDFS(nums, 0, out, ans);
    return ans;
  }

 private:
  void subsetsDFS(vector<int>& nums, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (index == nums.size()) return;
    for (int i = index; i < nums.size(); ++i) {
      out.emplace_back(nums[i]);
      ans.emplace_back(out);
      subsetsDFS(nums, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```

## Solution 2: BFS

```cpp
// Non-recursion
class Solution {
 public:
  vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int> > res(1);
    sort(S.begin(), S.end());
    for (int i = 0; i < S.size(); ++i) {
      int len = res.size();
      for (int j = 0; j < len; ++j) {
        res.push_back(res[j]);
        res.back().push_back(S[i]);
      }
    }
    return res;
  }
};
```

# Updated

* 03/01/2019 Review(BFS: 5mins)