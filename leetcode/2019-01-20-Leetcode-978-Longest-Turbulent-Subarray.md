---
title: Leetcode 978. Longest Turbulent Subarray
date: 2019-01-20 00:27:20
updated: 2019-01-20 00:27:20
categories: 
- [Leetcode]
- [Leetcode, Array]
tags: Leetcode
notshow: true
top:
---

# Question

A subarray  `A[i], A[i+1], ..., A[j]` of  `A`  is said to be  _turbulent_  if and only if:

-   For  `i <= k < j`,  `A[k] > A[k+1]`  when  `k`  is odd, and  `A[k] < A[k+1]`  when  `k`  is even;
-   **OR**, for  `i <= k < j`,  `A[k] > A[k+1]`  when  `k`  is even, and  `A[k] < A[k+1]`  when  `k`  is odd.

That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

Return the  **length**  of a maximum size turbulent subarray of A.

**Example 1:**

> **Input:** [9,4,2,10,7,8,8,1,9]
> **Output:** 5
> **Explanation:** (A[1] > A[2] < A[3] > A[4] < A[5])

**Example 2:**

> **Input:** [4,8,12,16]
> **Output:** 2

**Example 3:**

> **Input:** [100]
> **Output:** 1

**Note:**

1. `1 <= A.length <= 40000`
2. `0 <= A[i] <= 10^9`

**Difficulty**:Medium

**Category**:Array

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int maxTurbulenceSize(vector<int>& A) {
    if (A.empty()) return 0;
    if (A.size() == 1) return 1;
    int len = A.size();
    int cur = 1;
    int ans = 1;

    bool less = false;
    for (int i = 1; i < A.size(); ++i) {
      if (less == false) {
        less = true;
        if (A[i] > A[i - 1]) {
          ++cur;
          ans = max(cur, ans);
        } else
          cur = 1;
      } else {
        less = false;
        if (A[i] < A[i - 1]) {
          ++cur;
          ans = max(cur, ans);
        } else
          cur = 1;
      }
    }

    less = true;
    cur = 1;
    for (int i = 1; i < A.size(); ++i) {
      if (less == false) {
        less = true;
        if (A[i] > A[i - 1]) {
          ++cur;
          ans = max(cur, ans);
        } else
          cur = 1;
      } else {
        less = false;
        if (A[i] < A[i - 1]) {
          ++cur;
          ans = max(cur, ans);
        } else
          cur = 1;
      }
    }
    return ans;
  }
};
```


