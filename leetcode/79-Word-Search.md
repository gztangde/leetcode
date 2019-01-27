
# Question

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

![](/images/in-post/2019-01-11-Leetcode-79-Word-Search/2019-01-11-10-15-35.png)

**Difficulty**:Medium
**Category**: Array, Backtracking


------------

# Analyze

This problem have these features:

- Begin with each element and try to find the whole words begin with it.
- For the wordsearch recursion function, deal with the constraint function firstly. After that, call this function for its' up, down, left and right element in order to find the next element.

**Constraint Condition:**

- If board is empty, then the function return false;
- If the wordsearch function doesn't find the word in the board, then return fasle.

------------

# Solution

```cpp
// Solution: Recursion
// runtime: 32ms
class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty()) return false;
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (wordsearch(board, word, 0, i, j) ) return true;
      }
    }
    return false;
  }

 private:
  bool wordsearch(vector<vector<char>>& b, string& w, int d, int x, int y) { 
    if (x < 0 || y < 0 || x == b.size() || y == b[0].size() || w[d] != b[x][y])
      return false;
    if (d == w.length() - 1) return true;
    char cur = b[x][y];
    b[x][y] = 0;
    bool res = wordsearch(b, w, d + 1, x + 1, y) 
              || wordsearch(b, w, d + 1, x, y + 1) 
              || wordsearch(b, w, d + 1, x - 1, y) 
              || wordsearch(b, w, d + 1, x, y - 1);
    b[x][y] = cur;
    return res;
  }
};
```