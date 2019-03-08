---
title: Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
date: 2019-01-13 01:20:30
updated: 2019-01-13 01:20:30
categories: 
- [Leetcode]
- [Leetcode, Tree]
- [Leetcode, Easy]
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the  [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow  **a node to be a descendant of itself**).”

Given binary search tree: root = [6,2,8,0,4,7,9,null,null,3,5]

![](/images/in-post/2019-01-13-Leetcode-235-Lowest-Common-Ancestor-of-a-Binary-Search-Tree/2019-01-13-01-22-08.png)

**Example 1:**

> **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
> **Output:** 6
> **Explanation:** The LCA of nodes `2` and `8` is `6`.

**Example 2:**

> **Input:** root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
> **Output:** 2
> **Explanation:** The LCA of nodes `2` and `4` is `2`, since a node can be a descendant of itself according to the LCA definition.

**Note:**

- All of the nodes' values will be unique.
- p and q are different and both values will exist in the BST.

**Difficulty**:Easy

**Category**:

<!-- more -->

------------

# Analyze

# Solution

<!-- TODO:You don't need to deal with the values. You can only use the point to make decision. -->

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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
    if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};
```

**Solution 2**: Leetcode 236

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
//Runtime: 24ms
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if (l && r) return root;
    return l ? l : r;
  }
};
```


