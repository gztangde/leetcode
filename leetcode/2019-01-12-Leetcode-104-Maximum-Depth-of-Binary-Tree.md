---
title: Leetcode 104. Maximum Depth of Binary Tree
date: 2019-01-12 16:21:57
updated: 2019-01-12 16:21:57
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
- [Leetcode, 1_Tree, DFS]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Note:** A leaf is a node with no children.

![](/images/in-post/2019-01-12-Leetcode-104-Maximum-Depth-of-Binary-Tree/2019-01-12-16-22-58.png)

**Difficulty**:Easy

**Category**:Tree, Depth-first-Search

<!-- more -->

------------

# Analyze

This is a easy question for the tree problem. This question have these feature:

1. One root node question
2. We can use the return value to compare.
  
So we use the template code for the `Tree Question`.

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-13-28.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value.
3. recursive call funciton
4. compare ouput value
  
Post: [Tree Question Summary](../Leetcode-Tree-Summary/)

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
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l, r) + 1;
  }
};
```


