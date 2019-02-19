---
title: Leetcode 37. Sudoku Solver
date: 2019-02-19 16:34:41
updated: 2019-02-19 16:34:41
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy  **all of the following rules**:

1.  Each of the digits `1-9`  must occur exactly once in each row.
2.  Each of the digits `1-9` must occur exactly once in each column.
3.  Each of the the digits `1-9`  must occur exactly once in each of the 9  `3x3`  sub-boxes of the grid.

Empty cells are indicated by the character  `'.'`.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)  
A sudoku puzzle...

![](https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png)  
...and its solution numbers marked in red.

**Note:**

-   The given board contain only digits  `1-9`  and the character  `'.'`.
-   You may assume that the given Sudoku puzzle will have a single unique solution.
-   The given board size is always  `9x9`.

**Difficulty**:Hard

**Category**:Hash-Table, Backtracking

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    rows_ = vector<vector<int>>(9, vector<int>(10));
    cols_ = vector<vector<int>>(9, vector<int>(10));
    boxes_ = vector<vector<int>>(9, vector<int>(10));

    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] != '.') {
          int n = board[r][c] - '0';
          int br = r / 3, bc = c / 3;
          rows_[r][n] = 1;
          cols_[c][n] = 1;
          boxes_[br * 3 + bc][n] = 1;
        }
      }
    }

    fill(board, 0, 0);
  }

 private:
  vector<vector<int>> rows_, cols_, boxes_;

  bool fill(vector<vector<char>>& board, int r, int c) {
    if (r == 9) return true;

    // Get the next element index
    int nc = (c + 1) % 9;
    int nr = nc == 0 ? r + 1 : r;

    if (board[r][c] != '.') return fill(board, nr, nc);

    for (int i = 1; i <= 9; ++i) {
      int br = r / 3, bc = c / 3;
      int box_index = br * 3 + bc;
      if (!rows_[r][i] && !cols_[c][i] && !boxes_[box_index][i]) {
        rows_[r][i] = 1;
        cols_[c][i] = 1;
        boxes_[box_index][i] = 1;
        board[r][c] = i + '0';
        if (fill(board, nr, nc)) return true;
        board[r][c] = '.';
        boxes_[box_index][i] = 0;
        cols_[c][i] = 0;
        rows_[r][i] = 0;
      }
    }
    return false;
  }
};
```