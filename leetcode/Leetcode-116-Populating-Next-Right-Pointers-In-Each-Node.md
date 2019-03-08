---
title: Leetcode 116. Populating Next Right Pointers in Each Node
date: 2018-11-26 19:09:31
updated: 2018-11-26 19:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a binary tree

```cpp
struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to  `NULL`.

Initially, all next pointers are set to  `NULL`.

**Note:**

- You may only use constant extra space.
- Recursive approach is fine, implicit stack space does not count as extra space for this problem.
- You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

![](/images/in-post/2018-11-26-Leetcode-116-Populating-Next-Right-Pointers-In-Each-Node/2018-11-26-20-24-54.png)

**Difficulty**:Medium

**Category**:Tree, Depth-First-Search

<!-- more -->

------------

# Analyze

方案一：递归 (Solution 1)

这道题目是完全二叉树，所以如果节点的左子节点存在的话，那么右子节点必定存在：

- 如果左子节点存在，那么左节点的`next`指针可以直接指向其右子节点
- 对应右节点，判断其父节点的`next`是否为空，如果不为空，那么就指向父节点`next`指针指向的节点的左子节点，如果为空那么就指向`NULL`.

方案二：迭代 (Solution 2)

# Solution

**Solution 1:**递归的解决方案

```cpp
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    if (root == nullptr) return;
    if (root->left) root->left->next = root->right;
    if (root->right) root->right->next = root->next ? root->next->left : NULL;
    connect(root->left);
    connect(root->right);
  }
};
```

**Solution 2:** 迭代的解决方案

```cpp
class Solution {
 public:
  void connect(TreeLinkNode *root) {
    while (root) {
      TreeLinkNode *next = nullptr, *prev = nullptr;
      // Loop in the same level
      for (; root; root = root->next) {
        // The first one --> to find the next level
        if (!next) next = root->left ? root->left : root->right;

        if (root->left) {
          if (prev) prev->next = root->left;
          prev = root->left;
        }

        if (root->right) {
          if (prev) prev->next = root->right;
          prev = root->right;
        }
      }
      root = next;  // Next Level
    }
  }
};
```