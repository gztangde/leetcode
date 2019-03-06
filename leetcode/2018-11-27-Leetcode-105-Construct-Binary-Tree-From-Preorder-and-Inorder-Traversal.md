---
title: Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal
date: 2018-11-27 09:09:31
updated: 2018-11-27 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given preorder and inorder traversal of a tree, construct the binary tree.

![](/images/in-post/leetcode/2018-11-27-13-44-09.png)

**Difficulty**:Medium

**Category**:Tree, Array, Depth-first-Search

<!-- more -->

------------

# Analyze

题目给定了`先序`和`中序`，并且里面的元素不重复，可以得到这样几个条件：

- 先序的第一个元素一定是跟
- 可以更加先序里面的根节点到中序里面找到对应的节点，因为没有重复元素
- 根据中序里面找到的根节点可以将其分为左右两个部分，分别对左右两个部分递归调用原函数

![](/images/in-post/leetcode/2018-11-27-15-47-36.png)

图片来自于:[Construct a Binary Tree from Given Inorder and Depth-First-Search](https://algorithms.tutorialhorizon.com/construct-a-binary-tree-from-given-inorder-and-depth-first-search/) 

# Solution

参考博客：[Construct Binary Tree from Preorder and Inorder Traversal 由先序和中序遍历建立二叉树](http://www.cnblogs.com/grandyang/p/4296500.html)

**Solution 1:**递归方案

```cpp
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }

  TreeNode* buildTree(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) return nullptr;

    // Get the root value for each subtree
    TreeNode* root = new TreeNode(preorder[pLeft]);

    // Move the i to the root->val in the inorder array
    int i = iLeft;
    for (; i <= iRight; ++i) {
      if (preorder[pLeft] == inorder[i]) break;
    }

    // Left of the root in the precorder: pLeft+1, pLeft + (i - iLeft)
    // Right of the root in the preorder: pLeft+(i - iLeft) + 1, pRight
    root->left = buildTree(preorder, pLeft + 1, pLeft + (i - iLeft), inorder, iLeft, i - 1);
    root->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
    return root;
  }
};
```
