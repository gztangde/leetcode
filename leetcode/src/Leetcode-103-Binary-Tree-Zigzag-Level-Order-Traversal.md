---
title: Leetcode 103. Binary Tree Zigzag Level Order Traversal
date: 2018-11-26 06:09:31
updated: 2018-11-26 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

![](/images/in-post/2018-11-26-Leetcode-103-Binary-Tree-Zigzag-Level-Order-Traversal/2018-11-26-00-28-31.png)

**Difficulty**:Medium

**Category**:Tree, Stack, Breadth-first Search

<!-- more -->

# Solution

```cpp

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    traverse(root, 1, res, true);
    return res;
  }

  void traverse(TreeNode const *root, int level, vector<vector<int>> &res,
                bool left_to_right) {
    if (!root) return;

    if (level > res.size()) res.push_back(vector<int>());
    if (left_to_right) {
      res[level - 1].push_back(root->val);
    } else {
      res[level - 1].insert(res[level - 1].begin(), root->val);
    }
    traverse(root->left, level + 1, res, !left_to_right);
    traverse(root->right, level + 1, res, !left_to_right);
  }
};
```