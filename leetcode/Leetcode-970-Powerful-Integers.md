---
title: Leetcode 169. Majority Element
date: 2019-01-08 09:09:31
updated: 2019-01-08 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given two non-negative integers  `x`  and  `y`, an integer is  _powerful_ if it is equal to  `x^i + y^j` for some integers  `i >= 0`  and  `j >= 0`.

Return a list of all  _powerful_  integers that have value less than or equal to  `bound`.

You may return the answer in any order. In your answer, each value should occur at most once.

**Example 1:**

> **Input:** x = 2, y = 3, bound = 10
> **Output:** [2,3,4,5,7,9,10]
> **Explanation:**
> 2 = 2^0 + 3^0
> 3 = 2^1 + 3^0
> 4 = 2^0 + 3^1
> 5 = 2^1 + 3^1
> 7 = 2^2 + 3^1
> 9 = 2^3 + 3^0
> 10 = 2^0 + 3^2

**Example 2:**

> **Input:** x = 3, y = 5, bound = 15
> **Output:** [2,4,6,8,10,14]

**Note:**

- `1 <= x <= 100`
- `1 <= y <= 100`
- `0 <= bound <= 10^6`

**Difficulty**:Easy

**Category**:Math

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, int bound) {
    vector<int> ans;
    unordered_set<int> res;
    if (bound == 0) return ans;
    int m = 0, n = 0;
    if (x != 1) m = log(bound) / log(x);
    if (y != 1) n = log(bound) / log(y);

    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        int p = pow(x, i) + pow(y, j);
        if (p <= bound) {
          if (res.count(p)) continue;
          res.insert(p);
          ans.emplace_back(p);
        }
      }
    }
    return ans;
  }
};
```