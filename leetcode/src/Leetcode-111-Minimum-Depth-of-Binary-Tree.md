---
title: Leetcode 111. Minimum Depth of Binary Tree
date: 2019-01-12 17:31:34
updated: 2019-01-12 17:31:34
categories: 
- [Leetcode]
- [Leetcode, Easy]
- [Leetcode, 1_Tree]
tags: Leetcode
notshow: true
top:
---

# Question


Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

**Note:** A leaf is a node with no children.

![](/images/in-post/2019-01-12-Leetcode-111-Minimum-Depth-of-Binary-Tree/2019-01-12-17-35-28.png)

**Difficulty**:Easy

**Category**:Tree, Depth-first-Search, Breadth-First-Search

<!-- more -->

# Analyze

## Template 1: One root

![](/images/in-post/2019-01-12-Leetcode-Tree-Summary/2019-01-12-15-13-28.png)

There are four steps for this template:
1. Boundary conditions.
2. Deal with the root value.
3. recursive call funciton
4. compare ouput value

> There is a small mistake in the picture, the last line for this question. Use: min function

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
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if (r == 0) return l + 1;
    if (l == 0) return r + 1;
    return min(l, r) + 1;
  }
};
```
