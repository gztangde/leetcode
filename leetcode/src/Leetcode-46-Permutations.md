---
title: Leetcode 46. Permutations
date: 2018-11-19 06:09:31
updated: 2018-11-19 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a collection of  **distinct**  integers, return all possible permutations.

**Example:**

> **Input:** [1,2,3]
> **Output:**
> [
>  [1,2,3],
>  [1,3,2],
>  [2,1,3],
>  [2,3,1],
>  [3,1,2],
>  [3,2,1]
> ]

**Difficulty**:Medium

**Category**:Backtracking  

<!-- more -->

# Analyze

这到题是找到数字的所有排列，按照顺序排序，我们在`Leetcode 31. Next Permutation` 这个题目是已经完成了求解给定排列的下一个排列的情况，所以这道题目，我们直接使用那道题目的函数来循环`n!`次求解就好。

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    unsigned len = nums.size(), res_size = 1;
    for (int i = 1; i <= len; ++i) {
      res_size *= i;
    }
    res.push_back(nums);
    for (int i = 1; i < res_size; ++i) {
      nextPermutation(nums, res);
    }
    return res;
  }
  void nextPermutation(vector<int>& nums, vector<vector<int>>& res) {
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

    // If there are increate order from left to right.
    reverse(nums.begin(), nums.end());
    res.push_back(nums);
    return;
  }
};
```

## Solution 1: DFS

```cpp
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Permutations.
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> out;
    permuteDFS(nums, out, ans);
    return ans;
  }

 private:
  void permuteDFS(vector<int>& nums, vector<int>& out, vector<vector<int>>& ans) {
    if (out.size() == nums.size()) {
      ans.emplace_back(out);
      return;
    }

    for (int& num : nums) {
      if (find(out.begin(), out.end(), num) != out.end()) continue;
      out.emplace_back(num);
      permuteDFS(nums, out, ans);
      out.pop_back();
    }
  }
};
```

下面这种解法, 不使用中间变量的方式来完成:(前提是给的数据是没有重复的元素的)

```cpp
// Runtime: 16 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Permutations.

class Solution {
 public:
  vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    permuteRecursive(num, 0, ans);
    return ans;
  }

  // permute num[begin..end]
  // invariant: num[0..begin-1] have been fixed/permuted
  void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &ans) {
    if (begin >= num.size()) {
      // one permutation instance
      ans.emplace_back(num);
      return;
    }

    for (int i = begin; i < num.size(); i++) {
      swap(num[begin], num[i]);
      permuteRecursive(num, begin + 1, ans);
      // reset
      swap(num[begin], num[i]);
    }
  }
};
```

# Updated

* 03/01/2019 Review(DFS, 10mins)