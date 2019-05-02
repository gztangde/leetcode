---
title: Leetcode 980. Unique Paths III
date: 2019-01-25 15:54:56
updated: 2019-01-25 15:54:56
categories: 
- [Leetcode]
- [Leetcode, Dynamic-Programming]
- [Leetcode, Backtracking]
tags: Leetcode
notshow: true
top:
---

# Question

On a 2-dimensional `grid`, there are 4 types of squares:

- `1`  represents the starting square. There is exactly one starting square.
- `2`  represents the ending square. There is exactly one ending square.
- `0`  represents empty squares we can walk over.
- `-1`  represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, that  **walk over every non-obstacle square exactly once**.

**Example 1:**

```
**Input:** [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
**Output:** 2
**Explanation:** We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
```

**Example 2:**

```
**Input:** [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
**Output:** 4
**Explanation:** We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
```

**Example 3:**

```
**Input:** [[0,1],[2,0]]
**Output:** 0
**Explanation:** 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
```

**Note:**

1. `1 <= grid.length * grid[0].length <= 20`


**Difficulty**:Hard

**Category**:Dynamic-Programming, Backtracking

<!-- more -->

# Analyze

这是一道周赛的题目, 参考了讨论区的[解法](https://leetcode.com/problems/unique-paths-iii/discuss/221941/C%2B%2B-brute-force-DFS)

使用DFS来完成这道题目.

# Solution

## Solution 1: 使用DFS完成

```cpp
class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int x_1 = 0, y_1 = 0, t_steps = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          x_1 = i;
          y_1 = j;
        }
        if (grid[i][j] != -1) t_steps++;
      }
    }
    return pathsearch(grid, x_1, y_1, 1, t_steps);
  }

 private:
  int pathsearch(vector<vector<int>>& g, int x, int y, int steps, int t_steps) {
    if (x < 0 || y < 0 || x == g.size() || y >= g[0].size() || g[x][y] == -1) return 0;
    if (g[x][y] == 2) {
      return steps == t_steps ? 1 : 0;
    }

    g[x][y] = -1;
    int paths = pathsearch(g, x + 1, y, steps + 1, t_steps) + pathsearch(g, x - 1, y, steps + 1, t_steps) +
                pathsearch(g, x, y + 1, steps + 1, t_steps) + pathsearch(g, x, y - 1, steps + 1, t_steps);
    g[x][y] = 0;
    return paths;
  }
};
```

## Solution 2: 动态规划

<!-- TODO: You need to find this solution to do this side. -->

