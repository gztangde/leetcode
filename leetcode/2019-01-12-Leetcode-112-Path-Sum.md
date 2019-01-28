---
title: Leetcode 112. Path Sum
date: 2019-01-12 18:22:06
updated: 2019-01-12 18:22:06
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

**Note:** A leaf is a node with no children.

![](/images/in-post/2019-01-12-Leetcode-112-Path-Sum/2019-01-12-18-23-19.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze


So we use the template code for this `Tree Question`.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-13-28.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value.
3. recursive call funciton
4. compare ouput value

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
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root) return false;
    if (!root->left && !root->right) return root->val == sum;
    bool l = hasPathSum(root->left, sum - root->val);
    bool r = hasPathSum(root->right, sum - root->val);
    return l || r;
  }
};
```


