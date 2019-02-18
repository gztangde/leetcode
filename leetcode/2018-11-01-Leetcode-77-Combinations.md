---
title: Leetcode 77. Combinations
date: 2018-11-01 06:09:31
updated: 2018-11-01 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given two integers  _n_  and  _k_, return all possible combinations of  _k_  numbers out of 1 ...  _n_.

**Example:**

**Input:** n = 4, k = 2
**Output:**
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

<!-- more -->

----------

# Solution

```cpp
// Runtime: 100 ms, faster than 78.48% of C++ online submissions for Combinations.
// Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Combinations.
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    res.reserve(n * (n - 1) / 2);
    temp.reserve(k);
    findcombine(n, k, 1, temp, res);
    return res;
  }

  void findcombine(int upper, int nums, int index, vector<int>& temp,
                   vector<vector<int>>& res) {
    if (nums == 0) res.emplace_back(temp);
    for (int i = index; i <= upper; ++i) {
      temp.emplace_back(i);
      findcombine(upper, nums - 1, i + 1, temp, res);
      temp.pop_back();
    }
  }
};
```

## Solution 1: DFS

```cpp
// Runtime: 104 ms, faster than 71.52% of C++ online submissions for Combinations.
// Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Combinations.
class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> out;
    combineDFS(n, k, 1, out, ans);
    return ans;
  }

 private:
  void combineDFS(int n, int k, int index, vector<int>& out, vector<vector<int>>& ans) {
    if (k == 0) {
      ans.emplace_back(out);
      return;
    }
    for (int i = index; i <= n; ++i) {
      out.emplace_back(i);
      combineDFS(n, k - 1, i + 1, out, ans);
      out.pop_back();
    }
  }
};
```