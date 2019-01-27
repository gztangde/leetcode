
# Question

A robot is located at the top-left corner of a  _m_  x  _n_  grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

![](/images/in-post/2018-12-22-Leetcode-63-Unique-Paths-II/2018-12-23-00-46-58.png)

An obstacle and empty space is marked as  `1`  and  `0`  respectively in the grid.

**Note:**  _m_  and  _n_  will be at most 100.

**Example 1:**
![](/images/in-post/2018-12-22-Leetcode-63-Unique-Paths-II/2018-12-23-00-47-20.png)

**Difficulty**:Medium
**Category**:Array, Dynamic-Programming


------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) return 0;
    const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;

    vector<int> f(n, 0);
    f[0] = obstacleGrid[0][0] ? 0 : 1;
    for (int i = 0; i < m; ++i) {
      f[0] = f[0] == 0 ? 0 : (obstacleGrid[i][0] ? 0 : 1);
      for (int j = 1; j < n; ++j) {
        f[j] = obstacleGrid[i][j] ? 0 : (f[j] + f[j - 1]);
      }
    }
    return f[n - 1];
  }
};
```

------------
