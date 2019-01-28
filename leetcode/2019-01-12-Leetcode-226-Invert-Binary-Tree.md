---
title: Leetcode 226. Invert Binary Tree
date: 2019-01-12 22:51:32
updated: 2019-01-12 22:51:32
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Invert a binary tree.

![](/images/in-post/2019-01-12-Leetcode-226-Invert-Binary-Tree/2019-01-12-22-53-14.png)


**Trivia:**  
This problem was inspired by  [this original tweet](https://twitter.com/mxcl/status/608682016205344768)  by  [Max Howell](https://twitter.com/mxcl):

> Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.

**Difficulty**:Medium
**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

```


