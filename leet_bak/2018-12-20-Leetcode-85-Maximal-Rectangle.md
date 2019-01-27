---
title: Leetcode 85. Maximal Rectangle
date: 2018-12-20 09:09:31
updated: 2018-12-20 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

![](/images/in-post/2018-12-20-Leetcode-85-Maximal-Rectangle/2018-12-20-18-34-36.png)

**Difficulty**:Hard
**Category**:Array, Hash-Table, Dynamic-Programming, Stack

<!-- more -->

------------

# Analyze

这到题目是在二位矩阵上面求解最大的矩形面积。
**方案一：Solution 1:** 这一道题目可以在原来的`Largest Rectangle in Histogram`的基础上来完成.

- 每一行向上的部分看成是一个直方图，我们只需要对每一行计算一次直方图的数值，就可以了
- 输入的矩阵有多少行，就计算多少次直方图的数值

------------

# Solution

```cpp
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int res = 0, m = matrix.size(), n = matrix[0].size();
    vector<int> height;
    for (int i = 0; i < m; ++i) {
      height.resize(n);
      for (int j = 0; j < n; ++j) {
        height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
      }
      res = max(res, largestRectangleArea(height));
    }
    return res;
  }

  int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    std::stack<int> s;
    heights.emplace_back(0);

    for (int i = 0; i < heights.size();) {
      if (s.empty() || heights[i] > heights[s.top()]) {
        s.push(i++);
      } else {
        int tmp = s.top();
        s.pop();
        res = max(res, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
      }
    }
    return res;
  }
};
```

<!-- TODO: Understand the other way to do this questions. -->