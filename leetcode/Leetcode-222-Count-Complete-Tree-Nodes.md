---
title: Leetcode 222. Count Complete Tree Nodes
date: 2019-01-12 22:26:56
updated: 2019-01-12 22:26:56
categories: 
- [Leetcode]
- [Leetcode, 1_Tree]
- [Leetcode, Binary-Search]
tags: Leetcode
notshow: true
top:
---

# Question

Given a  **complete**  binary tree, count the number of nodes.

**Note:**

**Definition of a complete binary tree from  [Wikipedia](http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees):**  
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h  nodes inclusive at the last level h.

![](/images/in-post/2019-01-12-Leetcode-222-Count-Complete-Tree-Nodes/2019-01-12-22-31-07.png)

**Difficulty**:Medium

**Category**:Tree, Binary-Search

<!-- more -->

# Analyze

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
//Runtime: 16ms
class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;

    int l = countNodes(root->left);
    int r = countNodes(root->right);
    return l + r + 1;
  }
};
```


