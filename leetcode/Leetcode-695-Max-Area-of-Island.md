---
title: Leetcode 695. Max Area of Island
date: 2019-03-13 00:37:43
updated: 2019-03-13 00:37:43
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Question

Given a non-empty 2D array  `grid`  of 0's and 1's, an  **island**  is a group of  `1`'s (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

```
Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return `6`. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return `0`.
```

**Note:**  The length of each dimension in the given  `grid`  does not exceed 50.

**Difficulty**:Medium

**Category**:

# Analyze


# Solution

```cpp
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int y = 0; y < m; ++y)
      for (int x = 0; x < n; ++x) {
        if (grid[y][x] == 0) continue;
        // ans += grid[y][x] - '0';
        int cnt = 1;
        dfs(grid, x, y, m, n, cnt, ans);
      }
    return ans;
  }

 private:
  void dfs(vector<vector<int>>& grid, int x, int y, int m, int n, int& cnt, int& ans) {
    if (x < 0 || y < 0 || x >= n || y >= m || grid[y][x] == 0) return;
    // Change all the grid[y][x] to '0'
    ans = max(ans, cnt++);
    grid[y][x] = 0;
    dfs(grid, x + 1, y, m, n, cnt, ans);
    dfs(grid, x - 1, y, m, n, cnt, ans);
    dfs(grid, x, y + 1, m, n, cnt, ans);
    dfs(grid, x, y - 1, m, n, cnt, ans);
  }
};
```