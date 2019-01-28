---
title: Leetcode 885. Spiral Matrix III
date: 2019-01-23 21:34:12
updated: 2019-01-23 21:34:12
categories: 
- [Leetcode]
- [Leetcode, Math]
tags: Leetcode
notshow: true
top:
---

# Question

On a 2 dimensional grid with  `R`  rows and  `C`  columns, we start at  `(r0, c0)`facing east.

Here, the north-west corner of the grid is at the first row and column, and the south-east corner of the grid is at the last row and column.

Now, we walk in a clockwise spiral shape to visit every position in this grid.

Whenever we would move outside the boundary of the grid, we continue our walk outside the grid (but may return to the grid boundary later.)

Eventually, we reach all  `R * C`  spaces of the grid.

Return a list of coordinates representing the positions of the grid in the order they were visited.

**Example 1:**

**Input:** R = 1, C = 4, r0 = 0, c0 = 0
**Output:** [[0,0],[0,1],[0,2],[0,3]]

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_1.png)

**Example 2:**

**Input:** R = 5, C = 6, r0 = 1, c0 = 4
**Output:** [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/24/example_2.png)

**Note:**

1. `1 <= R <= 100`
2. `1 <= C <= 100`
3. `0 <= r0 < R`
4. `0 <= c0 < C`

**Difficulty**:Medium
**Category**:Math

<!-- more -->

------------

# Analyze

走的步数的规律:
* 右移一步，向右转
* 下移一步，向右转
* 左移两步，向右转
* 上移两步，向右转
* 右移三步，向右转
* 下移三步，向右转
* 左移四步，向右转
* 上移四步，向右转

记录转方向的次数为i, 所以可以得到每一次走的步数是 `i/2 + 1`

------------

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
    vector<vector<int>> ans = {{r0, c0}};
    int x = 0, y = 1;
    for (int i = 0; ans.size() < R * C; ++i) {
      for (int j = 0; j < (i / 2) + 1; ++j) {
        r0 += x;
        c0 += y;
        if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) ans.push_back({r0, c0});
      }
      int temp = x;
      x = y;
      y = -temp;
    }
    return ans;
  }
};
```