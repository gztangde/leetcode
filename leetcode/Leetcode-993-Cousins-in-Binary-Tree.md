---
title: Leetcode 993. Cousins in Binary Tree
date: 2019-02-16 23:15:36
updated: 2019-02-16 23:15:36
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

In a binary tree, the root node is at depth  `0`, and children of each depth  `k`  node are at depth  `k+1`.

Two nodes of a binary tree are  _cousins_  if they have the same depth, but have  **different parents**.

We are given the  `root`  of a binary tree with unique values, and the values  `x` and  `y` of two different nodes in the tree.

Return `true` if and only if the nodes corresponding to the values  `x`  and  `y`  are cousins.

**Example 1:  
![](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)**

**Input:** root = [1,2,3,4], x = 4, y = 3
**Output:** false

**Example 2:  
![](https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png)**

**Input:** root = [1,2,3,null,4,null,5], x = 5, y = 4
**Output:** true

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png)**

**Input:** root = [1,2,3,null,4], x = 2, y = 3
**Output:** false

**Note:**

1.  The number of nodes in the tree will be between  `2`  and  `100`.
2.  Each node has a unique integer value from  `1`  to  `100`.

**Difficulty**:Easy

**Category**:

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  bool isCousins(TreeNode* root, int x, int y) {
    if ((level(root, x, 1) == level(root, y, 1)) && !(isSibling(root, x, y))) return true;
    return false;
  }

 private:
  bool isSibling(TreeNode* root, int a, int b) {
    if (!root) return false;
    if (root->left && root->right) {
      if ((root->left->val == a && root->right->val == b) || (root->right->val == a && root->left->val == b)) {
        return true;
      }
    }
    return isSibling(root->left, a, b) || isSibling(root->right, a, b);
  }

  int level(TreeNode* root, int target, int lev) {
    if (!root) return 0;
    if (root->val == target) return lev;

    int l = level(root->left, target, lev + 1);
    if (l != 0) return l;
    return level(root->right, target, lev + 1);
  }
};
```