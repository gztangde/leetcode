---
title: Leetcode 110. Balanced Binary Tree
date: 2018-11-26 06:09:31
updated: 2018-11-26 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

> a binary tree in which the depth of the two subtrees of every node never differ by more than 1

![](/images/in-post/2018-11-26-Leetcode-110-Balanced-Binary-tree/2018-11-26-00-45-30.png)

**Difficulty**:Easy

**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isBalanced(TreeNode* root) { return balanceHeight(root) >= 0; }

  int balanceHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = balanceHeight(root->left);
    int right = balanceHeight(root->right);
    if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }
};
```