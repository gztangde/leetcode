---
title: Leetcode 778. Swim in Rising Water
date: 2019-03-11 16:54:44
updated: 2019-03-11 16:54:44
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
---

# Leetcode 778. Swim in Rising Water

On an N x N  `grid`, each square  `grid[i][j]`  represents the elevation at that point  `(i,j)`.

Now rain starts to fall. At time  `t`, the depth of the water everywhere is  `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most `t`. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square  `(0, 0)`. What is the least time until you can reach the bottom right square  `(N-1, N-1)`?

**Example 1:**

**Input:** [[0,2],[1,3]]
**Output:** 3
**Explanation:**
At time `0`, you are in grid location `(0, 0)`.
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point `(1, 1)` until time `3`.
When the depth of water is `3`, we can swim anywhere inside the grid.

**Example 2:**

**Input:** [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
**Output:** 16

**Explanation:**

 **0  1  2  3  4**

24 23 22 21  **5**

**12 13 14 15 16**

**11** 17 18 19 20

**10  9  8  7  6**

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

**Note:**

1.  `2 <= N <= 50`.
2.  grid[i][j] is a permutation of [0, ..., N*N - 1].

**Difficulty**:Hard

**Category**:

# Solution

这道题目输入是一个二维数组，当成一个水池，不同的数字代表了在水池里面台阶的高度。然后水面高度不断的上升，判断在水面高度上升到最低的高度，可以从左上角到达右下角。

## Solution 1: Binary Search + BFS

使用二分搜索，以子函数作为判断关系进行搜索

由于题目中给定了数字的范围，那么二分搜索法的左右边界就有了，然后我们计算一个中间值mid，调用子函数来看这个水面高度下能否到达右下角，如果不能的话，说明水面高度不够，则 left = mid+1，如果能到达的话，有可能水面高度过高了，则right = mid，最终会到达的临界点就是能到达右下角的最低水面高度。那么来看子函数怎么写，其实就是个迷宫遍历问题，我们可以使用BFS或者DFS，这里使用了stack辅助的迭代形式的DFS来遍历，当然我们也可以使用queue辅助的迭代形式的BFS来遍历，都一样，如果在mid的水面高度下，遍历到了右下角，则返回true，否则返回false，

```cpp
// grid[i][j] is a permutation of [0, ..., N*N - 1], so we can try to use binary search to solve this problem.
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    int left = grid[0][0], right = n * n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (!helper(grid, mid)) left = mid + 1;
      else right = mid;
    }
    return left;
  }

 private:
  bool helper(vector<vector<int>>& grid, int mid) {
    int n = grid.size();
    unordered_set<int> visited{0};
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    stack<int> st{{0}};
    while (!st.empty()) {
      int row = st.top() / n, col = st.top() % n;
      st.pop();
      if (row == n - 1 && col == n - 1) return true;

      for (auto dir : dirs) {
        int new_row = row + dir[0], new_col = col + dir[1];
        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= n || visited.count(new_row * n + new_col) || grid[new_row][new_col] > mid) continue;
        st.push(new_row * n + new_col);
        visited.insert(new_row * n + new_col);
      }
    }
    return false;
  }
};
```

另外一种写法： Cite- [花花酱 LeetCode 778. Swim in Rising Water](https://zxi.mytechroad.com/blog/heap/leetcode-778-swim-in-rising-water/)

Time complexity: O(2 logn * n^2), Space complexity: O(n^2)

```cpp
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    auto hasPath = [&grid, n](int t) {
      if (grid[0][0] > t) return false;
      queue<int> q;
      vector<int> seen(n * n);
      vector<int> dirs{1, 0, -1, 0, 1};
      q.push(0);

      while (!q.empty()) {
        const int x = q.front() % n;
        const int y = q.front() / n;
        q.pop();
        if (x == n - 1 && y == n - 1) return true;
        for (int i = 0; i < 4; ++i) {
          const int tx = x + dirs[i];
          const int ty = y + dirs[i + 1];
          if (tx < 0 || ty < 0 || tx >= n || ty >= n || grid[ty][tx] > t) continue;
          const int key = ty * n + tx;
          if (seen[key]) continue;
          seen[key] = 1;
          q.push(key);
        }
      }
      return false;
    };

    int left = 0;
    int right = n * n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (hasPath(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
```

## Solution 2: BFS

我们每次都使用当前的最低位置进行遍历，并使用最小堆来记录数据，每次先处理高度低的地方，如果当前位置以及是最右下角的话，我们就返回当前的水面高度。使用`unordered_set<int> visited{0};`作为标记，如果当前可以扩展的元素的四周，如果未越界其并没有被访问过，则将其标记为已访问。

Time complexity: O(n), Space complexity: O(1).

> Runtime: 28 ms, faster than 56.25% of C++ online submissions for Swim in Rising Water.
> 
> Memory Usage: 11.8 MB, less than 52.63% of C++ online submissions for Swim in Rising Water.


```cpp
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int ans = 0, n = grid.size();
    unordered_set<int> visited{0};

    // Set the directions
    vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    // Compare function
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) { return a.first > b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
    q.push({grid[0][0], 0});  // <value, index>
    while (!q.empty()) {
      int row = q.top().second / n, col = q.top().second % n;
      ans = max(ans, grid[row][col]);
      q.pop();
      if (row == n - 1 && col == n - 1) return ans;

      for (auto& dir : dirs) {
        int new_row = row + dir[0], new_col = col + dir[1];

        if (new_row < 0 || new_row >= n || new_col < 0 || new_col >= n || visited.count(new_row * n + new_col))
          continue;
        visited.insert(new_row * n + new_col);
        q.push({grid[new_row][new_col], new_row * n + new_col});
      }
    }
    return ans;
  }
};
```

## Solution 3: DP + DFS

使用一个二维数组`dp`，其中 `dp[i][j] 表示到达 (i, j) 位置所需要的最低水面高度，均初始化为整型数最大值`.

我们的递归函数函数需要知道当前的位置 (x, y)，还有当前的水高cur，同时传入grid数组和需要不停更新的dp数组，如果当前位置越界了，或者是当前水高和 grid[x][y] 中的较大值大于等于 dp[x][y] 了，直接跳过，因为此时的dp值更小，不需要被更新了。否则 dp[x][y] 更新为较大值，然后对周围四个位置调用递归函数继续更新dp数组，最终返回右下位置的dp值即可.

> Runtime: 6712 ms, faster than 5.73% of C++ online submissions for Swim in Rising Water.
> 
> Memory Usage: 752.5 MB, less than 5.26% of C++ online submissions for Swim in Rising Water.

```cpp
class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    dirs = vector<vector<int>>{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    helper(grid, 0, 0, grid[0][0], dp);
    return dp[n - 1][n - 1];
  }

 private:
  vector<vector<int>> dirs;
  void helper(vector<vector<int>>& grid, int row, int col, int cur, vector<vector<int>>& dp) {
    int n = grid.size();
    if (row < 0 || row >= n || col < 0 || col >= n || max(cur, grid[row][col]) >= dp[row][col]) return;
    dp[row][col] = max(cur, grid[row][col]);

    // Deal with four directions
    for (auto dir : dirs) helper(grid, row + dir[0], col + dir[1], dp[row][col], dp);
  }
};
```

## Solution 4: Dijkstra’s Algorithm

Time complexity: O(n^2*logn), Space complexity: O(n^2)

```cpp
class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    const int n = grid.size();
    priority_queue<pair<int, int>> q; // {-time, y * N + x}
    q.push({-grid[0][0], 0 * n + 0});
    vector<int> seen(n * n);
    vector<int> dirs{-1, 0, 1, 0, -1};
    seen[0 * n + 0] = 1;
    while (!q.empty()) {
      auto node = q.top(); q.pop();
      int t = -node.first;
      int x = node.second % n;
      int y = node.second / n;      
      if (x == n - 1 && y == n - 1) return t;
      for (int i = 0; i < 4; ++i) {
        int tx = x + dirs[i];
        int ty = y + dirs[i + 1];
        if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
        if (seen[ty * n + tx]) continue;
        seen[ty * n + tx] = 1;
        q.push({-max(t, grid[ty][tx]), ty * n + tx});
      }
    }
    return -1;
  }
};
```