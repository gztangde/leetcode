---
title: Leetcode 965. Univalued Binary Tree
date: 2019-01-25 13:14:13
updated: 2019-01-25 13:14:13
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

A binary tree is  _univalued_  if every node in the tree has the same value.

Return  `true` if and only if the given tree is univalued.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_1.png)

**Input:** [1,1,1,1,1,null,1]
**Output:** true

**Example 2:**

![](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_2.png)

**Input:** [2,2,2,5,2]
**Output:** false

**Note:**

1.  The number of nodes in the given tree will be in the range  `[1, 100]`.
2.  Each node's value will be an integer in the range  `[0, 99]`.

**Difficulty**:Easy
**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    if (!root) return true;
    int val = root->val;
    return isUnivalTree(root, val);
  }
  bool isUnivalTree(TreeNode* root, int val) {
    if (!root) return true;
    if (root->val == val) {
      return isUnivalTree(root->left, val) && isUnivalTree(root->right, val);
    } else {
      return false;
    }
  }
};
```


