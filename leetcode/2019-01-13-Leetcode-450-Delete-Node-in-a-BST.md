---
title: Leetcode 450. Delete Node in a BST
date: 2019-01-13 16:45:20
updated: 2019-01-13 16:45:20
categories: 
- [Leetcode]
- [Leetcode, Tree]
tags: Leetcode
notshow: true
top:
---

# Question

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

1. Search for a node to remove.
2. If the node is found, delete the node.

**Note:**  Time complexity should be O(height of tree).

![](/images/in-post/2019-01-13-Leetcode-450-Delete-Node-in-a-BST/2019-01-13-16-46-24.png)

**Difficulty**:Medium
**Category**:Tree

<!-- more -->

------------

# Analyze

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    // If found the element
    if (key == root->val) {
      if (!root->right)
        return root->left;
      else {
        TreeNode* t = root->right;
        while (t->left) t = t->left;
        // Exchange the val for the t node
        // Move the target val to the last leaf
        // So Next time, move it
        swap(root->val, t->val);
      }
    }

    // Recursive call
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
  }
};
```

<!-- 
------------

# Leetcode Question Summary


------------ -->
