---
title: Leetcode 617. Merge Two Binary Trees
date: 2019-01-13 20:01:54
updated: 2019-01-13 20:01:54
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

![](/images/in-post/2019-01-13-Leetcode-617-Merge-Two-Binary-Trees/2019-01-13-20-05-05.png)

**Note:** The merging process must start from the root nodes of both trees.

**Difficulty**:Easy

**Category**:Tree

<!-- more -->

------------

# Analyze

# Solution

```cpp
//Runtime: 36ms
class Solution {
 public:
  TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return nullptr;
    if (!t1 || !t2) {
      if (!t1) t1 = t2;
      return t1;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
  }
};
```


