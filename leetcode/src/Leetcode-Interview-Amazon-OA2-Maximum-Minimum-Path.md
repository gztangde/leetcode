---
title: Maximum Minimum Path
date: 2019-03-08 23:36:09
updated: 2019-03-08 23:36:09
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Maximum Minimum Path

计算到目标位置的最小路径里面的(最左上角-->最右下角)，最大的那一个最小值。 给一个n*m矩阵，元素表示在该点的高度。从矩阵左上角开始爬山，爬到右下角。会有许多最短路径（长度都是n+m-2），这些路径都会有各自的最低海拔min_i，求这些min_i的最大值

# Solution

## Solution 1: DP

这道题目的 `C++` 代码来自于 `Leetcode 174. Dungeon Game` question.

![](images/2019-02-28-18-49-52.png)

Time complexity: O(mn)
Space complexity: O(n)

```cpp
int helper(vector<vector<int>>& matrix) {
  int n = matrix.size();
  vector<int> res(n, 0);
  res[0] = matrix[0][0];
  for (int i = 1; i < matrix[0].size(); ++i) {
    res[i] = min(res[i - 1], matrix[0][i]);
  }

  for (int i = 1; i < matrix.size(); i++) {
    res[0] = min(matrix[i][0], res[0]);
    for (int j = 1; j < matrix[0].size(); ++j) {
      res[j] = (res[j] < matrix[i][j] && res[j - 1] < matrix[i][j]) ? max(res[j - 1], res[j]) : matrix[i][j];
    }
  }
  return res[res.size() - 1];
}
```

## Solution 2: DFS

```java
 public class MaximumMinimumPath {
    private int min, max, row, col;
    public int maxMinPath(int[][] matrix) {
        row = matrix.length;
        col = matrix[0].length;
        min = Integer.MAX_VALUE;
        max = Integer.MIN_VALUE;
        dfsHelper(matrix, min, 0, 0);
     return max;
    }

    public void dfsHelper(int[][] matrix, int min, int i, int j ){
        if (i >= row || j >= col) return;
        if (i == row - 1 && j == col - 1) {
            min = Math.min(min, matrix[i][j]);
            max = Math.max(max, min);
            return;
        }
        min = Math.min(min, matrix[i][j]);
        dfsHelper(matrix, min, i, j + 1);
        dfsHelper(matrix, min, i + 1, j);
    }
}
```