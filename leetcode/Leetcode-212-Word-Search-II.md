---
title: Leetcode 212. Word Search II
date: 2019-01-11 10:23:38
updated: 2019-01-11 10:23:38
categories: 
- [Leetcode]
- [Leetcode, 3_Backtracking]
- [Leetcode, 1_Tree, Trie]
tags: Leetcode
notshow: true
top:
---

# Question

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

![](/images/in-post/2019-01-11-Leetcode-212-Word-Search-II/2019-01-11-10-26-30.png)

**Difficulty**:Hard

**Category**:Backtracking, Trie

<!-- more -->

------------

# Analyze

This question is similar with the Leetcode 79: Word Search, I reused the `wordsearch` recursion function in that problem and change the loop in the `findWords` to search for each words. As a result, the runtime around `800ms`.

# Solution

<!-- TODO:Change this function to more powerful, the runtime is so long. Consider use the tree in this quesiton -->

```cpp
// Runtime: 780ms
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> rec;
    vector<string> ans;
    if (board.empty()) return {};
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (string& word : words) {
          if (rec.count(word)) continue;
          if (wordsearch(board, word, 0, i, j) ) {
            rec.insert(word);
            ans.emplace_back(word);
          }
        }
      }
    }
    return ans;
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