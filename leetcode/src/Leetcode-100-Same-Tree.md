---
title: Leetcode 100. Same Tree
date: 2018-11-26 06:09:31
updated: 2018-11-26 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

![](/images/in-post/2018-11-26-Leetcode-100-Same-Tree/2018-11-26-00-40-18.png)

**Difficulty**:Easy

**Category**:Tree, Depth-first-Search

# Solution

## Solution 1: Recursion

Time complexity: O(n)
Space complexity: O(n)

```cpp
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
```

# Follow up

如何判断其中一个树是另外一个树的 `subtree`

* [LeetCode 572. Subtree of Another Tree](./2019-01-14-Leetcode-572-Subtree-of-Another-Tree/)

**Solution: Recursion**

Time complexity: O(max(n, m))
Space complexity: O(max(n, m))

```cpp
class Solution {
public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (t == nullptr) return true;
    if (s == nullptr) return false;
    if (isSameTree(s, t)) return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }
private:
  bool isSameTree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) return true;
    if (s == nullptr || t == nullptr) return false;
    return (s->val == t->val)
           && isSameTree(s->left, t->left) 
           && isSameTree(s->right, t->right);
  }
};
```