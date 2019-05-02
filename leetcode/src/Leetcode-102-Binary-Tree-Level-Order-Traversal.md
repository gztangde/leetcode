---
title: Leetcode 102. Binary Tree Level Order Traversal
date: 2018-11-26 06:09:31
updated: 2018-11-26 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

![](/images/in-post/leetcode/2018-11-26-00-10-57.png)

**Difficulty**:Medium

**Category**:Tree, Breadith-first Search

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    traverse(root, 1, res);
    return res;
  }
  void traverse(TreeNode const *root, int level, vector<vector<int>> &res) {
    if (!root) return;
    if (level > res.size()) res.push_back(vector<int>());
    res[level - 1].push_back(root->val);
    traverse(root->left, level + 1, res);
    traverse(root->right, level + 1, res);
  }
};
```
