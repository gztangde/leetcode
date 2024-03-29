---
title: Leetcode 671. Second Minimum Node In a Binary Tree
date: 2019-01-14 15:24:16
updated: 2019-01-14 15:24:16
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question


Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly  `two`  or  `zero`  sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the  **second minimum**  value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

**Example 1:**  

**Input:**

```
    2
   / \
  2   5
     / \
    5   7

```

**Output:** 5
**Explanation:** The smallest value is 2, the second smallest value is 5.

**Example 2:**  

**Input:**

```
    2
   / \
  2   2

```

**Output:** -1
**Explanation:** The smallest value is 2, but there isn't any second smallest value.

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

# Analyze

# Solution

```cpp
// Runtime: 0ms
class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    // If there is a leaf, and don't have other node.
    if (!root || (!root->left && !root->right)) return -1;

    int l = root->left->val, r = root->right->val;
    if (l == root->val) l = findSecondMinimumValue(root->left);
    if (r == root->val) r = findSecondMinimumValue(root->right);

    if (l != -1 && r != -1) return min(l, r);
    return l != -1 ? l : r;
  }
};
```


