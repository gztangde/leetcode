---
title: Leetcode 230. Kth Smallest Element in a BST
date: 2019-01-13 12:46:43
updated: 2019-01-13 12:46:43
categories: 
- [Leetcode]
- [Leetcode,Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary search tree, write a function  `kthSmallest`  to find the  **k**th smallest element in it.

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

![](/images/in-post/2019-01-13-Leetcode-230-Kth-Smallest-Element-in-a-BST/2019-01-13-12-47-38.png)

**Follow up:**  
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

**Difficulty**:Medium
**Category**:

<!-- more -->

------------

# Analyze

------------

# Solution

## Solution 1: Inorder Traversal

```cpp
// Runtime: 12ms
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while (p || !s.empty()) {
      if (p) {
        s.push(p);
        p = p->left;
      } else {
        TreeNode* t = s.top();
        s.pop();
        if (--k == 0) return t->val;
        p = t->right;
      }
    }
    return 0;
  }
};
```

We also can change the Inorder function like the second way.

## Solution 2: The other Inorder traversal was

```cpp
// Runtime: 12ms
class Solution {
 public:
  int kthSmallest(TreeNode* root, int k) {
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while (p) {
      s.push(p);
      p = p->left;
    }
    while (!s.empty()) {
      TreeNode* t = s.top();
      s.pop();
      if (--k == 0) return t->val;
      t = t->right;
      while (t) {
        s.push(t);
        t = t->left;
      }
    }
    return 0;
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
