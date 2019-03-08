---
title: Leetcode 114. Flatten Binary Tree to Linked List
date: 2018-11-26 19:09:31
updated: 2018-11-26 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree, flatten it to a linked list in-place.

![](/images/in-post/2018-11-26-Leetcode-114-Flatten-Binary-Tree-To-Linked-List/2018-11-26-18-30-40.png)

**Difficulty**:Medium

**Category**:Tree, Depth-first-Search

<!-- more -->

------------

# Solution

思路是先利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。

```cpp
class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root) return;
    if (root->left) flatten(root->left);
    if (root->right) flatten(root->right);
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right) root = root->right;
    root->right = temp;
  }
};
```