---
title: Leetcode 538. Convert BST to Greater Tree
date: 2019-01-13 19:23:53
updated: 2019-01-13 19:23:53
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

![](/images/in-post/2019-01-13-Leetcode-538-Convert-BST-to-Greater-Tree/2019-01-13-19-24-27.png)

**Difficulty**:Easy
**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// Runtime: 32ms
class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    dfs(root, sum);
    return root;
  }

 private:
  void dfs(TreeNode* root, int& sum) {
    if (!root) return;
    dfs(root->right, sum);
    sum += root->val;
    root->val = sum;
    dfs(root->left, sum);
  }
};
```


