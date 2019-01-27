---
title: Leetcode 120. Triangle
date: 2018-12-18 09:09:31
updated: 2018-12-18 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

![](/images/in-post/2018-12-18-Leetcode-120-Triangle/2018-12-19-15-36-57.png)

The minimum path sum from top to bottom is  `11`  (i.e.,  **2**  +  **3**  +  **5**  +  **1**  = 11).

**Note:**

Bonus point if you are able to do this using only  _O_(_n_) extra space, where  _n_  is the total number of rows in the triangle.

**Difficulty**:Medium
**Category**:Array, Dynamic-Programming

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = triangle.size() - 2; i >= 0; --i) {
      for (int j = 0; j < i + 1; ++j) triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
    return triangle[0][0];
  }
};
```