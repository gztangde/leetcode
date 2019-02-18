---
title: Leetcode 216. Combination Sum III
date: 2018-10-31 16:09:31
updated: 2018-10-31 16:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Find all possible combinations of  _**k**_  numbers that add up to a number  _**n**_, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

**Note:**

- All numbers will be positive integers.
- The solution set must not contain duplicate combinations.

**Example 1:**

> **Input:** _**k**_ = 3, _**n**_ = 7
> **Output:** [[1,2,4]]

**Example 2:**

> **Input:** _**k**_ = 3, _**n**_ = 9
> **Output:** [[1,2,6], [1,3,5], [2,3,4]]

<!-- more -->

--------

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> temp;
    res.reserve(3);
    findcombination(n, k, 1, temp, res);
    return res;
  }

  void findcombination(int n, int k, int nums, vector<int> &temp,
                       vector<vector<int>> &res) {
    if (n < 0) return;
    if (n == 0 && temp.size() == k) res.emplace_back(temp);
    for (int i = nums; i <= 9; ++i) {
      temp.emplace_back(i);
      findcombination(n - i, k, i + 1, temp, res);
      temp.pop_back();
    }
  }
};
```

## Solution 1 : DFS

```cpp
class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> out;
    combinationSum3DFS(k, n, 1, out, ans);
    return ans;
  }

 private:
  void combinationSum3DFS(int k, int target, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (out.size() == k) {
      if (target == 0) ans.emplace_back(out);
      return;
    }
    for (int i = index; i < 10; ++i) {
      out.emplace_back(i);
      combinationSum3DFS(k, target - i, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```