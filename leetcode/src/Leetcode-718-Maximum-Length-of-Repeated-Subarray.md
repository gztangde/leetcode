---
title: Leetcode 718. Maximum Length of Repeated Subarray
date: 2019-02-05 21:30:10
updated: 2019-02-05 21:30:10
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two integer arrays  `A`  and  `B`, return the maximum length of an subarray that appears in both arrays.

**Example 1:**  

**Input:**
A: [1,2,3,2,1]
B: [3,2,1,4,7]
**Output:** 3
**Explanation:** 
The repeated subarray with maximum length is [3, 2, 1].

**Note:**  

1. 1 <= len(A), len(B) <= 1000
2. 0 <= A[i], B[i] < 100

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

```cpp
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    int m = A.size(), n = B.size(), ans = INT_MIN;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < m + 1; ++i) {
      for (int j = 1; j < n + 1; ++j) {
        dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
        ans = max(dp[i][j], ans);
      }
    }
    return ans;
  }
};
```

讨论区有通过一维的方式来实现的, 没怎么看明白: [Java/C++ Clean Code - 8 lines](https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/109068/JavaC%2B%2B-Clean-Code-8-lines)

<!-- TODO:Understand -->

```cpp
class Solution {
 public:
  int findLength(vector<int>& a, vector<int>& b) {
    int m = a.size(), n = b.size();
    vector<int> dp(n + 1);
    int res = 0;
    for (int i = m - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        res = max(res, dp[j] = a[i] == b[j] ? 1 + dp[j + 1] : 0);
      }
    }
    return res;
  }
};
```