---
title: Leetcode 572. Subtree of Another Tree
date: 2019-01-14 13:03:02
updated: 2019-01-14 13:03:02
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given two non-empty binary trees  **s**  and  **t**, check whether tree  **t**  has exactly the same structure and node values with a subtree of  **s**. A subtree of  **s**  is a tree consists of a node in  **s**  and all of this node's descendants. The tree  **s**  could also be considered as a subtree of itself.

**Example 1:**  
Given tree s:

```
     3
    / \
   4   5
  / \
 1   2
```

Given tree t:

```
   4 
  / \
 1   2

```

Return **true**, because t has the same structure and node values with a subtree of s.

**Example 2:**  
Given tree s:

```
     3
    / \
   4   5
  / \
 1   2
    /
   0
```

Given tree t:

```
   4
  / \
 1   2
```

Return **false**.

**Difficulty**:Easy
**Category**:Tree

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// Runtime: 24ms
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s) return false;
    bool p = isSubtreeRoot(s, t);
    bool l = isSubtree(s->left, t);
    bool r = isSubtree(s->right, t);
    return p || l || r;
  }

 private:
  bool isSubtreeRoot(TreeNode* s, TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val != t->val) return false;
    bool l = isSubtreeRoot(s->left, t->left);
    bool r = isSubtreeRoot(s->right, t->right);
    return l && r;
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
