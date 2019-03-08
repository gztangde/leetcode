---
title: Leetcode 404. Sum of Left Leaves
date: 2019-01-13 13:52:08
updated: 2019-01-13 13:52:08
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Find the sum of all left leaves in a given binary tree.

![](/images/in-post/2019-01-13-Leetcode-404-Sum-of-Left-Leaves/2019-01-13-13-52-50.png)

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// Runtimes: 4ms
class Solution {
 public:
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    int l = sumOfLeftLeaves(root->left);
    int r = sumOfLeftLeaves(root->right);
    return l + r;
  }
};
```


