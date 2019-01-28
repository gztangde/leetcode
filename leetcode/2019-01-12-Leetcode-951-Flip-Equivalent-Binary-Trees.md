---
title: Leetcode 951. Flip Equivalent Binary Trees
date: 2019-01-12 20:05:15
updated: 2019-01-12 20:05:15
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
tags: Leetcode
notshow: true
top:
---

# Question

For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is  _flip equivalent_  to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are  _flip equivalent_. The trees are given by root nodes  `root1`  and  `root2`.

![](/images/in-post/2019-01-12-Leetcode-951-Flip-Equivalent-Binary-Trees/2019-01-12-20-06-17.png)

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
// Runtime: 4ms
class Solution {
 public:
  bool flipEquiv(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;
    bool l1 = flipEquiv(root1->left, root2->right);
    bool l2 = flipEquiv(root1->left, root2->left);
    bool r1 = flipEquiv(root1->right, root2->left);
    bool r2 = flipEquiv(root1->right, root2->right);

    return root1->val == root2->val && (l1 && r1) || (l2 && r2);
  }
};
```


