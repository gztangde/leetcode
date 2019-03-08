---
title: Leetcode 513. Find Bottom Left Tree Value
date: 2019-01-13 19:08:13
updated: 2019-01-13 19:08:13
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, find the leftmost value in the last row of the tree.

![](/images/in-post/2019-01-13-Leetcode-513-Find-Bottom-Left-Tree-Value/2019-01-13-19-09-07.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search, Breadth-First-Search

<!-- more -->

------------

# Analyze

# Solution

```cpp
// Find the bootton left tree valur(not the left node)
// Runtimes: 12ms
class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int max_row = -1, ans = 0;
    // DFS function
    dfs(root, 0, max_row, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int row, int& max_row, int& ans) {
    if (!root) return;
    dfs(root->left, row + 1, max_row, ans);
    if (row > max_row) {
      ans = root->val;
      max_row = row;
    }
    dfs(root->right, row + 1, max_row, ans);
  }
};
```


