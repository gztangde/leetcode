---
title: Leetcode 174. Dungeon Game
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 174. Dungeon Game

The demons had captured the princess (**P**) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (**K**) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (_negative_  integers) upon entering these rooms; other rooms are either empty (_0's_) or contain magic orbs that increase the knight's health (_positive_  integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

**Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.**

For example, given the dungeon below, the initial health of the knight must be at least  **7**  if he follows the optimal path  `RIGHT-> RIGHT -> DOWN -> DOWN`.

![](/images/in-post/2019-01-07-Leetcode-174-Dungeon-Game/2019-01-07-16-27-50.png)

**Note:**

- The knight's health has no upper bound.
- Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

**Difficulty**:Hard

**Category**:Binary-Search, Dynamic-Programming

<!-- more -->

# Solution

## Solutions 1: DP

![](/images/in-post/2019-01-07-Leetcode-174-Dungeon-Game/2019-01-07-17-07-20.png)

Time complexity: O(mn), Space complexity: O(mn) -> O(n)

**Space complexity: O(mn)**
  
```cpp
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    const int m = dungeon.size();
    const int n = dungeon[0].size();

    // hp[y][x]: min hp required to reach bottom right (P).
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n - 1] = hp[m - 1][n] = 1;

    for (int y = m - 1; y >= 0; --y)
      for (int x = n - 1; x >= 0; --x) hp[y][x] = max(1, min(hp[y + 1][x], hp[y][x + 1]) - dungeon[y][x]);

    return hp[0][0];
  }
};
```

**Space complexity: O(n)**

```cpp
class Solution {
 public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    const vector<vector<int>>& d = dungeon;
    const int m = d.size();
    const int n = d[0].size();

    // hp[x][y] is the lowest hp required to reach the P position
    vector<vector<int>> hp(m + 1, vector<int>(n + 1, INT_MAX));
    hp[m][n - 1] = hp[m - 1][n] = 1;

    for (int x = m - 1; x >= 0; --x) {
      for (int y = n - 1; y >= 0; --y) {
        // the hp must bigger than 1
        hp[x][y] = max(1, min(hp[x + 1][y], hp[x][y + 1]) - d[x][y]);
      }
    }
    return hp[0][0];
  }
};
```

## Solution 2: Binary Search