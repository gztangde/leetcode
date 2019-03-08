---
title: Leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal
date: 2018-11-26 21:09:31
updated: 2018-11-26 21:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given inorder and postorder traversal of a tree, construct the binary tree.

![](/images/in-post/2018-11-26-Leetcode-106-Construct-Binary-Tree-From-Inorder-And-Postorder-Traversal/2018-11-26-21-29-15.png)

**Difficulty**:Medium

**Category**:Tree, Array, Depth-first-Search

<!-- more -->

------------

# Analyze

题目给定了`后序`和`中序`，并且里面的元素不重复，可以得到这样几个条件：

- 后序的最后一个元素一定是跟节点
- 可以在后序里面的根节点到中序里面找到对应的节点，因为没有重复元素
- 根据中序里面找到的根节点可以将其分为左右两个部分，分别对左右两个部分递归调用原函数

![](/images/in-post/2018-11-26-Leetcode-106-Construct-Binary-Tree-From-Inorder-And-Postorder-Traversal/2018-11-27-16-01-26.png)

图片来自于:[Construct a Binary Tree from Given Inorder and Depth-First-Search](https://algorithms.tutorialhorizon.com/construct-a-binary-tree-from-given-inorder-and-depth-first-search/) 

------------

# Solution

```cpp
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
  }

  TreeNode* buildTree(vector<int>& postorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) return nullptr;

    TreeNode* root = new TreeNode(postorder[pRight]);

    int i = 0;
    for (i = iLeft; i <= iRight; ++i) {
      if (postorder[pRight] == inorder[i]) break;
    }

    root->left = buildTree(postorder, pLeft, pLeft + (i - iLeft) - 1, inorder, iLeft, i - 1);
    root->right = buildTree(postorder, pLeft + (i - iLeft), pRight - 1, inorder, i + 1, iRight);
    return root;
  }
};
```
