---
title: Leetcode 962. Maximum Width Ramp
date: 2019-02-13 16:05:51
updated: 2019-02-13 16:05:51
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given an array  `A`  of integers, a  _ramp_ is a tuple  `(i, j)`  for which  `i < j` and `A[i] <= A[j]`. The width of such a ramp is  `j - i`.

Find the maximum width of a ramp in  `A`. If one doesn't exist, return 0.

**Example 1:**

**Input:** [6,0,8,2,1,5]
**Output:** 4
**Explanation:** 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.

**Example 2:**

**Input:** [9,8,1,0,1,9,4,0,4,1]
**Output:** 7
**Explanation:** 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int maxWidthRamp(vector<int>& A) {
    vector<int> s;
    int best = 0;
    for (int i = 0; i < A.size(); i++) {
      // 如果上一个数字大于当前的数字, 那么就放到 s 里面去
      // s 里面保存的都是 单调减的元素
      // 当我们处理到后面元素之后, 只需要找前面的部分就好了
      if (s.empty() || A[s.back()] > A[i]) s.push_back(i);
      int l = 0, r = s.size() - 1;
      int ans = 0;
      while (l <= r) {
        int m = l + (r - l) / 2;
        // Find A[i] <= A[j] , i < j
        // S[m] < i
        // 找到第一个小于等于的数字
        if (A[s[m]] <= A[i]) {
          ans = i - s[m];
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      best = max(best, ans);
    }
    return best;
  }
};
```