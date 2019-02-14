---
title: Leetcode 957. Prison Cells After N Days
date: 2019-02-14 01:33:06
updated: 2019-02-14 01:33:06
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question


There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

-   If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
-   Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: `cells[i] == 1`  if the  `i`-th cell is occupied, else  `cells[i] == 0`.

Given the initial state of the prison, return the state of the prison after  `N`  days (and  `N`  such changes described above.)

**Example 1:**

**Input:** cells = [0,1,0,1,1,0,0,1], N = 7
**Output:** [0,0,1,1,0,0,0,0]
**Explanation:** The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

**Example 2:**

**Input:** cells = [1,0,0,1,0,0,1,0], N = 1000000000
**Output:** [0,0,1,1,1,1,1,0]

**Note:**

1.  `cells.length == 8`
2.  `cells[i]`  is in  `{0, 1}`
3.  `1 <= N <= 10^9`

[Discuss](https://leetcode.com/problems/prison-cells-after-n-days/discuss)

**Difficulty**:Medium

**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    N = N % 14;
    if (N == 0) N = 14;
    for (int i = 1; i <= N; ++i) {
      vector<int> temp = cells;
      for (int j = 0; j < temp.size(); ++j) {
        if (j == 0 || j == temp.size() - 1) {
          cells[j] = 0;
          continue;
        } else {
          if (temp[j - 1] == temp[j + 1]) {
            cells[j] = 1;
          } else {
            cells[j] = 0;
          }
        }
      }
      // for (auto cell : cells) {
      //   std::cout << cell << ", ";
      // }
      // std::cout << std::endl;
    }
    return cells;
  }
};
```