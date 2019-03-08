---
title: Leetcode 986. Interval List Intersections
date: 2019-02-03 00:54:58
updated: 2019-02-03 00:54:58
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two lists of  **closed**  intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

_(Formally, a closed interval  `[a, b]`  (with  `a <= b`) denotes the set of real numbers  `x`  with  `a <= x <= b`. The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].)_

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/01/30/interval1.png)**

**Input:** A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
**Output:** [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
**Reminder:** The inputs and the desired output are lists of Interval objects, and not arrays or lists.

**Note:**

1. `0 <= A.length < 1000`
2. `0 <= B.length < 1000`
3. `0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9`

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
    vector<Interval> ans;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
      int start = max(A[i].start, B[j].start);
      int end = min(A[i].end, B[j].end);

      if (end >= start) ans.emplace_back(Interval(start, end));
      if (A[i].end < B[j].end) {
        ++i;
      } else
        ++j;
    }
    return ans;
  }
};
```