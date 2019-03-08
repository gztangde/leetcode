---
title: Leetcode 963. Minimum Area Rectangle II
date: 2019-02-13 17:01:26
updated: 2019-02-13 17:01:26
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given a set of points in the xy-plane, determine the minimum area of  **any**  rectangle formed from these points, with sides  **not necessarily parallel**  to the x and y axes.

If there isn't any rectangle, return 0.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/21/1a.png)

**Input:** [[1,2],[2,1],[1,0],[0,1]]
**Output:** 2.00000
**Explanation:** The minimum area rectangle occurs at [1,2],[2,1],[1,0],[0,1], with an area of 2.

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/22/2.png)

**Input:** [[0,1],[2,1],[1,1],[1,0],[2,0]]
**Output:** 1.00000 **Explanation:** The minimum area rectangle occurs at [1,0],[1,1],[2,1],[2,0], with an area of 1.

**Example 3:**

![](https://assets.leetcode.com/uploads/2018/12/22/3.png)

**Input:** [[0,3],[1,2],[3,1],[1,3],[2,1]]
**Output:** 0 **Explanation:** There is no possible rectangle to form from these points.

**Example 4:**

![](https://assets.leetcode.com/uploads/2018/12/21/4c.png)

**Input:** [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
**Output:** 2.00000 **Explanation:** The minimum area rectangle occurs at [2,1],[2,3],[3,3],[3,1], with an area of 2.

**Note:**

1. `1 <= points.length <= 50`
2. `0 <= points[i][0] <= 40000`
3. `0 <= points[i][1] <= 40000`
4. All points are distinct.
5. Answers within  `10^-5`  of the actual value will be accepted as correct.

**Difficulty**:Medium

**Category**:Math, Geometry

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    int n = points.size();
    bool find = false;
    double ans = INT_MAX;
    vector<vector<int>>& P = points;
    for (int a = 0; a < n; ++a)
      for (int b = 0; b < n; ++b)
        for (int c = 0; c < n; ++c)
          for (int d = 0; d < n; ++d) {
            if (a == b || a == c || a == d || b == c || b == d || c == d) continue;
            if (P[a][0] - P[b][0] != P[d][0] - P[c][0]) continue;
            // Deal with the parallel sides
            if (P[a][1] - P[b][1] != P[d][1] - P[c][1]) continue;

            double x1 = P[a][0] - P[b][0];
            double x2 = P[c][0] - P[b][0];
            double y1 = P[a][1] - P[b][1];
            double y2 = P[c][1] - P[b][1];

            if (x1 * x2 + y1 * y2 == 0) {
              double area = abs(x1 * y2 - x2 * y1);
              if (area > 0 && area < ans) {
                find = true;
                ans = area;
              }
            }
          }
    if (!find) return 0;
    return ans;
  }
};
```