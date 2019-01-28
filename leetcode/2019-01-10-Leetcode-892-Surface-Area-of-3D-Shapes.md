---
title: Leetcode 892. Surface Area of 3D Shapes
date: 2019-01-10 10:48:38
updated: 2019-01-10 10:48:38
categories: Leetcodes
tags: Leetcode
notshow: true
top:
---

# Question

On a `N * N` grid, we place some `1 * 1 * 1` cubes.

Each value `v = grid[i][j]` represents a tower of `v` cubes placed on top of grid cell `(i, j)`.

Return the total surface area of the resulting shapes.

**Example 1:**

> **Input:** [[2]]
> **Output:** 10

**Example 2:**

> **Input:** [[1,2],[3,4]]
> **Output:** 34

**Example 3:**

> **Input:** [[1,0],[0,2]]
> **Output:** 16

**Example 4:**

> **Input:** [[1,1,1],[1,0,1],[1,1,1]]
> **Output:** 32

**Example 5:**

> **Input:** [[2,2,2],[2,1,2],[2,2,2]]
> **Output:** 46

**Note:**

- `1 <= N <= 50`
- `0 <= grid[i][j] <= 50`

**Difficulty**:Medium

**Category**:Math, Geometry

<!-- more -->

------------

# Analyze

------------

# Solution

<!-- TODO: You need to understand this quesiton more powerful. -->
```cpp
// Running time: 8 ms
class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    static const vector<int> dirs{0, -1, 0, 1, 0};
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int h = grid[i][j];
        if (h == 0) continue;
        ans += 2 + 4 * h;
        for (int k = 0; k < 4; k++) {
          int tx = j + dirs[k];
          int ty = i + dirs[k + 1];
          if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
          int th = grid[ty][tx];
          ans -= (th <= 0 ? 0 : min(h, th));
        }
      }
    return ans;
  }
};
```