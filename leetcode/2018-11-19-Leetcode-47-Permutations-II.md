---
title: Leetcode 47. Permutations II
date: 2018-11-19 06:09:31
updated: 2018-11-19 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

**Example:**

> **Input:** [1,1,2]
> **Output:**
> [
>  [1,1,2],
>  [1,2,1],
>  [2,1,1]
> ]

**Difficulty**:Medium

**Category**:Backtracking  

<!-- more -->

------------

# Analyze

这到题是找到数字的所有不重复排列，按照顺序排序，我们在`Leetcode 31. Next Permutation` 这个题目是已经完成了求解给定排列的下一个排列的情况，所以这道题目，我们直接使用那道题目的函数来循环求解就好,当出现要循环到最开始的时候，就停止。

------------

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    bool done = false;
    unsigned res_size = 1;
    for (int i = 1; i <= nums.size(); ++i) {
      res_size *= i;
    }
    res.push_back(nums);
    for (int i = 1; i < res_size; ++i) {
      nextPermutation(nums, res, done);
      if (done) return res;
    }
    return res;
  }
  void nextPermutation(vector<int>& nums, vector<vector<int>>& res, bool& done) {
    unsigned len = nums.size() - 1;

    // Find an element from the right to left.
    for (int i = len - 1; i >= 0; --i) {
      if (nums[i + 1] > nums[i]) {
        for (int j = len; j > i; --j) {
          if (nums[j] > nums[i]) {
            swap(nums[j], nums[i]);
            reverse(nums.begin() + i + 1, nums.end());
            res.push_back(nums);
            return;
          }
        }
      }
    }
    done = true;
    return;
  }
};
```

## Solution 1: DFS

```cpp
// Runtime: 32 ms, faster than 72.85% of C++ online submissions for Permutations II.
// Memory Usage: 10 MB, less than 100.00% of C++ online submissions for Permutations II.
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> out;
    vector<int> used(nums.size(), 0);
    permuteUniqueDFS(nums, used, out, ans);
    return ans;
  }

 private:
  void permuteUniqueDFS(vector<int>& nums, vector<int>& used, vector<int>& out, vector<vector<int>>& ans) {
    if (out.size() == nums.size()) {
      ans.emplace_back(out);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;
      // Same number can be only used once at each depth.
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
      used[i] = 1;
      out.emplace_back(nums[i]);
      permuteUniqueDFS(nums, used, out, ans);
      out.pop_back();
      used[i] = 0;
    }
  }
};
```

## Solution 2: 迭代

```cpp
// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Permutations II.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Permutations II.
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.emplace_back(nums);
    } while (nextPermutation(nums, 0, nums.size() - 1));
    return res;
  }

 private:
  bool nextPermutation(vector<int>& v, int left, int right) {
    if (left >= right) return false;

    int i, j;
    i = right - 1;
    while (i >= left && v[i] >= v[i + 1]) --i;
    if (i < left) return false;

    j = right;
    while (v[i] >= v[j]) --j;

    std::swap(v[i], v[j]);
    std::reverse(v.begin() + i + 1, v.begin() + right + 1);
    return true;
  }
};
```